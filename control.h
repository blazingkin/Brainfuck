#ifndef CONTROL_H
#define CONTROL_H 
#include <stdio.h>
#include <stdlib.h>
typedef enum control_codes {INC_DP, DEC_DP, INC, DEC, OUTPUT, INPUT, JF, JB} control_t;

typedef struct _PROGRAM{
    control_t *control_code;
    size_t length;
} program_t;

#include "cells.h"
#include "parse.h"

int main(int, char **);




#endif