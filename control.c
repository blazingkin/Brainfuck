#include "control.h"

void run_program(program_t *program){
    size_t data_pointer = 0;
    size_t program_index = 0;
    int temporary = 0; 
    while ((program_index >= 0 && program_index < program->length)){
        switch (program->control_code[program_index]){
            case INC_DP:
                data_pointer++;
            break;
            case DEC_DP:
                data_pointer--;
            break;
            case INC:
                set_data(data_pointer, get_data(data_pointer) + 1);
            break;
            case DEC:
                set_data(data_pointer, get_data(data_pointer) - 1);
            break;
            case OUTPUT:
                printf("%c", get_data(data_pointer));
            break;
            case INPUT:
                scanf("%c", &temporary);
                set_data(data_pointer, temporary);
            break;
            case JF:
                if (get_data(data_pointer) == 0){
                    temporary = 0;
                    program_index++;
                    while (program->control_code[program_index] != JB || temporary != 0){
                        if (program->control_code[program_index] == JF){
                            temporary++;
                        }else if (program->control_code[program_index] == JB){
                            temporary--;
                        }
                        program_index++;
                    }
                }
            break;
            case JB:
                if (get_data(data_pointer) != 0){
                    temporary = 0;
                    program_index--;
                    while (program->control_code[program_index] != JF || temporary != 0){
                        if (program->control_code[program_index] == JB){
                            temporary++;
                        }else if (program->control_code[program_index] == JF){
                            temporary--;
                        }
                        program_index--;
                    }
                }
            break;
        }
        program_index++;
    }
}


int main(int argc, char **argv){
    FILE *input = NULL;
    program_t *program = NULL;
    if (argc != 2){
        fprintf(stderr, "usage: ./bf file\n");
        exit(1);
    }
    input = fopen(argv[1], "r");
    if (input == NULL){
        perror("Could not open file:\n");
        exit(2);
    }   
    program = parse(input);
    run_program(program);
    fclose(input);
    return 0;
}