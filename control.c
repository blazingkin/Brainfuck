#include "control.h"

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
    fclose(input);

    return 0;
}