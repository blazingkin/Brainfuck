#include "parse.h"


program_t *parse(FILE *file){
    int input = 0;
    size_t buffer_size = 10;
    size_t program_length = 0;
    control_t *program = calloc(buffer_size, sizeof(control_t));
    while ((input = fgetc(file)) != EOF){
        switch (input){
            case '>':
                program[program_length] = INC_DP;
            break;
            case '<':
                program[program_length] = DEC_DP;
            break;
            case '+':
                program[program_length] = INC;
            break;
            case '-':
                program[program_length] = DEC;
            break;
            case '.':
                program[program_length] = OUTPUT;
            break;
            case ',':
                program[program_length] = INPUT;
            break;
            case '[':
                program[program_length] = JF;
            break;
            case ']':
                program[program_length] = JB;
            break;
            default: continue;
        }
        program_length++;
        if (program_length >= buffer_size){
            buffer_size *= 2;
            program = realloc(program, buffer_size * sizeof(control_t));
        }
    }
    return build_program(program, program_length);
}

program_t *build_program(control_t *program, size_t len){
    program_t *result = calloc(1, sizeof(program_t));
    result->control_code = program;
    result->length = len;
    return result;
}