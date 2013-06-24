/*
 *  
 *
 *  Created by Radhika Garg on 14/03/12.
 *  Updated by Rafael Ballester on 10/01/13.
 *  Copyright 2013 University of Zurich. All rights reserved.
 *
 */

#include "matrix_subtraction.h"

#include <iostream>
int main()
{
	int **r, **p , **q,row1,row2,col1,col2;
	std::cout << "Matrix Subtraction Program: \n";
	std::cout << "Enter the number of rows for the first matrix: ";
	std::cin >> row1;
	std::cout << "Enter the number of columns for the first matrix: ";
	std::cin >> col1;
	std::cout << "Enter the number of rows for the second matrix: ";
	std::cin >> row2;
	std::cout << "Enter the number of columns for the second matrix: ";
	std::cin >> col2;
	if (col1 != col2 || row1 != row2) {
		std::cout << "Subtraction not possible (size mismatch)";
		return 0;
	}
	initialiseMemory(p, row1, col1);
	initialiseMemory(q, row2, col2);
	p[0][0] = 3;
	fill(p, row1, col1);
	fill(q, row2, col2);
	r = subtractMatrices(p, q, row1, col1);
	std::cout << "First matrix: "<<std::endl;
	display(p, row1, col1);
	std::cout << "Second matrix: " << std::endl;
	display(q, row2, col2);
	std::cout << "Subtraction result: " << std::endl;
	display(r, row1, col2);
	deallocateMemory(p, row1, col1);
	deallocateMemory(q, row2, col2);
	deallocateMemory(r, row1, col2);
	std::cout << "Deallocation completed." << std::endl;
	std::cout << "Program finished." << std::endl;
}

// Task 1)
void initialiseMemory(int **&x, int row, int col)
{

}

void fill(int **&x, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::cout << "Enter element (" << i << "," << j << "): ";
			std::cin >> x[i][j];
			std::cerr << "We did it " << std::endl;
		}
	}
}

// Task 2)
int **subtractMatrices(int **x, int **y, int row, int col)
{

}

void display(int **val, int x, int y)
{
	for (int i=0; i<x; i++)
	{  
		for (int j=0; j<y; j++)
			std::cout << val[i][j] << " ";
		std::cout << std::endl;
	}
}   

// Task 3)
void deallocateMemory(int **&val, int x, int y)
{

}
