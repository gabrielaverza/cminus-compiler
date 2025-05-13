/****************************************************/
/* File: cminus.l                                   */
/* Lex specification for C-                         */
/* Gabriela Carregari Verza                         */
/*                                                  */
/* Adapted from                                     */ 
/* File: tiny.l                                     */
/* Lex specification for TINY                       */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden   			                        */
/****************************************************/

%{
#include "globals.h"
#include "util.h"
#include "scan.h"
/* lexeme of identifier or reserved word */
char tokenString[MAXTOKENLEN+1];

static int yylex(void); /* add to ensure no conflict with lex */
%}

/* regular expressions */

digit       [0-9]   
number      {digit}+
letter      [a-zA-Z]
identifier  {letter}+
newline     \r?\n
whitespace  [ \t\r]+

%%

"else"          {return ELSE;}                           /* key words */
"if"            {return IF;}
"int"           {return INT;}
"return"        {return RETURN;}
"void"          {return VOID;}
"while"         {return WHILE;}
"+"             {return PLUS;}                           /* special symbols */
"-"             {return MINUS;}
"*"             {return TIMES;}
"/"             {return OVER;}
"<"             {return LT;}
"<="            {return LTE;}
">"             {return GT;}
">="            {return GTE;}
"=="            {return EQ;}
"!="            {return NEQ;}
"="             {return ASSIGN;}
";"             {return SEMI;}
","		          {return COMMA;}
"("             {return LPAREN;}
")"             {return RPAREN;}
"["             {return LBRACKET;}
"]"             {return RBRACKET;}
"{"             {return LBRACES;}
"}"             {return RBRACES;}
{number}        {return NUM;}                          /* markers */
{identifier}    {return ID;}
{newline}       {lineno++;}                            /* new line counter */
{whitespace}    { }                                    /* skip whitespace */
"/*"	          { char c;                              /* comments */ 
                while (1) {
                    c = input();
                    if (c == EOF) break;
                    if (c == '\n') lineno++;
                    while ((c = input()) == '*');
                    if (c == '/') break;
                  }
		            }
.               {return ERROR;}
<<EOF>>	        {return ENDFILE;}

%%

TokenType getToken(void) {
  static int firstTime = TRUE;
  TokenType currentToken;
  
  if (firstTime) {
    firstTime = FALSE;
    lineno++;
    yyin = source;
    yyout = listing;
  }
  
  currentToken = yylex();
  strncpy(tokenString, yytext, MAXTOKENLEN);
  
  if (TraceScan) {
    fprintf(listing, "\t%d: ", lineno);
    printToken(currentToken, tokenString);
  }
  
  return currentToken;
}







