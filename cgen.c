/****************************************************/
/* The code generator implementation                */
/* for the C- compiler                              */
/* Gabriela Carregari Verza                         */
/*                                                  */
/* Adapted from                                     */
/* File: cgen.c                                     */
/* The code generator implementation                */
/* for the TINY compiler                            */
/* (generates code for the TM machine)              */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "symtab.h"
#include "cgen.h"
#include "code.h"
#define MAX_ARGS 4

static int temp = 0;
static int label = 0;
static int nextSibling = 1;
static int labelScope = 0;

char temp1[20];
char temp2[20];
char temp3[20];
char temp4[20];

int analyzeNode(TreeNode *no);
int analyzeNodeCall(TreeNode *no);

int returnLabel() {
   return label;
}

static int generateStmt(TreeNode *no) {
   int ret, op, base, pos, aux, cont, param, startWhile, finishWhile;

   char *name;
   TreeNode *brother;

   switch (no->kind.stmt) {
   case WhileK:
      startWhile = label;

      emitLabel(startWhile);

      label++;

      finishWhile = label;

      label++;

      op = analyzeNode(no->child[0]); // check opposite condition

      sprintf(temp1, "IF");
      sprintf(temp2, "$t%d", op);
      sprintf(temp3, "L%d", finishWhile);
      sprintf(temp4, "-");
      emitInstruction(temp1, temp2, temp3, temp4);

      ret = analyzeNode(no->child[1]); // for while's content

      sprintf(temp1, "GOTO");
      sprintf(temp2, "L%d", startWhile);
      sprintf(temp3, "-");
      sprintf(temp4, "-");
      emitInstruction(temp1, temp2, temp3, temp4);

      emitLabel(finishWhile);
      break;

   case AssignK:
      base = analyzeNode(no->child[1]);

      if (no->child[0]->child[0] != NULL) { // check if its vector
         if (strcmp(search_data_id_param_vect(no->child[0]->attr.name, no->child[0]->attr.scope, 3), "yes") == 0) {
            sprintf(temp1, "LOAD");
            sprintf(temp2, "$t%d", temp++);
            sprintf(temp3, "%s", no->child[0]->attr.name);
            sprintf(temp4, "-");
            emitInstruction(temp1, temp2, temp3, temp4);

            pos = analyzeNode(no->child[0]->child[0]);

            sprintf(temp1, "PLUS");
            sprintf(temp2, "$t%d", temp--);
            sprintf(temp3, "$t%d", pos);
            sprintf(temp4, "$t%d", temp);
            emitInstruction(temp1, temp2, temp3, temp4);

            sprintf(temp1, "ASSIGN");
            sprintf(temp2, "$t%d", base);
            sprintf(temp3, "0");
            sprintf(temp4, "$t%d", temp);
            emitInstruction(temp1, temp2, temp3, temp4);
         }
         else {
            pos = analyzeNode(no->child[0]->child[0]);

            sprintf(temp1, "ASSIGN");
            sprintf(temp2, "$t%d", base);
            sprintf(temp3, "%s", no->child[0]->attr.name);
            sprintf(temp4, "$t%d", pos);
            emitInstruction(temp1, temp2, temp3, temp4);
         }
      }
      else {
         sprintf(temp1, "ASSIGN");
         sprintf(temp2, "$t%d", base);
         sprintf(temp3, "%s", no->child[0]->attr.name);
         sprintf(temp4, "-");
         emitInstruction(temp1, temp2, temp3, temp4);
      }

      temp = 0;
      break;

   case IfK:
      ret = analyzeNode(no->child[0]);

      sprintf(temp1, "IF");
      sprintf(temp2, "$t%d", ret);
      sprintf(temp3, "L%d", label);
      sprintf(temp4, "-");
      emitInstruction(temp1, temp2, temp3, temp4);

      analyzeNode(no->child[1]); // enters if

      sprintf(temp1, "GOTO");
      sprintf(temp2, "L%d", label + 1);
      sprintf(temp3, "-");
      sprintf(temp4, "-");
      emitInstruction(temp1, temp2, temp3, temp4);

      emitLabel(label); // label else
      label++;

      analyzeNode(no->child[2]); // else's content

      // end if/else
      emitLabel(label);
      label++;
      break;

   case VariableK:
      sprintf(temp1, "ALLOC");
      sprintf(temp2, "%s", no->attr.name);
      sprintf(temp3, "%s", no->attr.scope);
      sprintf(temp4, "-");
      emitInstruction(temp1, temp2, temp3, temp4);
      break;

   case VectorK:
      sprintf(temp1, "ALLOC_VECTOR");
      sprintf(temp2, "%s", no->attr.name);
      sprintf(temp3, "%s", no->attr.scope);
      sprintf(temp4, "%d", no->attr.len);
      emitInstruction(temp1, temp2, temp3, temp4);
      return -1;
      break;

   case FunctionK:
      temp = 0;
      switch (no->specifier_type) {
      case IntK:
         sprintf(temp1, "FUNCTION");
         sprintf(temp2, "int");
         sprintf(temp3, "%s", no->attr.name);
         sprintf(temp4, "-");
         emitInstruction(temp1, temp2, temp3, temp4);
         break;

      case VoidK:
         sprintf(temp1, "FUNCTION");
         sprintf(temp2, "void");
         sprintf(temp3, "%s", no->attr.name);
         sprintf(temp4, "-");
         emitInstruction(temp1, temp2, temp3, temp4);
         break;

      default:
         break;
      }

      analyzeNode(no->child[0]); // args

      analyzeNode(no->child[1]); // function's content

      if (strcmp(no->attr.name, "main") == 0) {
         sprintf(temp1, "END_MAIN");
         sprintf(temp2, "%s", no->attr.name);
         sprintf(temp3, "-");
         sprintf(temp4, "-");
         emitInstruction(temp1, temp2, temp3, temp4);
      }
      else {
         sprintf(temp1, "END");
         sprintf(temp2, "%s", no->attr.name);
         sprintf(temp3, "-");
         sprintf(temp4, "-");
         emitInstruction(temp1, temp2, temp3, temp4);
      }

      break;

   case ParameterK:
      switch (no->specifier_type) {
      case IntK:
         sprintf(temp1, "PARAMETER");
         sprintf(temp2, "int");
         sprintf(temp3, "%s", no->attr.name);
         sprintf(temp4, "%s", no->attr.scope);
         emitInstruction(temp1, temp2, temp3, temp4);

         sprintf(temp1, "LOAD");
         sprintf(temp2, "$t%d", temp);
         sprintf(temp3, "%s", no->attr.name);
         sprintf(temp4, "-");
         emitInstruction(temp1, temp2, temp3, temp4);
         temp++;
         break;

      default:
         break;
      }
      break;

   case CallK:
      nextSibling = 0;
      cont = 0;
      name = no->attr.name;

      if (strcmp(no->attr.name, "output") == 0) { 
         if (no->child[0] != NULL) {
            param = analyzeNodeCall(no->child[0]);

            sprintf(temp1, "CALL_OUT");
            sprintf(temp2, "$t%d", param);
            sprintf(temp3, "%s", no->attr.name);
            sprintf(temp4, "-");
            emitInstruction(temp1, temp2, temp3, temp4);

            nextSibling = 1;
         }
      }
      else if (strcmp(no->attr.name, "input") == 0) {
         sprintf(temp1, "CALL_IN");
         sprintf(temp2, "$t%d", temp);
         sprintf(temp3, "%s", no->attr.name);
         sprintf(temp4, "-");
         emitInstruction(temp1, temp2, temp3, temp4);

         nextSibling = 1;
      }
      else {
         if (no->child[0] != NULL) {
            // stack up return adress ($ra)
            sprintf(temp1, "LOAD_CONST");
            sprintf(temp2, "$t%d", temp);
            sprintf(temp3, "PC");
            sprintf(temp4, "-");
            emitInstruction(temp1, temp2, temp3, temp4);

            sprintf(temp1, "ASSIGN");
            sprintf(temp2, "$t%d", temp++);
            sprintf(temp3, "0");
            sprintf(temp4, "$sp");
            emitInstruction(temp1, temp2, temp3, temp4);

            sprintf(temp1, "LOAD_CONST");
            sprintf(temp2, "$t%d", temp);
            sprintf(temp3, "1");
            sprintf(temp4, "-");
            emitInstruction(temp1, temp2, temp3, temp4);

            sprintf(temp1, "PLUS");
            sprintf(temp2, "$sp");
            sprintf(temp3, "$t%d", temp++);
            sprintf(temp4, "$sp");
            emitInstruction(temp1, temp2, temp3, temp4);

            param = analyzeNodeCall(no->child[0]);

            sprintf(temp1, "ARGUMENT");
            sprintf(temp2, "$t%d", param);
            sprintf(temp3, "-");
            sprintf(temp4, "-");
            emitInstruction(temp1, temp2, temp3, temp4);

            cont++;
            brother = no->child[0]->sibling;
            while (brother != NULL) {
               param = analyzeNodeCall(brother);

               sprintf(temp1, "ARGUMENT");
               sprintf(temp2, "$t%d", param);
               sprintf(temp3, "-");
               sprintf(temp4, "-");
               emitInstruction(temp1, temp2, temp3, temp4);

               cont++;
               brother = brother->sibling;
            }
         }

         sprintf(temp1, "CALL");
         sprintf(temp2, "$t%d", temp);
         sprintf(temp3, "%s", name);
         sprintf(temp4, "%d", cont);
         emitInstruction(temp1, temp2, temp3, temp4);

         nextSibling = 1;

         sprintf(temp1, "PLUS");
         sprintf(temp2, "$v0");
         sprintf(temp3, "-");
         sprintf(temp4, "$t%d", temp);
         emitInstruction(temp1, temp2, temp3, temp4);
      }

      return temp++;

      break;

   case ReturnK:
      ret = analyzeNode(no->child[0]);

      temp--;

      sprintf(temp1, "PLUS");
      sprintf(temp2, "$t%d", temp);
      sprintf(temp3, "-");
      sprintf(temp4, "$v0");
      emitInstruction(temp1, temp2, temp3, temp4);

      temp++;

      sprintf(temp1, "LOAD_CONST");
      sprintf(temp2, "$t%d", temp);
      sprintf(temp3, "1");
      sprintf(temp4, "-");
      emitInstruction(temp1, temp2, temp3, temp4);

      sprintf(temp1, "MINUS");
      sprintf(temp2, "$sp");
      sprintf(temp3, "$t%d", temp++);
      sprintf(temp4, "$sp");
      emitInstruction(temp1, temp2, temp3, temp4);

      sprintf(temp1, "LOAD");
      sprintf(temp2, "$ra");
      sprintf(temp3, "0");
      sprintf(temp4, "$sp");
      emitInstruction(temp1, temp2, temp3, temp4);

      sprintf(temp1, "RETURN");
      sprintf(temp2, "$v0");
      sprintf(temp3, "-");
      sprintf(temp4, "-");
      emitInstruction(temp1, temp2, temp3, temp4);

      temp = 0;
      break;

   default:
      break;
   }
}

static int generateExp(TreeNode *no) {
   int aux1, aux2;
   int param1, param2;

   switch (no->kind.exp) {

   case OpK:
      param1 = analyzeNode(no->child[0]);
      param2 = analyzeNode(no->child[1]);

      switch (no->attr.op) {
      case PLUS:
         sprintf(temp2, "$t%d", param1);
         sprintf(temp3, "$t%d", param2);
         sprintf(temp4, "$t%d", temp);
         emitInstruction("PLUS", temp2, temp3, temp4);
         break;

      case MINUS:
         sprintf(temp2, "$t%d", param1);
         sprintf(temp3, "$t%d", param2);
         sprintf(temp4, "$t%d", temp);
         emitInstruction("MINUS", temp2, temp3, temp4);
         break;

      case TIMES:
         sprintf(temp2, "$t%d", param1);
         sprintf(temp3, "$t%d", param2);
         sprintf(temp4, "$t%d", temp);
         emitInstruction("TIMES", temp2, temp3, temp4);
         break;

      case OVER:
         sprintf(temp2, "$t%d", param1);
         sprintf(temp3, "$t%d", param2);
         sprintf(temp4, "$t%d", temp);
         emitInstruction("OVER", temp2, temp3, temp4);
         break;

      case EQ:
         sprintf(temp2, "$t%d", param1);
         sprintf(temp3, "$t%d", param2);
         sprintf(temp4, "$t%d", temp);
         emitInstruction("NEQ", temp2, temp3, temp4);
         break;

      case NEQ:
         sprintf(temp2, "$t%d", param1);
         sprintf(temp3, "$t%d", param2);
         sprintf(temp4, "$t%d", temp);
         emitInstruction("EQ", temp2, temp3, temp4);
         break;

      case LT:
         sprintf(temp2, "$t%d", param1);
         sprintf(temp3, "$t%d", param2);
         sprintf(temp4, "$t%d", temp);
         emitInstruction("GTE", temp2, temp3, temp4);
         break;

      case GT:
         sprintf(temp2, "$t%d", param1);
         sprintf(temp3, "$t%d", param2);
         sprintf(temp4, "$t%d", temp);
         emitInstruction("LTE", temp2, temp3, temp4);
         break;

      case LTE:
         sprintf(temp2, "$t%d", param1);
         sprintf(temp3, "$t%d", param2);
         sprintf(temp4, "$t%d", temp);
         emitInstruction("GT", temp2, temp3, temp4);
         break;

      case GTE:
         sprintf(temp2, "$t%d", param1);
         sprintf(temp3, "$t%d", param2);
         sprintf(temp4, "$t%d", temp);
         emitInstruction("LT", temp2, temp3, temp4);
         break;

      default:
         break;
      }
      return temp++;

      break;

   case ConstK:
      sprintf(temp1, "LOAD_CONST");
      sprintf(temp2, "$t%d", temp);
      sprintf(temp3, "%d", no->attr.val);
      sprintf(temp4, "-");
      emitInstruction(temp1, temp2, temp3, temp4);
      return temp++;
      break;

   case IdK:
      // load vector args
      if (strcmp(search_data_id_param_vect(no->attr.name, "global", 4), "yes") == 0 || strcmp(search_data_id_param_vect(no->attr.name, no->attr.scope, 4), "yes") == 0) {
         sprintf(temp1, "LOAD_VARG");
         sprintf(temp2, "$t%d", temp);
         sprintf(temp3, "%s", no->attr.name);
         sprintf(temp4, "-");
         emitInstruction(temp1, temp2, temp3, temp4);
      }
      else {
         sprintf(temp1, "LOAD");
         sprintf(temp2, "$t%d", temp);
         sprintf(temp3, "%s", no->attr.name);
         sprintf(temp4, "-");
         emitInstruction(temp1, temp2, temp3, temp4);
      }
      return temp++;
      break;

   case VectorK:
      aux1 = analyzeNode(no->child[0]); // save vector index

      if (strcmp(search_data_id_param_vect(no->attr.name, no->attr.scope, 3), "yes") == 0) {
         aux2 = temp;
         sprintf(temp1, "LOAD");
         sprintf(temp2, "$t%d", temp++);
         sprintf(temp3, "%s", no->attr.name);
         sprintf(temp4, "-");
         emitInstruction(temp1, temp2, temp3, temp4);

         sprintf(temp1, "PLUS");
         sprintf(temp2, "$t%d", aux1);
         sprintf(temp3, "$t%d", aux2);
         sprintf(temp4, "$t%d", temp++);
         emitInstruction(temp1, temp2, temp3, temp4);

         sprintf(temp1, "LOAD");
         sprintf(temp2, "$t%d", temp);
         sprintf(temp3, "0");
         sprintf(temp4, "$t%d", temp - 1);
         emitInstruction(temp1, temp2, temp3, temp4);
      }
      else {
         temp++;
         sprintf(temp1, "LOAD_VECTOR");
         sprintf(temp2, "$t%d", temp++);
         sprintf(temp3, "%s", no->attr.name);
         sprintf(temp4, "$t%d", aux1);
         emitInstruction(temp1, temp2, temp3, temp4);
         temp--;
      }
      return temp--; // all 
      break;

   case TypeK:
      analyzeNode(no->child[0]);
      break;

   default:
      break;
   }
}

int analyzeNode(TreeNode *no) {
   int auxTemp = -1;
   if (no != NULL) {

      switch (no->nodekind) {

      case StmtK:
         auxTemp = generateStmt(no);
         break;

      case ExpK:
         auxTemp = generateExp(no);
         break;

      default:
         break;
      }

      // check if analysis continue for sibling node 
      if (no->sibling != NULL && nextSibling == 1)
         auxTemp = analyzeNode(no->sibling);
   }

   return auxTemp;
}

int analyzeNodeCall(TreeNode *no) {
   int auxTemp = -1;

   if (no != NULL) {

      switch (no->nodekind) {

      case StmtK:
         auxTemp = generateStmt(no);
         break;

      case ExpK:
         if (no->attr.op == VectK) {
            if (no->child[0] == NULL) {
               if (strcmp(search_data_id_param_vect(no->attr.name, "global", 3), "no") == 0 ||
                   strcmp(search_data_id_param_vect(no->attr.name, no->attr.scope, 3), "no") == 0) {
                  sprintf(temp1, "LOAD_CONST");
                  sprintf(temp2, "$t%d", temp);
                  sprintf(temp3, "%s", no->attr.name);
                  sprintf(temp4, "-");
                  emitInstruction(temp1, temp2, temp3, temp4);
               }
               else {
                  sprintf(temp1, "LOAD");
                  sprintf(temp2, "$t%d", temp);
                  sprintf(temp3, "%s", no->attr.name);
                  sprintf(temp4, "-");
                  emitInstruction(temp1, temp2, temp3, temp4);
               }
               auxTemp = temp;
               break;
            }
         }
         auxTemp = generateExp(no);
         break;

      default:
         break;
      }

      // check if analysis continue for sibling node
      if (no->sibling != NULL && nextSibling == 1)
         auxTemp = analyzeNode(no->sibling);
   }

   return auxTemp;
}

void codeGen(TreeNode *no) {
   emitComment("INTERMEDIARY CODE:");

   sprintf(temp1, "LOAD_CONST");
   sprintf(temp2, "$sp");
   sprintf(temp3, "500");
   sprintf(temp4, "-");
   emitInstruction(temp1, temp2, temp3, temp4);

   sprintf(temp1, "JUMP_MAIN");
   sprintf(temp2, "-");
   sprintf(temp3, "-");
   sprintf(temp4, "-");
   emitInstruction(temp1, temp2, temp3, temp4);

   analyzeNode(no);
}
