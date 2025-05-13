/****************************************************/
/* File: binary.c                                   */
/* The binary code generator implementation         */
/* for the C- compiler                              */
/* Gabriela Carregari Verza                         */
/****************************************************/

#include "globals.h"
#include "assembly.h"
#include <string.h>
#include "binaryCode.h"

static int currentLine = 0;

char reg[10];
int register_(char *line, int index) {
    int j = 0, i;
    for (i = index + 1; i < 40 && line[i] != ',' && line[i] != '\n' && line[i] != ')'; i++) {
        reg[j] = line[i];
        j++;
    }
    reg[j] = '\0';

    return i + 1;
}

int immediate(char *line, int index) {
    int j = 0, i;
    for (i = index; i < 40 && line[i] != ',' && line[i] != '\n' && line[i] != '('; i++) { // get imm
        reg[j] = line[i];
        j++;
    }
    reg[j] = '\0';

    return i + 1;
}

// auxiliar vectors
// char opcode[6];
char opcode[7]; // 6 + \0
char register_rs[5];
char register_rt[5];
char register_rd[5];
char var_imm[26];
// char shamt[5]; // 6 + \0
char shamt[6];
char funct[5];
char comment[10];

void addi_bin(char *read, int i) {
    strcpy(opcode, "000001");
    i = register_(read, i);
    strcpy(register_rs, reg);
    i = register_(read, i);
    strcpy(register_rt, reg);
    i = immediate(read, i);
    strcpy(var_imm, reg);
    strcpy(comment, "addi");
    emitBinaryInstructionTypeI(currentLine, opcode, register_rs, register_rt, var_imm, comment);
}

void subi_bin(char *read, int i) {
    strcpy(opcode, "000010");
    i = register_(read, i);
    strcpy(register_rs, reg);
    i = register_(read, i);
    strcpy(register_rt, reg);
    i = immediate(read, i);
    strcpy(var_imm, reg);
    strcpy(comment, "subi");
    emitBinaryInstructionTypeI(currentLine, opcode, register_rs, register_rt, var_imm, comment);
}

void multi_bin(char *read, int i) {
    strcpy(opcode, "000011");
    i = register_(read, i);
    strcpy(register_rs, reg);
    i = register_(read, i);
    strcpy(register_rt, reg);
    i = immediate(read, i);
    strcpy(var_imm, reg);
    strcpy(comment, "multi");
    emitBinaryInstructionTypeI(currentLine, opcode, register_rs, register_rt, var_imm, comment);
}

void divi_bin(char *read, int i) {
    strcpy(opcode, "000100");
    i = register_(read, i);
    strcpy(register_rs, reg);
    i = register_(read, i);
    strcpy(register_rt, reg);
    i = immediate(read, i);
    strcpy(var_imm, reg);
    strcpy(comment, "divi");
    emitBinaryInstructionTypeI(currentLine, opcode, register_rs, register_rt, var_imm, comment);
}

void lw_bin(char *read, int i) {
    strcpy(opcode, "000111");
    i = register_(read, i);
    strcpy(register_rt, reg);
    i = immediate(read, i);
    strcpy(var_imm, reg);
    i = register_(read, i);
    strcpy(register_rs, reg);
    strcpy(comment, "lw");
    emitBinaryInstructionTypeI(currentLine, opcode, register_rs, register_rt, var_imm, comment);
}

void sw_bin(char *read, int i) {
    strcpy(opcode, "001000");
    i = register_(read, i);
    strcpy(register_rt, reg);
    i = immediate(read, i);
    strcpy(var_imm, reg);
    i = register_(read, i);
    strcpy(register_rs, reg);
    strcpy(comment, "sw");
    emitBinaryInstructionTypeI(currentLine, opcode, register_rs, register_rt, var_imm, comment);
}

void beq_bin(char *read, int i) {
    strcpy(opcode, "001001");
    i = register_(read, i);
    strcpy(register_rs, reg);
    i = register_(read, i);
    strcpy(register_rt, reg);
    i = immediate(read, i);
    sprintf(var_imm, "%d", atoi(reg) - 1);
    strcpy(comment, "beq");
    emitBinaryInstructionTypeI(currentLine, opcode, register_rs, register_rt, var_imm, comment);
}

void bne_bin(char *read, int i) {
    strcpy(opcode, "001010");
    i = register_(read, i);
    strcpy(register_rs, reg);
    i = register_(read, i);
    strcpy(register_rt, reg);
    i = immediate(read, i);
    sprintf(var_imm, "%d", atoi(reg) - 1);
    strcpy(comment, "bne");
    emitBinaryInstructionTypeI(currentLine, opcode, register_rs, register_rt, var_imm, comment);
}

// void bge_bin(char *read, int i) {
//     strcpy(opcode, "010001");
//     i = register_(read, i);
//     strcpy(register_rs, reg);
//     i = register_(read, i);
//     strcpy(register_rt, reg);
//     i = immediate(read, i);
//     sprintf(var_imm, "%d", atoi(reg) - 1);
//     strcpy(comment, "bge");
//     emitBinaryInstructionTypeI(currentLine, opcode, register_rs, register_rt, var_imm, comment);
// }

// void bgt_bin(char *read, int i) {
//     strcpy(opcode, "010010");
//     i = register_(read, i);
//     strcpy(register_rs, reg);
//     i = register_(read, i);
//     strcpy(register_rt, reg);
//     i = immediate(read, i);
//     sprintf(var_imm, "%d", atoi(reg) - 1);
//     strcpy(comment, "bgt");
//     emitBinaryInstructionTypeI(currentLine, opcode, register_rs, register_rt, var_imm, comment);
// }

// void ble_bin(char *read, int i) {
//     strcpy(opcode, "010011");
//     i = register_(read, i);
//     strcpy(register_rs, reg);
//     i = register_(read, i);
//     strcpy(register_rt, reg);
//     i = immediate(read, i);
//     sprintf(var_imm, "%d", atoi(reg) - 1);
//     strcpy(comment, "ble");
//     emitBinaryInstructionTypeI(currentLine, opcode, register_rs, register_rt, var_imm, comment);
// }

// void blt_bin(char *read, int i) {
//     strcpy(opcode, "010100");
//     i = register_(read, i);
//     strcpy(register_rs, reg);
//     i = register_(read, i);
//     strcpy(register_rt, reg);
//     i = immediate(read, i);
//     sprintf(var_imm, "%d", atoi(reg) - 1);
//     strcpy(comment, "blt");
//     emitBinaryInstructionTypeI(currentLine, opcode, register_rs, register_rt, var_imm, comment);
// }

void slt_bin(char *read, int i) {
    strcpy(opcode, "001011");
    i = register_(read, i);
    strcpy(register_rs, reg);
    i = register_(read, i);
    strcpy(register_rt, reg);
    i = register_(read, i);
    strcpy(register_rd, reg);
    strcpy(shamt, "00000");
    strcpy(funct, "000000");
    strcpy(comment, "slt");
    emitBinaryInstructionTypeR(currentLine, opcode, register_rs, register_rt, register_rd, shamt, funct, comment);
}

// void slti_bin(char *read, int i) {
//     strcpy(opcode, "001100");
//     i = register_(read, i);
//     strcpy(register_rs, reg);
//     i = immediate(read, i);
//     sprintf(var_imm, "%d", atoi(reg) - 1);
//     i = register_(read, i);
//     strcpy(register_rt, reg);
//     strcpy(comment, "slti");
//     emitBinaryInstructionTypeI(currentLine, opcode, register_rs, register_rt, var_imm, comment);
// }

void jump_bin(char *read, int i) {
    strcpy(opcode, "001101");
    i = immediate(read, i);
    sprintf(var_imm, "%d", atoi(reg) - 1);
    strcpy(comment, "jump");
    emitBinaryInstructionTypeJ(currentLine, opcode, var_imm, comment);
}

void jal_bin(char *read, int i) {
    strcpy(opcode, "001110");
    i = immediate(read, i);
    sprintf(var_imm, "%d", atoi(reg) - 1);
    strcpy(comment, "jal");
    emitBinaryInstructionTypeJ(currentLine, opcode, var_imm, comment);
}

void jr_bin(char *read, int i) {
    strcpy(opcode, "000000");
    strcpy(register_rs, "31");
    strcpy(register_rt, "0");
    strcpy(register_rd, "0");
    strcpy(shamt, "00000");
    strcpy(funct, "001000");
    strcpy(comment, "jr");
    emitBinaryInstructionTypeR(currentLine, opcode, register_rs, register_rt, register_rd, shamt, funct, comment);
}

void add_bin(char *read, int i) {
    strcpy(opcode, "000000");
    i = register_(read, i);
    strcpy(register_rs, reg);
    i = register_(read, i);
    strcpy(register_rt, reg);
    i = register_(read, i);
    strcpy(register_rd, reg);
    strcpy(shamt, "00000");
    strcpy(funct, "000001");
    strcpy(comment, "add");
    emitBinaryInstructionTypeR(currentLine, opcode, register_rs, register_rt, register_rd, shamt, funct, comment);
}

void sub_bin(char *read, int i) {
    strcpy(opcode, "000000");
    i = register_(read, i);
    strcpy(register_rs, reg);
    i = register_(read, i);
    strcpy(register_rt, reg);
    i = register_(read, i);
    strcpy(register_rd, reg);
    strcpy(shamt, "00000");
    strcpy(funct, "000010");
    strcpy(comment, "sub");
    emitBinaryInstructionTypeR(currentLine, opcode, register_rs, register_rt, register_rd, shamt, funct, comment);
}

void mult_bin(char *read, int i) {
    strcpy(opcode, "000000");
    i = register_(read, i);
    strcpy(register_rs, reg);
    i = register_(read, i);
    strcpy(register_rt, reg);
    i = register_(read, i);
    strcpy(register_rd, reg);
    strcpy(shamt, "00000");
    strcpy(funct, "000011");
    strcpy(comment, "mult");
    emitBinaryInstructionTypeR(currentLine, opcode, register_rs, register_rt, register_rd, shamt, funct, comment);
}

void div_bin(char *read, int i) {
    strcpy(opcode, "000000");
    i = register_(read, i);
    strcpy(register_rs, reg);
    i = register_(read, i);
    strcpy(register_rt, reg);
    i = register_(read, i);
    strcpy(register_rd, reg);
    strcpy(shamt, "00000");
    strcpy(funct, "000100");
    strcpy(comment, "div");
    emitBinaryInstructionTypeR(currentLine, opcode, register_rs, register_rt, register_rd, shamt, funct, comment);
}

void and_bin(char *read, int i) {
    strcpy(opcode, "000000");
    i = register_(read, i);
    strcpy(register_rs, reg);
    i = register_(read, i);
    strcpy(register_rt, reg);
    i = register_(read, i);
    strcpy(register_rd, reg);
    strcpy(shamt, "00000");
    strcpy(funct, "000101");
    strcpy(comment, "and");
    emitBinaryInstructionTypeR(currentLine, opcode, register_rs, register_rt, register_rd, shamt, funct, comment);
}

// void or_bin(char *read, int i) {
//     strcpy(opcode, "000000");
//     i = register_(read, i);
//     strcpy(register_rs, reg);
//     i = register_(read, i);
//     strcpy(register_rt, reg);
//     i = register_(read, i);
//     strcpy(register_rd, reg);
//     strcpy(shamt, "00000");
//     strcpy(funct, "000110");
//     strcpy(comment, "or");
//     emitBinaryInstructionTypeR(currentLine, opcode, register_rs, register_rt, register_rd, shamt, funct, comment);
// }

// void nor_bin(char *read, int i) {
//     strcpy(opcode, "000000");
//     i = register_(read, i);
//     strcpy(register_rs, reg);
//     i = register_(read, i);
//     strcpy(register_rt, reg);
//     i = register_(read, i);
//     strcpy(register_rd, reg);
//     strcpy(shamt, "00000");
//     strcpy(funct, "000111");
//     strcpy(comment, "nor");
//     emitBinaryInstructionTypeR(currentLine, opcode, register_rs, register_rt, register_rd, shamt, funct, comment);
// }

void input_bin(char *read, int i) {
    strcpy(opcode, "000101");
    strcpy(register_rs, "0");
    strcpy(register_rt, "0");
    i = register_(read, i);
    strcpy(register_rd, reg);
    strcpy(shamt, "00000");
    strcpy(funct, "000000");
    strcpy(comment, "input");
    emitBinaryInstructionTypeR(currentLine, opcode, register_rs, register_rt, register_rd, shamt, funct, comment);
}

void output_bin(char *read, int i) {
    strcpy(opcode, "000110");
    i = register_(read, i);
    strcpy(register_rs, reg);
    strcpy(register_rt, register_rs);
    strcpy(var_imm, "0");
    strcpy(comment, "output");
    emitBinaryInstructionTypeI(currentLine, opcode, register_rs, register_rt, var_imm, comment);
}

void jmain(char *read, int i) {
    // strcpy(opcode, "001111");
    strcpy(opcode, "001101");
    i = immediate(read, i);
    sprintf(var_imm, "%d", atoi(reg) - 1);
    strcpy(comment, "jumpMain");
    emitBinaryInstructionTypeJ(currentLine, opcode, var_imm, comment);
}

void endMain(char *read, int i) {
    strcpy(opcode, "010000");
    sprintf(register_rs, "0");
    sprintf(register_rt, "0");
    strcpy(var_imm, "0");
    strcpy(comment, "endMain");
    emitBinaryInstructionTypeI(currentLine, opcode, register_rs, register_rt, var_imm, comment);
}

void instructionBin(char *read) {
    char instruction[15];
    int j = 0, i;

    for (i = 0; read[i] != ' ' && i < 15; i++) {
        instruction[j] = read[i];
        j++;
    }

    i++;

    instruction[j] = '\0';

    if (strcmp(instruction, "add") == 0) {
        add_bin(read, i);
    }
    if (strcmp(instruction, "addi") == 0) {
        addi_bin(read, i);
    }
    else if (strcmp(instruction, "sub") == 0) {
        sub_bin(read, i);
    }
    else if (strcmp(instruction, "subi") == 0) {
        subi_bin(read, i);
    }
    else if (strcmp(instruction, "mult") == 0) {
        mult_bin(read, i);
    }
    else if (strcmp(instruction, "multi") == 0) {
        multi_bin(read, i);
    }
    else if (strcmp(instruction, "div") == 0) {
        div_bin(read, i);
    }
    else if (strcmp(instruction, "divi") == 0) {
        divi_bin(read, i);
    }
    else if (strcmp(instruction, "and") == 0) {
        and_bin(read, i);
    }
    // else if (strcmp(instruction, "or") == 0) {
    //     or_bin(read, i);
    // }
    // else if (strcmp(instruction, "nor") == 0) {
    //     div_bin(read, i);
    // }
    else if (strcmp(instruction, "lw") == 0) {
        lw_bin(read, i);
    }
    else if (strcmp(instruction, "sw") == 0) {
        sw_bin(read, i);
    }
    else if (strcmp(instruction, "beq") == 0) {
        beq_bin(read, i);
    }
    else if (strcmp(instruction, "bne") == 0) {
        bne_bin(read, i);
    }
    // else if (strcmp(instruction, "bge") == 0) {
    //     bge_bin(read, i);
    // }
    // else if (strcmp(instruction, "bgt") == 0) {
    //     bgt_bin(read, i);
    // }
    // else if (strcmp(instruction, "ble") == 0) {
    //     ble_bin(read, i);
    // }
    // else if (strcmp(instruction, "blt") == 0) {
    //     blt_bin(read, i);
    // }
    else if (strcmp(instruction, "slt") == 0) {
        slt_bin(read, i);
    }
    // else if (strcmp(instruction, "slti") == 0) {
    //     slti_bin(read, i);
    // }
    else if (strcmp(instruction, "sw") == 0) {
        sw_bin(read, i);
    }
    else if (strcmp(instruction, "jump") == 0) {
        jump_bin(read, i);
    }
    else if (strcmp(instruction, "jal") == 0) {
        jal_bin(read, i);
    }
    else if (strcmp(instruction, "jr") == 0) {
        jr_bin(read, i);
    }
    else if (strcmp(instruction, "jmain") == 0) {
        jmain(read, i);
    }
    else if (strcmp(instruction, "endmain") == 0) {
        endMain(read, i);
    }
    else if (strcmp(instruction, "input") == 0) {
        input_bin(read, i);
    }
    else if (strcmp(instruction, "output") == 0) {
        output_bin(read, i);
    }
}

void binaryGen() {
    char read[51];

    while (fgets(read, 50, assembly) != NULL) {
        instructionBin(read);
        currentLine++;
    }
}