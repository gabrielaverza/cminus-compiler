#include "binaryCode.h"
#include "globals.h"

void emitBinaryInstructionTypeR(int currentLine, char *opcode, char *rs, char *rt, char *rd, char *shamt, char *funct, char *comment) {
    fprintf(binary, "mem[%d] = {6'b%s, 5'd%s, 5'd%s, 5'd%s, 5'b%s, 6'b%s}; // %s\n", currentLine, opcode, rs, rt, rd, shamt, funct, comment);
}

void emitBinaryInstructionTypeI(int currentLine, char *opcode, char *rs, char *rt, char *immediate, char *comment) {
    fprintf(binary, "mem[%d] = {6'b%s, 5'd%s, 5'd%s, 16'd%s}; // %s\n", currentLine, opcode, rs, rt, immediate, comment);
}

void emitBinaryInstructionTypeJ(int currentLine, char *opcode, char *immediate, char *comment) {
    fprintf(binary, "mem[%d] = {6'b%s, 26'd%s}; // %s\n", currentLine, opcode, immediate, comment);
}