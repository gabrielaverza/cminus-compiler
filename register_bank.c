#include <string.h>
#include "register_bank.h"

int get_register(char *regAux) {
    if (strcmp(regAux, "$zero") == 0 || strcmp(regAux, "-") == 0 || strcmp(regAux, "0") == 0)
        return $zero;

    else if (strcmp(regAux, "$v0") == 0)
        return $v0;

    else if (strcmp(regAux, "$at") == 0)
        return $at;

    else if (strcmp(regAux, "$v1") == 0)
        return $v1;

    else if (strcmp(regAux, "$a0") == 0)
        return $a0;

    else if (strcmp(regAux, "$a1") == 0)
        return $a1;

    else if (strcmp(regAux, "$a2") == 0)
        return $a2;

    else if (strcmp(regAux, "$a3") == 0)
        return $a3;

    else if (strcmp(regAux, "$t0") == 0)
        return $t0;

    else if (strcmp(regAux, "$t1") == 0)
        return $t1;

    else if (strcmp(regAux, "$t2") == 0)
        return $t2;

    else if (strcmp(regAux, "$t3") == 0)
        return $t3;

    else if (strcmp(regAux, "$t4") == 0)
        return $t4;

    else if (strcmp(regAux, "$t5") == 0)
        return $t5;

    else if (strcmp(regAux, "$t6") == 0)
        return $t6;

    else if (strcmp(regAux, "$t7") == 0)
        return $t7;

    else if (strcmp(regAux, "$t8") == 0)
        return $t8;

    else if (strcmp(regAux, "$t9") == 0)
        return $t9;

    else if (strcmp(regAux, "$t10") == 0)
        return $t10;

    else if (strcmp(regAux, "$t11") == 0)
        return $t11;

    else if (strcmp(regAux, "$t12") == 0)
        return $t12;

    else if (strcmp(regAux, "$t13") == 0)
        return $t13;

    else if (strcmp(regAux, "$t14") == 0)
        return $t14;

    else if (strcmp(regAux, "$t15") == 0)
        return $t15;

    else if (strcmp(regAux, "$t16") == 0)
        return $t16;

    else if (strcmp(regAux, "$t17") == 0)
        return $t17;

    else if (strcmp(regAux, "$t18") == 0)
        return $t18;

    else if (strcmp(regAux, "$t19") == 0)
        return $t19;

    else if (strcmp(regAux, "$sp") == 0)
        return $sp;

    else if (strcmp(regAux, "$gp") == 0)
        return $gp;

    else if (strcmp(regAux, "$fp") == 0)
        return $fp;

    else if (strcmp(regAux, "$ra") == 0)
        return $ra;
}