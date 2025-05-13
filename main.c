/****************************************************/
/* File: main.c                                     */
/* Main program for C- compiler                     */
/* Gabriela Carregari Verza                         */
/*                                                  */
/* Adapted from                                     */
/* File: main.c                                     */
/* Main program for TINY compiler                   */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"

/* set NO_PARSE to TRUE to get a scanner-only compiler */
#define NO_PARSE FALSE
/* set NO_ANALYZE to TRUE to get a parser-only compiler */
#define NO_ANALYZE FALSE

/* set NO_CODE to TRUE to get a compiler that does not
 * generate code
 */
#define NO_CODE FALSE

#include "util.h"
#if NO_PARSE
#include "scan.h"
#else
#include "parse.h"
#if !NO_ANALYZE
#include "analyze.h"
#if !NO_CODE
#include "cgen.h"
// #include "assembly.h"
// #include "binary.h"
#endif
#endif
#endif

/* allocate global variables */
int lineno = 0;
FILE *source;
FILE *listing;
FILE *code; 
FILE *intermediary;
FILE *assembly;
FILE *binary;

/* allocate and set tracing flags */
int EchoSource = FALSE;
int TraceScan = TRUE;
int TraceParse = TRUE;
int TraceAnalyze = TRUE;
int TraceCode = FALSE;

int Error = FALSE;

int yywrap() { return 1; }

int main(int argc, char *argv[]) {
  TreeNode *syntaxTree;
  char pgm[120]; /* source code file name */
  if (argc != 2)
  {
    fprintf(stderr, "usage: %s <filename>\n", argv[0]);
    exit(1);
  }
  strcpy(pgm, argv[1]);
  if (strchr(pgm, '.') == NULL)
    strcat(pgm, ".cminus");
  source = fopen(pgm, "r");
  if (source == NULL)
  {
    fprintf(stderr, "File %s not found\n", pgm);
    exit(1);
  }
  listing = stdout; /* send listing to screen */
  fprintf(listing, "\nC- COMPILATION: %s\n", pgm);
#if NO_PARSE
  while (getToken() != ENDFILE);
#else
  syntaxTree = parse();
  if (TraceParse)
  {
    fprintf(listing, "\nSyntax tree:\n");
    printTree(syntaxTree);
  }
#if !NO_ANALYZE
  if (!Error)
  {
    if (TraceAnalyze)
      fprintf(listing, "\nBuilding Symbol Table...\n\n");
    buildSymtab(syntaxTree);
    if (TraceAnalyze)
      fprintf(listing, "\nChecking Types...\n");
    typeCheck(syntaxTree);
    if (TraceAnalyze)
      fprintf(listing, "\nType Checking Finished\n");
  }
#if !NO_CODE
  if (!Error) {
    {
        int fnlen = strcspn(pgm, ".");
        char * intermediaryFile;

        intermediaryFile = (char *) calloc(fnlen+4, sizeof(char));

        strncpy(intermediaryFile, pgm, fnlen);
        strcat(intermediaryFile, "_int.txt");
        
        intermediary = fopen(intermediaryFile, "w");

        if (intermediary == NULL) { 
            printf("File %s not found\n", intermediaryFile);
            exit(1);
        }

        codeGen(syntaxTree);
        fclose(intermediary);
        fprintf(listing,"\nIntermediary Code Finished\n");

        fnlen = strcspn(pgm, ".");
        char * assemblyFile;
        assemblyFile = (char *) calloc(fnlen+4, sizeof(char));

        strncpy(assemblyFile, pgm, fnlen);
        strcat(assemblyFile, "_ably.txt");
        
        assembly = fopen(assemblyFile, "w");

        if (assembly == NULL) { 
            printf("File %s not found\n", assemblyFile);
            exit(1);
        }

        intermediary = fopen(intermediaryFile, "r");

        if (intermediary == NULL) { 
            printf("File %s not found\n", intermediaryFile);
            exit(1);
        }

        assemblyGen();

        fclose(assembly);
        fclose(intermediary);
        fprintf(listing,"\nAssembly Code Finished\n");

        fnlen = strcspn(pgm, ".");
        char * binaryFile;

        binaryFile = (char *) calloc(fnlen+4, sizeof(char));

        strncpy(binaryFile, pgm, fnlen);
        strcat(binaryFile, "_bin.txt");
        
        binary = fopen(binaryFile, "w");

        if (binary == NULL) { 
            printf("File %s not found\n", binaryFile);
            exit(1);
        }

        assembly = fopen(assemblyFile, "r");
        
        if (assembly == NULL) { 
            printf("File %s not found\n", assemblyFile);
            exit(1);
        
        }
        binaryGen();
        fclose(binary);
        fclose(assembly);
        fprintf(listing,"\nBinary Code Finished\n");
  }
} 
#endif
#endif
#endif
  fclose(source);
  return 0;
}
