#include "cells.h"

static int *memory = NULL;
static size_t memory_size = 0;

int get_data(size_t location){
    int i;
    if (location >= memory_size){
        memory = realloc(memory, (location + 10) * sizeof(int));
        for (i = memory_size; i < location + 9; i++){
            memory[i] = 0;
        }
        memory_size = location + 9;
    }
    return memory[location];
}

void set_data(size_t location, int data){
        int i;
    if (location >= memory_size){
        memory = realloc(memory, (location + 10) * sizeof(int));
        for (i = memory_size; i < location + 9; i++){
            memory[i] = 0;
        }
        memory_size = location + 9;
    }
    memory[location] = data;
}