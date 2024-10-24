#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


typedef struct Cell {
    int x, y;
    short NorthWall, SouthWall, WestWall, EastWall, hasBeenExplored;
    int visited;
    int FloodFillValue;
    int reverseFloodFillCost;
    struct Cell *prevVisitedCell;

} Cell;

Cell *createCell(int x, int y) {
    Cell *newCell = (Cell *) malloc(sizeof(Cell));
    newCell->x = x;
    newCell->y = y;
    newCell->NorthWall = FALSE;
    newCell->SouthWall = FALSE;
    newCell->WestWall = FALSE;
    newCell->EastWall = FALSE;
    newCell->hasBeenExplored = FALSE;
    newCell->visited = FALSE;
    newCell->FloodFillValue = 0;
    newCell->reverseFloodFillCost = 0;
    newCell->prevVisitedCell = NULL;
    return newCell;
}

typedef struct Stack {
    int size;
    Cell *cells[16*16];
} Stack;

Stack *createStack() {
    Stack *newStack = (Stack *) malloc(sizeof(Stack));
    newStack->size = 0;
	return newStack;
}

void push(Stack* s, Cell *cell) {
    s->cells[s->size] = cell;
    s->size++; 
}

Cell *pop(Stack *s) {
    if (s->size == 0) {
        return NULL;
    }
    s->size--;
    return s->cells[s->size];
}

void *deleteCell(Stack *s, Cell *cell) {
    for(int i = 0; i < s->size; i++){
        if(s->cells[i] == cell){
            for(int j = i; j < s->size - 1; j++){
                s->cells[j] = s->cells[j + 1];
            }
            s->size--;
        }
    }
}

Cell *top(Stack *s) {
    if (s->size == 0) {
        return NULL;
    }
    return s->cells[s->size - 1];
}

int isEmpty(Stack *s) {
    return (s->size == 0) ? TRUE : FALSE;
}

#endif
