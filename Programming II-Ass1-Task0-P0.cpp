// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 0
// Program: CS213-2018-A1-T1-P0
// Purpose: Apply basic arithmetic operations on Matrices
// Author1: Mostafa Omar Mahmoud - 20170292
// Author2: Ahmed Mohamed Hanafy - 20170357
// Date:    4 September 2018
// Version: 1.0

#include <iostream>
#include <cassert>
using namespace std;

struct matrix
{
	int** data;
	int row = 0, col = 0;
};

void createMatrix(int row, int col, int num[], matrix& mat); // deh hanms7ha beta3et el doctor
void allocateMatrix(matrix &mat, int row, int col); // Allocate memory for matrix

ostream& operator<<(ostream &out, matrix mat); // Print matrix

matrix operator+(matrix mat1, matrix mat2); // Add 2 matrices if both of the same dimensions
matrix operator-(matrix mat1, matrix mat2); // Subtract 2 matrices if both of the same dimensions
matrix operator*(matrix mat1, matrix mat2); // Multiply 2 matrices if number of columns in mat1 is equal to number of rows in mat2
matrix operator+(matrix mat1, int scalar);  // Add a scalar
matrix operator-(matrix mat1, int scalar);  // Subtract a scalar
matrix operator*(matrix mat1, int scalar);  // Multiple by scalar

bool operator==(matrix mat1, matrix mat2);
bool operator!=(matrix mat1, matrix mat2);

int main()
{
	int data1[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int data2[] = { 13, 233, 3, 4, 5, 6 };
	int data3[] = { 10, 100, 10, 100, 10, 100, 10, 100 };

	matrix mat1, mat2, mat3;
	createMatrix(4, 2, data1, mat1);
	createMatrix(2, 3, data2, mat2);
	createMatrix(4, 2, data3, mat3);


	return 0;
}

// Takes a reference to matrix and 2 integers.
// Allocates memory for matrix in heap using double pointers
void allocateMatrix(matrix &mat, int row, int col)
{
	mat.row = row;
	mat.col = col;
	mat.data = new int*[row];
	for (int i = 0; i < row; ++i)
		mat.data[i] = new int[col];
}

//Print matrix to an output stream
ostream& operator<<(ostream &out, matrix mat)
{
	for (int i = 0; i < mat.row; ++i)
	{
		for (int j = 0; j < mat.col; ++j)
		{
			out << mat.data[i][j] << ' ';
		}
		out << '\n';
	}
	return out;
}

// Add 2 matrices if both of the same dimensions
matrix operator+(matrix mat1, matrix mat2)
{
	// Error handling
	assert((mat1.row == mat2.row) && (mat1.col == mat2.col));

	matrix resultMat;
	allocateMatrix(resultMat, mat1.row, mat1.col);

	for (int i = 0; i < resultMat.row; ++i)
	{
		for (int j = 0; j < resultMat.col; ++j)
		{
			resultMat.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
		}
	}

	return resultMat;
}

// Subtract 2 matrices if both of the same dimensions
matrix operator-(matrix mat1, matrix mat2)
{
	// Error handling
	assert((mat1.row == mat2.row) && (mat1.col == mat2.col));

	matrix resultMat;
	allocateMatrix(resultMat, mat1.row, mat1.col);

	for (int i = 0; i < resultMat.row; ++i)
	{
		for (int j = 0; j < resultMat.col; ++j)
		{
			resultMat.data[i][j] = mat1.data[i][j] - mat2.data[i][j];
		}
	}

	return resultMat;
}

// Multiply 2 matrices if possible
matrix operator*(matrix mat1, matrix mat2)
{
	//Error handling
	assert(mat1.col == mat2.row);

	matrix resultMat;
	allocateMatrix(resultMat, mat1.row, mat2.col);

	for (int i = 0; i < resultMat.row; ++i)
	{
		for (int j = 0; j < resultMat.col; ++j)
		{
			for (int k = 0; k < mat1.col; ++k)
			{
				if (k == 0) // resultMat initialized with garbage value handling
					resultMat.data[i][j] = mat1.data[i][k] * mat2.data[k][j];
				else
					resultMat.data[i][j] += mat1.data[i][k] * mat2.data[k][j];
			}
		}
	}

	return resultMat;
}

// Add a scalar to matrix
matrix operator+(matrix mat1, int scalar)
{
	matrix resultMat;
	allocateMatrix(resultMat, mat1.row, mat1.col);

	for (int i = 0; i < resultMat.row; ++i)
	{
		for (int j = 0; j < resultMat.col; ++j)
		{
			resultMat.data[i][j] = mat1.data[i][j] + scalar;
		}
	}

	return resultMat;
}

// Subtract a scalar to matrix
matrix operator-(matrix mat1, int scalar)
{
	matrix resultMat;
	allocateMatrix(resultMat, mat1.row, mat1.col);

	for (int i = 0; i < resultMat.row; ++i)
	{
		for (int j = 0; j < resultMat.col; ++j)
		{
			resultMat.data[i][j] = mat1.data[i][j] - scalar;
		}
	}

	return resultMat;
}

// Multiply a scalar to matrix
matrix operator*(matrix mat1, int scalar)
{
	matrix resultMat;
	allocateMatrix(resultMat, mat1.row, mat1.col);

	for (int i = 0; i < resultMat.row; ++i)
	{
		for (int j = 0; j < resultMat.col; ++j)
		{
			resultMat.data[i][j] = mat1.data[i][j] * scalar;
		}
	}

	return resultMat;
}

bool operator==(matrix mat1, matrix mat2)
{
	if (mat1.row != mat2.row || mat1.col != mat2.col)
		return false;
	for (int i = 0; i < mat1.row;++i)
	{
		for (int j = 0; j < mat1.col; ++j)
		{
			if (mat1.data[i][j] != mat2.data[i][j])
				return false;
		}
	}
	return true;
}

bool operator!=(matrix mat1, matrix mat2)
{
	return !(mat1 == mat2);
}

void createMatrix(int row, int col, int num[], matrix& mat)
{
	mat.row = row;
	mat.col = col;
	mat.data = new int*[row];

	for (int i = 0; i < row; i++)
		mat.data[i] = new int[col];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			mat.data[i][j] = num[i * col + j];
}
