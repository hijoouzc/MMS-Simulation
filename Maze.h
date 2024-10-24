#include "API.h"
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

#define MAZE_SIZE 16


typedef struct Maze {
    Cell* map[MAZE_SIZE][MAZE_SIZE];
} Maze;

// create maze 16x16
Maze *createMaze() {
    Maze *newMaze = (Maze *) malloc(sizeof(Maze)); 

    int halfsize = MAZE_SIZE / 2;

    for (int i = 0; i < MAZE_SIZE; i++) {
            for (int j = 0; j < MAZE_SIZE; j++) {
                newMaze->map[i][j] = createCell(i, j);

                int minX = (abs(i - halfsize) < abs(i - (halfsize - 1))) ? abs(i - halfsize) : abs(i - (halfsize - 1));
                int minY = (abs(j - halfsize) < abs(j - (halfsize - 1))) ? abs(j - halfsize) : abs(j - (halfsize - 1));
                int value = minX + minY;
                newMaze->map[i][j]->FloodFillValue = value;
                API_setNumber(i, j, value);
                // newMaze->map[i][j]->reverseFloodFillCost = value;
            }
        }
    newMaze->map[0][0]->SouthWall = TRUE;
    return newMaze;
}

void printMAZE(Maze *maze) {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            API_setNumber(i, j, maze->map[i][j]->FloodFillValue);
        }
    }
}

void deleteMaze(Maze *maze) {
    if (maze != NULL) {
        for (int i = 0; i < MAZE_SIZE; i++) {
            for (int j = 0; j < MAZE_SIZE; j++) {
                free(maze->map[i][j]);
            }
        }
        free(maze);
    }
}





