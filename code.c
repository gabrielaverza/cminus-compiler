/****************************************************/
/* File: code.c                                     */
/* TM Code emitting utilities                       */
/* implementation for the C- compiler               */
/* Gabriela Carregari Verza                         */
/*                                                  */
/* Adapted from                                     */
/* File: code.c                                     */
/* TM Code emitting utilities                       */
/* implementation for the TINY compiler             */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "code.h"

/* Procedure emitComment prints a comment line 
 * with comment c in the code file
 */
void emitComment(char *c) {
  if (TraceCode)
    fprintf(intermediary, " %s\n", c);
}

/* Procedure emitLabel prints a comment line 
 * with labels in the code file
 */
void emitLabel(int label) {
  fprintf(intermediary, "(LABEL,L%d,-,-)\n", label);
}

/* Procedure emitInstruction prints a comment line 
 * with instructions in the code file
 */
void emitInstruction(char *op, char *first, char *second, char *third) {
  fprintf(intermediary, "(%s,%s,%s,%s)\n", op, first, second, third);
}