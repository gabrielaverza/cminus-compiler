/****************************************************/
/* File: assembly.c                                 */
/* The assembly generator implementation            */
/* for the C- compiler                              */
/* Gabriela Carregari Verza                         */
/****************************************************/

#include "globals.h"
#include "symtab.h"
#include <string.h>
#include "cgen.h"
#include "assembly.h"
#include "register_bank.h"

int mainLine;

// auxiliar vectors
char instruction_name[40];
char register_rs_a[40];
char register_rt_a[40];
char register_rd_a[40];

int contParams = 0, currentArg = 0, contArg = 0, i;
int *label_pos;

static int currentLine = 1;
static int qtdFunc = 0;

char function[40];
char regist[40];

typedef struct {
    char instructionName[10]; 
    char rs[10];
    char rt[10];
    char rd[10];
    char label[10];
} assemblyType;
assemblyType *instruction;

typedef struct {
    char name[40];
    int pos;
} labelType;
labelType *posLabel;

void addInstruction(char *inst, char *regRs, char *regRt, char *regRd) {
    strcpy(instruction[currentLine].instructionName, inst);
    strcpy(instruction[currentLine].rs, regRs);
    strcpy(instruction[currentLine].rt, regRt);
    strcpy(instruction[currentLine].rd, regRd);
}

int findParameters(char *line, int index, int flag) { 
    int j = 0, i;

    if (flag == 0) { // search for all parameters, except the last one
        for (i = index; i < 40 && line[i] != ','; i++) {
            regist[j] = line[i];
            j++;
        }
        regist[j] = '\0';
        return i + 1;
    }
    else { // search for the last parameter
        for (i = index; i < 40 && line[i] != ')'; i++) {
            regist[j] = line[i];
            j++;
        }
        regist[j] = '\0';
    }
    return 0;
}

int searchMemPos() { 
    int sl_pos;
    if (strcmp(regist, "0") == 0)
        sl_pos = 0;
    else {
        sl_pos = search_index(regist, function, "variable");
        if (sl_pos == -1)
            sl_pos = search_index(regist, "global", "variable");
    }
    return sl_pos;
}

void addi(char *line, int index) {
    sprintf(instruction_name, "addi");
    index = findParameters(line, index, 0);
    sprintf(register_rt_a, "$%d,", get_register(regist));
    index = findParameters(line, index, 0);
    strcpy(register_rd_a, regist);
    strcpy(register_rs_a, "$0,");
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void jump(char *line, int index) {
    sprintf(instruction_name, "jump");
    index = findParameters(line, index, 0);
    strcpy(register_rs_a, regist);
    strcpy(register_rt_a, "");
    strcpy(register_rd_a, "");
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void label(char *line, int index) {
    findParameters(line, index + 1, 0);
    label_pos[atoi(regist)] = currentLine;
    index = findParameters(line, index, 0);
    strcpy(instruction[currentLine].label, regist);
    currentLine--;
}

void ffunction(char *line, int index) {
    index = findParameters(line, index, 0);
    index = findParameters(line, index, 0);
    sprintf(function, "%s", regist);
    if (strcmp(function, "main") == 0)
        mainLine = currentLine;

    posLabel = (labelType *)realloc(posLabel, (qtdFunc + 1) * sizeof(labelType));
    strcpy(posLabel[qtdFunc].name, regist);
    posLabel[qtdFunc].pos = currentLine;
    qtdFunc++;
    strcpy(instruction[currentLine].label, regist);
    currentLine--;
}

void load(char *line, int index) {
    sprintf(instruction_name, "lw");
    index = findParameters(line, index, 0);
    sprintf(register_rs_a, "$%d,", get_register(regist));
    index = findParameters(line, index, 0);
    sprintf(register_rt_a, "%d", searchMemPos());
    findParameters(line, index, 1);
    sprintf(register_rd_a, "($%d)", get_register(regist));
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void load_v(char *line, int index) {
    sprintf(instruction_name, "lw");
    index = findParameters(line, index, 0);
    sprintf(register_rs_a, "$%d,", get_register(regist));
    index = findParameters(line, index, 0);
    sprintf(register_rt_a, "%d", searchMemPos());
    findParameters(line, index, 1);
    sprintf(register_rd_a, "($%d)", get_register(regist));
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void store(char *line, int index) {
    sprintf(instruction_name, "sw");
    index = findParameters(line, index, 0);
    sprintf(register_rs_a, "$%d,", get_register(regist));
    index = findParameters(line, index, 0);
    sprintf(register_rt_a, "%d", searchMemPos());
    findParameters(line, index, 1);
    sprintf(register_rd_a, "($%d)", get_register(regist));
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void call(char *line, int index) {
    sprintf(instruction_name, "jal");
    index = findParameters(line, index, 0);
    sprintf(register_rs_a, "$%d,", get_register(regist));
    index = findParameters(line, index, 0);
    for (i = 0; strcmp(posLabel[i].name, regist) != 0; i++){
    }
    sprintf(register_rs_a, "%d", posLabel[i].pos);
    strcpy(register_rt_a, "");
    strcpy(register_rd_a, "");
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
    contArg = contParams;
    contParams = 0;
}

void callOut(char *line, int index) {
    sprintf(instruction_name, "output");
    index = findParameters(line, index, 0);
    sprintf(register_rt_a, "$%d", get_register(regist));
    strcpy(register_rs_a, "");
    strcpy(register_rd_a, "");
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void callIn(char *line, int index) {
    sprintf(instruction_name, "input");
    index = findParameters(line, index, 0);
    sprintf(register_rd_a, "$%d", get_register(regist));
    strcpy(register_rs_a, "");
    strcpy(register_rt_a, "");
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void if_conditional(char *line, int index) {
    index = findParameters(line, index, 0);
    index = findParameters(line, index, 0);
    strcpy(instruction[currentLine - 1].rd, regist);
    currentLine--;
}

void branchNE(char *line, int index) {
    sprintf(instruction_name, "bne");
    index = findParameters(line, index, 0);
    sprintf(register_rs_a, "$%d,", get_register(regist));
    index = findParameters(line, index, 0);
    sprintf(register_rt_a, "$%d,", get_register(regist));
    strcpy(register_rd_a, "");
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void branchEQ(char *line, int index) {
    sprintf(instruction_name, "beq");
    index = findParameters(line, index, 0);
    sprintf(register_rs_a, "$%d,", get_register(regist));
    index = findParameters(line, index, 0);
    sprintf(register_rt_a, "$%d,", get_register(regist));
    strcpy(register_rd_a, "");
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void branchGE(char *line, int index) {
    // int index_aux;
    // index_aux = index;

    // sprintf(instruction_name, "addi");
    // index = findParameters(line, index, 0);
    // sprintf(register_rt_a, "$%d,", get_register(regist));
    // strcpy(register_rd_a, "0");
    // strcpy(register_rs_a, "$0,");
    // addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
    // currentLine++;

    // index = index_aux;
    sprintf(instruction_name, "slt");
    index = findParameters(line, index, 0);
    sprintf(register_rs_a, "$%d,", get_register(regist));
    index = findParameters(line, index, 0);
    sprintf(register_rt_a, "$%d,", get_register(regist));
    findParameters(line, index, 1);
    sprintf(register_rd_a, "$%d", get_register(regist));
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
    currentLine++;

    sprintf(instruction_name, "beq");
    strcpy(register_rs_a, "$0,");
    sprintf(register_rt_a, "%s,", register_rd_a);
    strcpy(register_rd_a, "");
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
    // sprintf(instruction_name, "bge");
    // index = findParameters(line, index, 0);
    // sprintf(register_rs_a, "$%d,", get_register(regist));
    // index = findParameters(line, index, 0);
    // sprintf(register_rt_a, "$%d,", get_register(regist));
    // strcpy(register_rd_a, "");
    // addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void branchGT(char *line, int index) {
    // int index_aux;
    // index_aux = index;

    // sprintf(instruction_name, "addi");
    // index = findParameters(line, index, 0);
    // sprintf(register_rt_a, "$%d,", get_register(regist));
    // strcpy(register_rd_a, "0");
    // strcpy(register_rs_a, "$0,");
    // addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
    // currentLine++;

    // index = index_aux;
    sprintf(instruction_name, "slt");
    index = findParameters(line, index, 0);
    sprintf(register_rs_a, "$%d,", get_register(regist));
    index = findParameters(line, index, 0);
    sprintf(register_rt_a, "$%d,", get_register(regist));
    findParameters(line, index, 1);
    sprintf(register_rd_a, "$%d", get_register(regist));
    addInstruction(instruction_name, register_rt_a, register_rs_a, register_rd_a);
    currentLine++;

    sprintf(instruction_name, "bne");
    strcpy(register_rs_a, "$0,");
    sprintf(register_rt_a, "%s,", register_rd_a);
    strcpy(register_rd_a, "");
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
    // sprintf(instruction_name, "bgt");
    // index = findParameters(line, index, 0);
    // sprintf(register_rs_a, "$%d,", get_register(regist));
    // index = findParameters(line, index, 0);
    // sprintf(register_rt_a, "$%d,", get_register(regist));
    // strcpy(register_rd_a, "");
    // addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void branchLE(char *line, int index) {
    // int index_aux;
    // index_aux = index;

    // sprintf(instruction_name, "addi");
    // index = findParameters(line, index, 0);
    // sprintf(register_rt_a, "$%d,", get_register(regist));
    // strcpy(register_rd_a, "0");
    // strcpy(register_rs_a, "$0,");
    // addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
    // currentLine++;

    // index = index_aux;
    sprintf(instruction_name, "slt");
    index = findParameters(line, index, 0);
    sprintf(register_rs_a, "$%d,", get_register(regist));
    index = findParameters(line, index, 0);
    sprintf(register_rt_a, "$%d,", get_register(regist));
    findParameters(line, index, 1);
    sprintf(register_rd_a, "$%d", get_register(regist));
    addInstruction(instruction_name, register_rt_a, register_rs_a, register_rd_a);
    currentLine++;

    sprintf(instruction_name, "beq");
    strcpy(register_rs_a, "$0,");
    sprintf(register_rt_a, "%s,", register_rd_a);
    strcpy(register_rd_a, "");
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
    // sprintf(instruction_name, "ble");
    // index = findParameters(line, index, 0);
    // sprintf(register_rs_a, "$%d,", get_register(regist));
    // index = findParameters(line, index, 0);
    // sprintf(register_rt_a, "$%d,", get_register(regist));
    // strcpy(register_rd_a, "");
    // addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void branchLT(char *line, int index) {
    // int index_aux;
    // index_aux = index;

    // sprintf(instruction_name, "addi");
    // index = findParameters(line, index, 0);
    // sprintf(register_rt_a, "$%d,", get_register(regist));
    // strcpy(register_rd_a, "0");
    // strcpy(register_rs_a, "$0,");
    // addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
    // currentLine++;

    // index = index_aux;
    sprintf(instruction_name, "slt");
    index = findParameters(line, index, 0);
    sprintf(register_rs_a, "$%d,", get_register(regist));
    index = findParameters(line, index, 0);
    sprintf(register_rt_a, "$%d,", get_register(regist));
    findParameters(line, index, 1);
    sprintf(register_rd_a, "$%d", get_register(regist));
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
    currentLine++;

    sprintf(instruction_name, "bne");
    strcpy(register_rs_a, "$0,");
    sprintf(register_rt_a, "%s,", register_rd_a);
    strcpy(register_rd_a, "");
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
    // sprintf(instruction_name, "blt");
    // index = findParameters(line, index, 0);
    // sprintf(register_rs_a, "$%d,", get_register(regist));
    // index = findParameters(line, index, 0);
    // sprintf(register_rt_a, "$%d,", get_register(regist));
    // strcpy(register_rd_a, "");
    // addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void ret(char *line, int index) {
    sprintf(instruction_name, "jr");
    strcpy(register_rs_a, "$ra");
    strcpy(register_rt_a, "");
    strcpy(register_rd_a, "");
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void add(char *line, int index) {
    sprintf(instruction_name, "add");
    index = findParameters(line, index, 0);
    sprintf(register_rs_a, "$%d,", get_register(regist));
    index = findParameters(line, index, 0);
    sprintf(register_rt_a, "$%d,", get_register(regist));
    findParameters(line, index, 1);
    sprintf(register_rd_a, "$%d", get_register(regist));
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void sub(char *line, int index) {
    sprintf(instruction_name, "sub");
    index = findParameters(line, index, 0);
    sprintf(register_rs_a, "$%d,", get_register(regist));
    index = findParameters(line, index, 0);
    sprintf(register_rt_a, "$%d,", get_register(regist));
    findParameters(line, index, 1);
    sprintf(register_rd_a, "$%d", get_register(regist));
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void div_(char *line, int index) {
    sprintf(instruction_name, "div");
    index = findParameters(line, index, 0);
    sprintf(register_rs_a, "$%d,", get_register(regist));
    index = findParameters(line, index, 0);
    sprintf(register_rt_a, "$%d,", get_register(regist));
    findParameters(line, index, 1);
    sprintf(register_rd_a, "$%d", get_register(regist));
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void mult(char *line, int index) {
    sprintf(instruction_name, "mult");
    index = findParameters(line, index, 0);
    sprintf(register_rs_a, "$%d,", get_register(regist));
    index = findParameters(line, index, 0);
    sprintf(register_rt_a, "$%d,", get_register(regist));
    findParameters(line, index, 1);
    sprintf(register_rd_a, "$%d", get_register(regist));
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void param(char *line, int index) {
    char num[5];
    sprintf(instruction_name, "add");
    index = findParameters(line, index, 0);
    sprintf(register_rs_a, "$%d,", get_register(regist));
    strcpy(register_rt_a, "$0,");

    sprintf(num, "$a%d", contParams);
    sprintf(register_rd_a, "$%d", get_register(num));
    contParams++;

    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void arg(char *line, int index) {
    char num[5];
    sprintf(instruction_name, "sw");
    index = findParameters(line, index, 0);
    if (strcmp(instruction[currentLine - 1].instructionName, "lw") != 0)
        currentArg = 0;
    sprintf(num, "$a%d", currentArg);

    sprintf(register_rs_a, "$%d,", get_register(num));
    currentArg++;

    index = findParameters(line, index, 0);
    sprintf(register_rt_a, "%d", searchMemPos());

    sprintf(register_rd_a, "($0)");
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void alloc(char *line, int index) {
    sprintf(instruction_name, "sw");
    strcpy(register_rs_a, "$0,");
    index = findParameters(line, index, 0);
    sprintf(register_rt_a, "%d", searchMemPos());
    findParameters(line, index, 1);

    strcpy(register_rd_a, "($0)");
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void load_varg(char *line, int index) {
    sprintf(instruction_name, "addi");
    index = findParameters(line, index, 0);
    sprintf(register_rt_a, "$%d,", get_register(regist));
    index = findParameters(line, index, 0);

    sprintf(register_rd_a, "%d,", searchMemPos());
    strcpy(register_rs_a, "$0");
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void jumpMain(char *line, int index) {
    strcpy(instruction_name, "jmain");
    strcpy(register_rs_a, "");
    strcpy(register_rt_a, "");
    strcpy(register_rd_a, "");
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void endMain_assembly(char *line, int index) {
    strcpy(instruction_name, "endmain");
    strcpy(register_rs_a, "");
    strcpy(register_rt_a, "");
    strcpy(register_rd_a, "");
    addInstruction(instruction_name, register_rs_a, register_rt_a, register_rd_a);
}

void searchInstructionName(char *read) {
    char instruc[15];
    int j = 0, i;
    for (i = 1; read[i] != ',' && i < 15; i++) {
        instruc[j] = read[i];
        j++;
    }
    i++;
    instruc[j] = '\0';

    if (strcmp(instruc, "LOAD_CONST") == 0)
        addi(read, i);
    else if (strcmp(instruc, "GOTO") == 0)
        jump(read, i);
    else if (strcmp(instruc, "LABEL") == 0)
        label(read, i);
    else if (strcmp(instruc, "FUNCTION") == 0)
        ffunction(read, i);
    else if (strcmp(instruc, "LOAD") == 0)
        load(read, i);
    else if (strcmp(instruc, "ASSIGN") == 0)
        store(read, i);
    else if (strcmp(instruc, "CALL") == 0)
        call(read, i);
    else if (strcmp(instruc, "CALL_OUT") == 0)
        callOut(read, i);
    else if (strcmp(instruc, "CALL_IN") == 0)
        callIn(read, i);
    else if (strcmp(instruc, "IF") == 0)
        if_conditional(read, i);
    else if (strcmp(instruc, "NEQ") == 0)
        branchNE(read, i);
    else if (strcmp(instruc, "EQ") == 0)
        branchEQ(read, i);
    else if (strcmp(instruc, "GTE") == 0) 
        branchGE(read, i); 
    else if (strcmp(instruc, "GT") == 0)
        branchGT(read, i);
    else if (strcmp(instruc, "LTE") == 0)
        branchLE(read, i);
    else if (strcmp(instruc, "LT") == 0)
        branchLT(read, i);
    else if (strcmp(instruc, "END") == 0)
        currentLine--;
    else if (strcmp(instruc, "RETURN") == 0)
        ret(read, i);
    else if (strcmp(instruc, "PLUS") == 0)
        add(read, i);
    else if (strcmp(instruc, "MINUS") == 0)
        sub(read, i);
    else if (strcmp(instruc, "OVER") == 0)
        div_(read, i);
    else if (strcmp(instruc, "TIMES") == 0)
        mult(read, i);
    else if (strcmp(instruc, "ALLOC") == 0)
        alloc(read, i);
    else if (strcmp(instruc, "ALLOC_VECTOR") == 0)
        alloc(read, i);
    else if (strcmp(instruc, "PARAMETER") == 0)
        arg(read, i);
    else if (strcmp(instruc, "ARGUMENT") == 0)
        param(read, i);
    else if (strcmp(instruc, "LOAD_VARG") == 0)
        load_varg(read, i);
    else if (strcmp(instruc, "LOAD_VECTOR") == 0)
        load_v(read, i);
    else if (strcmp(instruc, "JUMP_MAIN") == 0)
        jumpMain(read, i);
    else if (strcmp(instruc, "END_MAIN") == 0) {
        // currentLine--;
        endMain_assembly(read, i);
    }
    else
        strcpy(instruction[currentLine].instructionName, instruc);
}

void saveAssemblyCode() {
    for (int i = 1; i < currentLine; i++) {
        fprintf(assembly, "%s %s%s%s", instruction[i].instructionName, instruction[i].rs, instruction[i].rt, instruction[i].rd);
        fprintf(assembly, "\n");
    }
}

void labels() {
    char temporary[10], temporary2[10];
    int j;
    for (int i = 0; i < currentLine; i++) {
        if (strcmp(instruction[i].instructionName, "addi") == 0) {
            if (strcmp(instruction[i].rd, "PC") == 0) {
                j = i + 1;
                while (strcmp(instruction[j].instructionName, "jal") != 0)
                    j++;
                sprintf(temporary2, "%d", j);
                strcpy(instruction[i].rd, temporary2);
            }
        }
        else if (strcmp(instruction[i].instructionName, "jump") == 0) {
            if (instruction[i].rs[0] == 'L') {
                for (j = 1; instruction[i].rs[j] != '\0'; j++)
                    temporary[j - 1] = instruction[i].rs[j];
                temporary[j] = '\0';

                sprintf(temporary2, "%d", label_pos[atoi(temporary)]);
                strcpy(instruction[i].rs, temporary2);
            }
        }
        else if (strcmp(instruction[i].instructionName, "jmain") == 0) {
            char temporary[5];
            sprintf(temporary, "%d", mainLine);
            strcpy(instruction[i].rs, temporary);
        }
        // else if (strcmp(instruction[i].instructionName, "bne") == 0 || strcmp(instruction[i].instructionName, "beq") == 0 || strcmp(instruction[i].instructionName, "blt") == 0 || strcmp(instruction[i].instructionName, "bgt") == 0 || strcmp(instruction[i].instructionName, "ble") == 0 || strcmp(instruction[i].instructionName, "bge") == 0) {
        else if (strcmp(instruction[i].instructionName, "bne") == 0 || strcmp(instruction[i].instructionName, "beq") == 0) {
            for (j = 1; instruction[i].rd[j] != '\0'; j++)
                temporary[j - 1] = instruction[i].rd[j];
            temporary[j] = '\0';

            sprintf(temporary2, "%d", label_pos[atoi(temporary)]);
            strcpy(instruction[i].rd, temporary2);
        }
    }
}

void assemblyGen() {
    char read[51];
    strcpy(function, "");
    instruction = (assemblyType *)malloc(sizeof(assemblyType));
    label_pos = (int *)malloc(sizeof(int) * returnLabel() + 1);
    posLabel = (labelType *)malloc(sizeof(labelType));

    while (fgets(read, 50, intermediary) != NULL) {

        while (read[0] != '(')
            fgets(read, 50, intermediary);

        // instruction = (assemblyType *)realloc(instruction, (currentLine + 1) * sizeof(assemblyType));
        instruction = (assemblyType *)realloc(instruction, (currentLine + 2) * sizeof(assemblyType));
        searchInstructionName(read);
        currentLine++;
    }
    labels();
    saveAssemblyCode();

    free(instruction);
    free(label_pos);
    free(posLabel);
}