/*
 *  matrix_subtraction.h
 *  
 *
 *  Created by Radhika Garg on 14/03/12.
 *  Copyright 2012 University of Zurich. All rights reserved.
 *
 */

void initialiseMemory(int **&x, int row, int col);
void fill(int **&x, int row, int col);
int **subtractMatrices(int **x, int **y, int row, int col);
void deallocateMemory(int **&val, int x, int y);
void display(int **val, int x, int y);
