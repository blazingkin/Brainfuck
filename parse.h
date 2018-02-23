#ifndef PARSE_H
#define PARSE_H 
#include "control.h"

    program_t *parse(FILE *);
    program_t *build_program(control_t *, size_t);
#endif