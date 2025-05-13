/****************************************************/
/* File: symtab.c                                   */
/* Symbol table implementation for the C- compiler  */
/* (allows only one symbol table)                   */
/* Symbol table is implemented as a chained         */
/* hash table                                       */
/* Gabriela Carregari Verza                         */
/*                                                  */
/* Adapted from                                     */
/* File: symtab.c                                   */
/* Symbol table implementation for the TINY compiler*/
/* (allows only one symbol table)                   */
/* Symbol table is implemented as a chained         */
/* hash table                                       */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

#include "globals.h"
#include "analyze.h"
#include <string.h>

/* SIZE is the size of the hash table */
#define SIZE 211
/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 4

/* the hash function */
static int hash(char *name, char *scope) {
  int temp = 0;
  int i = 0;
  while (name[i] != '\0') {
    temp = ((temp << SHIFT) + name[i]) % SIZE;
    i++;
  }
  i = 0;
  while (scope[i] != '\0') {
    temp = ((temp << SHIFT) + scope[i]) % SIZE;
    i++;
  }
  return temp;
}

/* the list of line numbers of the source
 * code in which a variable is referenced
 */
typedef struct LineListRec {
  int lineno;
  struct LineListRec *next;
} * LineList;

/* The record in the bucket lists for
 * each variable, including name,
 * assigned memory location, and
 * the list of line numbers in which
 * it appears in the source code
 */
typedef struct BucketListRec {
  int memloc; /* memory location for variable */
  char *name;
  char *scope;
  char *data_type;
  char *id_type;
  char *param_flag;
  char *vector_flag;
  int argsFunction;
  struct BucketListRec *next;
} * BucketList;

/* the hash table */
static BucketList hashTable[SIZE];

/* Procedure insert inserts line numbers and
 * memory locations into the symbol table
 */
void insert(int memloc, char *name, char *scope, char *id_type, int data_type, int param_flag, int vector_flag, int argsFunction) {
  int h;
  h = hash(name, scope);
  BucketList aux = hashTable[h];
  while ((aux != NULL) && ((strcmp(id_type, aux->id_type) != 0) || (strcmp(name, aux->name) != 0) || (strcmp(scope, aux->scope) != 0)))
    aux = aux->next;

  if (aux == NULL) { /* variable not yet in table */
    aux = (BucketList)malloc(sizeof(struct BucketListRec));
    aux->name = name;
    aux->scope = scope;

    if (data_type == 0)
      aux->data_type = "void";
    else if (data_type == 1)
      aux->data_type = "int";

    aux->id_type = id_type;

    if (param_flag == 0)
      aux->param_flag = "no";
    else if (param_flag == 1)
      aux->param_flag = "yes";
    else if (param_flag == -1)
      aux->param_flag = "-";

    if (vector_flag == 0)
      aux->vector_flag = "no";
    else if (vector_flag == 1)
      aux->vector_flag = "yes";
    else if (vector_flag == -1)
      aux->vector_flag = "-";

    aux->argsFunction = argsFunction;
    aux->memloc = memloc;
    aux->next = hashTable[h];
    hashTable[h] = aux;
  }
}

/* Function search_index returns the index 
 * of a variable or -1 if not found
 */
int search_index(char *name, char *scope, char *id_type) {
  int h = hash(name, scope);
  BucketList aux = hashTable[h];

  while ((aux != NULL) && ((strcmp(id_type, aux->id_type) != 0) || (strcmp(name, aux->name) != 0) || (strcmp(scope, aux->scope) != 0)))
    aux = aux->next;

  if (aux == NULL)
    return -1;
  return aux->memloc;
}

/*
  Function search_data_id_param_vect ()
  Flag 1: return data type
  Flag 2: return id type
  Flag 3: return if it has parameters
  Flag 4: return if it is vector 
*/

char *search_data_id_param_vect(char *name, char *scope, int flag)
{
  int h = hash(name, scope);
  BucketList aux = hashTable[h];
  while ((aux != NULL) && (strcmp(name, aux->name) != 0) && (strcmp(scope, aux->scope) != 0))
    aux = aux->next;

  if (aux == NULL)
    return "null";

  if (flag == 1)
    return aux->data_type;
  else if (flag == 2)
    return aux->id_type;
  else if (flag == 3)
    return aux->param_flag;
  else if (flag == 4)
    return aux->vector_flag;
}

/* Function search_scope returns the memory 
 * location of a variable or -1 if not found
 */
int search_scope(char *name, char *scope) {
  int h = hash(name, scope);
  BucketList aux = hashTable[h];
  while ((aux != NULL) && (strcmp(name, aux->name) != 0) && (strcmp(scope, aux->scope) != 0))
    aux = aux->next;
  if (aux == NULL)
    return -1;
  return 1;
}

/* Function totalArgs returns the total 
 * number of args of the function
 */
int totalArgs(char *name) {
  int h = hash(name, "global");
  BucketList aux = hashTable[h];
  if (aux == NULL)
    return -1;
  return aux->argsFunction;
}

/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab(FILE *listing) {
  int i;
  fprintf(listing, "Name                Type      Escope       \n");
  fprintf(listing, "------------------  -------   -----------  \n");
  for (i = 0; i < SIZE; i++) {
    if (hashTable[i] != NULL) {
      BucketList aux = hashTable[i];
      while (aux != NULL)
      {
        fprintf(listing, "%-20s", aux->name);
        fprintf(listing, "%-10s", aux->data_type);
        fprintf(listing, "%s", aux->scope);
        fprintf(listing, "\n");
        aux = aux->next;
      }
    }
  }
}