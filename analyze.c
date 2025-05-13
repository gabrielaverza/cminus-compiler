/****************************************************/
/* File: analyze.c                                  */
/* Semantic analyzer implementation                 */
/* for the C- compiler                              */
/* Gabriela Carregari Verza                         */
/*                                                  */
/* Adapted from                                     */
/* File: analyze.c                                  */
/* Semantic analyzer implementation                 */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "symtab.h"
#include "analyze.h"
#include <string.h>

/* counter for variable memory locations */
static int location = 0;

char *currentScope;

static void printError(TreeNode *t, char *msg) {
  if (t->attr.name == NULL)
    fprintf(listing, "SEMANTICAL ERROR: %s LINE: %d\n", msg, t->lineno);
  else
    fprintf(listing, "SEMANTICAL ERROR: %s (%s) LINE: %d\n", t->attr.name, msg, t->lineno);
  Error = TRUE;
}

/* Procedure traverse is a generic recursive 
 * syntax tree traversal routine:
 * it applies preProc in preorder and postProc 
 * in postorder to tree pointed to by t
 */

static void traverse(TreeNode *t, void (*preProc)(TreeNode *), void (*postProc)(TreeNode *)) {
  if (t != NULL) {
    preProc(t);
    {
      int i;
      for (i = 0; i < MAXCHILDREN; i++){
        traverse(t->child[i], preProc, postProc);
      }
    }
    postProc(t);
    traverse(t->sibling, preProc, postProc);
  }
}

/* nullProc is a do-nothing procedure to 
 * generate preorder-only or postorder-only
 * traversals from traverse
 */

static void nullProc(TreeNode *t) {
  if (t == NULL) return;
  else return;
}

/* Procedure verify inserts 
 * identifiers stored in t into 
 * the symbol table 
 */

static void verify(TreeNode *t) {
  TreeNode *aux;
  int vet = 0;
  int contArgs = 0;
  int checkArgs = 0;

  if (t->nodekind == StmtK) {
    switch (t->kind.stmt)
    {
    case VariableK:
    case VectorK:
      if (t->specifier_type == VoidK)
        printError(t, "Variable declared as void");
      else if ((search_index(t->attr.name, "global", "function") == 0)) /* checks if a function with the same name is in the table */
        printError(t, "A function with that name is already declared");
      else if ((search_scope(t->attr.name, t->attr.scope) == -1)) /* not yet in table, so treat as new definition */
        insert(location++, t->attr.name, t->attr.scope, "variable", t->specifier_type, 0, 0, 0);
      else
        printError(t, "A variable with that name is already declared"); /* already in table */
      break;

    case ParameterK:
      if (t->specifier_type == VoidK)
        printError(t, "Variable declared as void");
      else if ((search_index(t->attr.name, "global", "function") == 0)) /* checks if a function with the same name is in the table */
        printError(t, "A function with that name is already declared");
      else if (search_index(t->attr.name, t->attr.scope, "variable") == -1) /* not yet in table, so treat as new definition */
        insert(location++, t->attr.name, t->attr.scope, "variable", t->specifier_type, 1, -1, 0);
      else if (search_scope(t->attr.name, t->attr.scope) == -1 && (strcmp(search_data_id_param_vect(t->attr.name, t->attr.scope, 4), "yes") || strcmp(search_data_id_param_vect(t->attr.name, "global", 4), "yes")))
      { /* treat vector */
        t->kind.exp = VectK;
        vet = 1;
        insert(location++, t->attr.name, t->attr.scope, "variable", t->specifier_type, 1, vet, 0);
        vet = 0;
      }
      else
        printError(t, "A variable with that name is already declared"); /* already in table */
      break;

    case FunctionK:
      for (aux = t->child[1]; aux != NULL; aux = aux->sibling)
        aux->attr.scope = t->attr.name;

      for (aux = t->child[0]; aux != NULL; aux = aux->sibling)
      {
        if (aux->nodekind == ExpK && aux->kind.exp == TypeK)
        {
          aux->attr.scope = t->attr.name;
          contArgs++; /* gets the number of arguments */
        }
      }
      if (search_index(t->attr.name, t->attr.scope, "function") == -1) /* not yet in table, so treat as new definition */
        insert(0, t->attr.name, t->attr.scope, "function", t->specifier_type, -1, -1, contArgs);
      else
        printError(t, "A function with that name is already declared"); /* already in table */
      break;

    case CallK:
      if (strcmp(search_data_id_param_vect(t->attr.name, "global", 2), "null") == 0 && strcmp(t->attr.name, "input") != 0 && strcmp(t->attr.name, "output")) /* checks if the function is declared */
        printError(t, "Function not declared");

      for (aux = t->child[0]; aux != NULL; aux = aux->sibling) /* check number of arguments */
        contArgs++;

      if(strcmp(t->attr.name, "input") == 0 && contArgs != 0)
        printError(t, "Input function must have no arguments");

      if(strcmp(t->attr.name, "output") == 0 && contArgs == 0)
        printError(t, "Output function must have arguments");

      if (totalArgs(t->attr.name) != -1 && totalArgs(t->attr.name) != contArgs)
        printError(t, "Number of arguments does not match");

      for (aux = t->child[0]; aux != NULL; aux = aux->sibling)
        aux->attr.scope = t->attr.scope;
      break;

    case WhileK:
      for (aux = t->child[0]; aux != NULL; aux = aux->sibling)
        aux->attr.scope = t->attr.scope;

      for (aux = t->child[1]; aux != NULL; aux = aux->sibling)
        aux->attr.scope = t->attr.scope;

      break;

    case IfK:
      for (aux = t->child[0]; aux != NULL; aux = aux->sibling)
        aux->attr.scope = t->attr.scope;

      for (aux = t->child[1]; aux != NULL; aux = aux->sibling)
        aux->attr.scope = t->attr.scope;

      for (aux = t->child[2]; aux != NULL; aux = aux->sibling)
        aux->attr.scope = t->attr.scope;

      break;

    case AssignK:
      for (aux = t->child[0]; aux != NULL; aux = aux->sibling)
        aux->attr.scope = t->attr.scope;

      for (aux = t->child[1]; aux != NULL; aux = aux->sibling)
        aux->attr.scope = t->attr.scope;

      if (t->child[1]->kind.stmt == CallK && strcmp(search_data_id_param_vect(t->child[1]->attr.name, "global", 1), "int") != 0 && strcmp(search_data_id_param_vect(t->child[1]->attr.name, "global", 1), "null") != 0)
        printError(t->child[1], "Expected a void's function return");
      break;

    case ReturnK:
      for (aux = t->child[0]; aux != NULL; aux = aux->sibling)
        aux->attr.scope = t->attr.scope;
      break;

    default:
      break;
    }
  }
  else if (t->nodekind == ExpK)
  {
    switch (t->kind.exp)
    {
    case IdK:
      if (search_index(t->attr.name, t->attr.scope, "variable") == -1 && search_index(t->attr.name, "global", "variable") == -1) /* checks if the variable is declared */
        printError(t, "Variable not declared");
      else
      {
        if (t->kind.exp == 3)
          vet = 1;
        else
          vet = 0;
        if (search_scope(t->attr.name, "global") == 1) /* checks if it is in global scope */
          insert(0, t->attr.name, "global", "variable", t->specifier_type, -1, vet, 0);
        else
          insert(0, t->attr.name, t->attr.scope, "variable", t->specifier_type, -1, -1, 0);
        vet = 0;
      }
      break;

    case TypeK:
      t->child[0]->attr.scope = t->attr.scope;
      break;

    case VectK:
      for (aux = t->child[0]; aux != NULL; aux = aux->sibling)
        aux->attr.scope = t->attr.scope;

      if (search_index(t->attr.name, t->attr.scope, "variable") == -1 && search_index(t->attr.name, "global", "variable") == -1) /* checks if the variable is declared */
        printError(t, "Variable not declared");
      else if (search_scope(t->attr.name, "global") == 1) /* checks if it is in global scope */
        insert(0, t->attr.name, "global", "variable", t->specifier_type, -1, -1, 0);
      else
        insert(0, t->attr.name, t->attr.scope, "variable", t->specifier_type, -1, -1, 0);
      break;

    case OpK:
      for (aux = t->child[0]; aux != NULL; aux = aux->sibling)
        aux->attr.scope = t->attr.scope;

      for (aux = t->child[1]; aux != NULL; aux = aux->sibling)
        aux->attr.scope = t->attr.scope;
      break;

    default:
      break;
    }
  }
}

/* Function buildSymtab constructs the symbol 
 * table by preorder traversal of the syntax tree
 */

void buildSymtab(TreeNode *syntaxTree) {
  TreeNode *aux;
  syntaxTree->attr.scope = "global";

  for (aux = syntaxTree->sibling; aux != NULL; aux = aux->sibling) {
    if (aux->nodekind == ExpK)
      if (aux->kind.exp == TypeK)
        aux->attr.scope = "global";
  }

  traverse(syntaxTree, verify, nullProc);

  if (search_index("main", "global", "function") == -1) {
    fprintf(listing, "\nSEMANTICAL ERROR: Main function not declared\n");
    Error = TRUE;
  }

  if (TraceAnalyze) {
    fprintf(listing, "\nSymbol Table:\n\n");
    printSymTab(listing);
  }
}

/* Procedure checkNode performs
 * type checking at a single tree node
 */

static void checkNode(TreeNode *t) {

  if (t->attr.scope != NULL)
    currentScope = t->attr.scope;

  if (t->nodekind == ExpK)
  {
    switch (t->kind.exp)
    {
    case OpK:
      if (t->child[0]->specifier_type != IntK)
        printError(t->child[0], "The type of the variable is not int");
      if (t->child[1]->specifier_type != IntK)
        printError(t->child[1], "The type of the variable is not int");
      if ((t->attr.op == ASSIGN) || (t->attr.op == LTE) || (t->attr.op == GT) || (t->attr.op == GTE) || (t->attr.op == LT) || (t->attr.op == NEQ))
        t->specifier_type = IntK;
      else
        t->specifier_type = IntK;
      break;

    case ConstK:
      t->specifier_type = IntK;
      break;

    case VectK:
      if (strcmp(search_data_id_param_vect(t->attr.name, currentScope, 1), "int") == 0)
        t->specifier_type = IntK;
      else if (strcmp(search_data_id_param_vect(t->attr.name, "global", 1), "int") == 0)
        t->specifier_type = IntK;
      else if (strcmp(search_data_id_param_vect(t->attr.name, currentScope, 1), "null") == 0 || strcmp(search_data_id_param_vect(t->attr.name, "global", 1), "null") == 0)
        t->specifier_type = VoidK;
      else
        printError(t, "Variable not declared");
      break;

    case IdK:
      if (strcmp(search_data_id_param_vect(t->attr.name, currentScope, 1), "int") == 0)
        t->specifier_type = IntK;
      else if (strcmp(search_data_id_param_vect(t->attr.name, "global", 1), "int") == 0)
        t->specifier_type = IntK;
      else if (strcmp(search_data_id_param_vect(t->attr.name, currentScope, 1), "null") == 0 || strcmp(search_data_id_param_vect(t->attr.name, "global", 1), "null") == 0)
        t->specifier_type = VoidK;
      else
        printError(t, "Variable not declared");
      break;

    default:
      break;
    }
  }
  else if (t->nodekind == StmtK)
  {
    switch (t->kind.stmt)
    {
    case AssignK:
      if (t->child[0]->specifier_type != IntK)
        printError(t->child[0], "Assignment to a non-integer type variable");
      break;

    case IfK:
      if (t->child[0]->specifier_type != IntK)
        printError(t, "Invalid operation");
      break;

    default:
      break;
    }
  }
}

/* Procedure typeCheck performs type checking 
 * by a postorder syntax tree traversal
 */

void typeCheck(TreeNode *syntaxTree) {
  traverse(syntaxTree, nullProc, checkNode);
}