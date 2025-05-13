/****************************************************/
/* File: cminus.y                                   */
/* The C- Yacc/Bison specification file             */
/* Gabriela Carregari Verza                         */
/*                                                  */
/* Adapted from                                     */
/* File: tiny.y                                     */
/* The TINY Yacc/Bison specification file           */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

%{
#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h" 

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void); /* add to ensure no conflict with lex */

%}

/* tokens declarations */

%token ELSE IF INT RETURN VOID WHILE
%token PLUS MINUS TIMES OVER
%token LT LTE GT GTE
%token EQ NEQ ASSIGN
%token SEMI COMMA
%token LPAREN RPAREN LBRACKET RBRACKET LBRACES RBRACES
%token ID NUM 
%token ENDFILE ERROR

%% /* grammar rules for cminus */

program		     :   declaration_list
				     { savedTree = $1; }
			     ;
declaration_list	:   declaration_list declaration
            	            {
             	               YYSTYPE t = $1;
             	               if(t != NULL)
				     	{ 
                                   while(t->sibling != NULL)
             	                       t = t->sibling;
             	                   t->sibling = $2;
             	                   $$ = $1;
                              }
             	               else $$ = $2;
             	            }
			     |   declaration 
				     { $$ = $1; }
			     ;
declaration		:   variable_declaration 
				    { $$ = $1; }
			     |   function_declaration 
				    { $$ = $1; }
			     ;
variable_declaration 	:   specifier_type identifier SEMI
			              {
                              $$ = $1;
                              $$->child[0] = $2;
                              $2->nodekind = StmtK;
                              $2->kind.stmt = VariableK;
                              $2->specifier_type = $1->specifier_type;
			              }
			          |   specifier_type identifier LBRACKET number RBRACKET SEMI
			              {
                              $$ = $1;
                              $$->child[0] = $2;
                              $2->nodekind = StmtK;
                              $2->kind.stmt = VectorK;
                              $2->attr.len = $4->attr.val;
                              $2->specifier_type = $1->specifier_type;
                             }
			          ;
specifier_type		:   INT
			          {
                            $$ = newExpNode(TypeK);
                            $$->specifier_type = IntK;
                            $$->attr.name = "Inteiro";
                         }

                    	|   VOID
                             {
                              $$ = newExpNode(TypeK);
                              $$->specifier_type = VoidK;
                              $$->attr.name = "Void";
                            }
			          ;
function_declaration   :   specifier_type identifier LPAREN parameters RPAREN compound_declaration 
                        {
                            $$ = $1;
                            $$->child[0] = $2;
                            $2->child[0] = $4;
                            $2->child[1] = $6;
                            $2->nodekind = StmtK;
                            $2->kind.stmt = FunctionK;
                            $2->specifier_type = $1->specifier_type;
                        }
			        ;
parameters		:   parameter_list
                       {
                           $$ = $1;
                       }
			     |   VOID
                       {
                       }
			     ;
parameter_list		:   parameter_list COMMA parameter
                           {
                            YYSTYPE t = $1;
                            if(t != NULL)
                           {
				          while(t->sibling != NULL)
                                  t = t->sibling;
				          t->sibling = $3;
				          $$ = $1;
                           }
                            else
                              $$ = $1;
                         }
			     |   parameter
                       {
                            $$ = $1;
                       }
			     ;
parameter		:   specifier_type identifier
                       {
                           $$ = $1;
                           $$->child[0] = $2;
                           $2->nodekind = StmtK;
                           $2->kind.stmt = ParameterK;
                           $2->specifier_type = $1->specifier_type;

                       }
			|   specifier_type identifier LBRACKET RBRACKET
			        {
                            $$ = $1;
                            $$->child[0] = $2;
                            $2->nodekind = StmtK;
                            $2->kind.exp = VectK;
                            $2->kind.stmt = ParameterK;
                            $2->specifier_type = $1->specifier_type;
                       }
               ;
compound_declaration  	:   LBRACES local_declarations statement_list RBRACES
                             {
                              YYSTYPE t = $2;
                              if(t != NULL)
                                {
                                 while(t->sibling != NULL)
                                    t = t->sibling;
                                  t->sibling = $3;
                                  $$ = $2;
                                }
                                 else
                                 $$ = $3;
                              }
                       |   LBRACES local_declarations RBRACES
                       {
                            $$ = $2;
                       }
	                  |   LBRACES statement_list RBRACES
                       {
                            $$ = $2;
                       }
	                  |   LBRACES RBRACES
                       {
                       }
			        ;
local_declarations  	:   local_declarations variable_declaration
                       {
                            YYSTYPE t = $1;
                            if(t != NULL)
                            {
                              while(t->sibling != NULL)
                                   t = t->sibling;
                              t->sibling = $2;
                              $$ = $1;
                            }
                            else
                               $$ = $2;
                       }
			|    variable_declaration
                       {
                            $$ = $1;
                       }
			;
statement_list 	:   statement_list statement
                       {
                           YYSTYPE t = $1;
                           if(t != NULL)
                           {
                              while(t->sibling != NULL)
                                   t = t->sibling;
                              t->sibling = $2;
                              $$ = $1;
                           }
                           else
                             $$ = $2;
			}
			|   statement
                       {
                           $$ = $1;
                       }
			;
statement 	     	:   expression_decl
                       {
                           $$ = $1;
                       }
               	|   compound_declaration
                       {
                           $$ = $1;
                       }
               	|   if_decl
                       {
                           $$ = $1;
                       }
               	|   loop_decl
                       {
                           $$ = $1;
                       }
			|   return_decl
                       {
                           $$ = $1;
                       }
               	;
expression_decl	:   expression SEMI
                       {
                           $$ = $1;
                       }
               	|   SEMI
                       {
                       }
               	;
if_decl	 	:   IF LPAREN expression RPAREN statement
                       {
                             $$ = newStmtNode(IfK);
                             $$->child[0] = $3;
                             $$->child[1] = $5;
                       }
               	|   IF LPAREN expression RPAREN statement ELSE statement
                       {
               
                             $$ = newStmtNode(IfK);
                             $$->child[0] = $3;
                             $$->child[1] = $5;
                             $$->child[2] = $7;
                       }
               	;
loop_decl	  	:   WHILE LPAREN expression RPAREN statement
                       {
                             $$ = newStmtNode(WhileK);
                             $$->child[0] = $3;
                             $$->child[1] = $5;
                       }
               	;
return_decl        	:   RETURN SEMI
                       {
                            $$ = newStmtNode(ReturnK);
                       }
	               |   RETURN expression SEMI
                       {
                            $$ = newStmtNode(ReturnK);
                            $$->child[0] = $2;
                       }
			;
expression      	:   var ASSIGN expression
                       {
                            $$ = newStmtNode(AssignK);
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                       }
			|   simple_expression
                       {
                            $$ = $1;
                       }
			;
var			:   identifier
                       {
                            $$ = $1;
                       }
			|   identifier LBRACKET expression RBRACKET
                       {
                            $$ = $1;
                            $$->child[0] = $3;
                            $$->kind.exp = VectK;
                       }
			;
simple_expression	: sum_expression relational sum_expression
                       {
                            $$ = $2;
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                       }
			|  sum_expression
                       {
                            $$ = $1;
                       }
			;
relational		:  EQ
                       {
                            $$ = newExpNode(OpK);
                            $$->attr.op = EQ;                            
                       }
			|  NEQ
                       {
                            $$ = newExpNode(OpK);
                            $$->attr.op = NEQ;                            
                       }
			|  LT
                       {
                            $$ = newExpNode(OpK);
                            $$->attr.op = LT;                            
                       }
			|  LTE
                       {
                            $$ = newExpNode(OpK);
                            $$->attr.op = LTE;                            
                       }
			|  GT
                       {
                            $$ = newExpNode(OpK);
                            $$->attr.op = GT;                            
                       }
			|  GTE
                       {
                            $$ = newExpNode(OpK);
                            $$->attr.op = GTE;                            
                       }
			;
sum_expression		:  sum_expression sum term
                       {
                            $$ = $2;
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                       }
			|  term
                       {
                            $$ = $1;
                       }
			;
sum			:  PLUS
			{
                            $$ = newExpNode(OpK);
                            $$->attr.op = PLUS;                            
			}
			| MINUS
			{
                            $$ = newExpNode(OpK);
                            $$->attr.op = MINUS;                            
			}
			;
term			:   term mult factor
                       {
                            $$ = $2;
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                       }
			|   factor
                       {
                            $$ = $1;
                       }
			;
mult 			:   TIMES
                       {
                            $$ = newExpNode(OpK);
                            $$->attr.op = TIMES;                            
                       }
			|   OVER
                       {
                            $$ = newExpNode(OpK);
                            $$->attr.op = OVER;                            
                       }
			;
factor			:   LPAREN expression RPAREN
                       {
                            $$ = $2;
                       }
			|   var
                       {
                            $$ = $1;
                       }
			|   activation
                       {
                            $$ = $1;
                       }
			|   number
                       {
                            $$ = $1;
                       }
			;
activation		:   identifier LPAREN argument_list RPAREN
                       {
                            $$ = $1;
                            $$->child[0] = $3;
                            $$->nodekind = StmtK;
                            $$->kind.stmt = CallK;
                       }                       
			|   identifier LPAREN RPAREN
			{
                            $$ = $1;
                            $$->nodekind = StmtK;
                            $$->kind.stmt = CallK;
                       }                       
			;
argument_list		:   argument_list COMMA expression
                       {
                            YYSTYPE t = $1;
                             if(t != NULL)
                             {
                                while(t->sibling != NULL)
                                   t = t->sibling;
                                 t->sibling = $3;
                                 $$ = $1;
                             }
                             else
                                 $$ = $3;
                       }
			|  expression
                       {
                             $$ = $1;
                       }
			;
identifier             :   ID
                       {
                             $$ = newExpNode(IdK);
                             $$->attr.name = copyString(tokenString);
                       }
			;
number			:   NUM
                       {
                             $$ = newExpNode(ConstK);
                             $$->attr.val = atoi(tokenString);
                       }
			;

%%

int yyerror(char* message){
     if(yychar != ENDFILE && !Error){
          fprintf(listing,"\nSINTATICAL ERROR: ");
          printToken(yychar,tokenString);
          fprintf(listing, "LINE: %d\n",lineno);
          Error = TRUE;
     }
     return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ yyparse();
  return savedTree;
}