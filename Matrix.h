/*
 * Author 1: Mostafa Omar Mahmoud 20170292
 * Date: 25 Oct. 2018
 * Version: 1.0
 */

/*
 * TODO:
 * Test scalar + mat and mat + scalar
 * Test mat + scalar1 + scalar2 + scalar3 ..
 * Implementation of the operators defined
 * maybe setRow, setCol, getRow, getCol
 */

/*
 * Mozakra:
 * Implementation 7efz
 *
 * Questions:
 * why didn't cin and cout work without taking matrix by reference?
 * Is taking matrix by value slow? Doesn't it only contain  a pointer? or array of pointers?
 */

#ifndef _MATRIX_H
#define _MATRIX_H

#include <iostream>
using namespace std;
/*
 * Class : Matrix
 *
 * a Class that applies basic arithmetic operations on matrices.
 * Data is represented in a 2D array using double pointers
 * Only integer values are allowed
 */

class Matrix
{
private:
	int** data;
	int row, col;
public:
	/*
	 * Constructor
	 * --------------------------
	 * Can take number of rows and columns for matrix
	 * Allocates memory in heap with the given dimensions
	 * Default is 0 if input is not specified
	 */
	Matrix(int row = 0, int col = 0);

	/*
	 * Copy Constructor
	 * -------------------
	 * Takes another matrix and makes a deep copy of it
	 */
	Matrix(const Matrix &mat);

	/*
	 * Operator =
	 * Usage: mat1 = mat2;
	 * -------------------------
	 * Makes a deep copy of mat2 in mat1
	 * Returns a new matrix with the contents of mat2
	 * -------------------------
	 * Aborts if (mat1.row != mat2.row || mat1.col != mat2.col)
	 */
	Matrix operator=(const Matrix mat);

	/*
	 * Method getCell
	 * Usage : int x = getCell(i,j);
	 * ---------------------------------
	 * Returns an integer which is the content of the cell (i, j)
	 * i, j are 0-based
	 * ---------------------------------
	 * Aborts if (i,j) is out of the matrix dimensions
	 */
	int getCell(int i, int j);

	/*
	 * Method: setCell
	 * Usage : setCell(i, j, val);
	 * ------------------------------
	 * Void return.
	 * Sets the content of cell (i, j) with value (val)
	 * i, j are 0-based
	 * ------------------------------
	 * Aborts if (i, j) is out of matrix dimensions
	 */
	void setCell(int i, int j, int val);

	/*
	 * Operator +
	 * Usage : mat1 + mat2
	 * Can have multiple additions in one line : mat1 + mat2 + ...
	 * ------------------------------------
	 * Returns a new matrix  which is the result of the addition of the 2 matrices
	 * ------------------------------------
	 *	Aborts if (mat1.row != mat2.row || mat1.col != mat2.col)
	 */
	Matrix operator+(Matrix mat);

	/*
	 * Operator -
	 * Usage : mat1 - mat2
	 * Can have multiple subtractions in one line : mat1 - mat2 - ...
	 * ------------------------------------
	 * Returns a new matrix  which is the result of the subtraction of the 2 matrices
	 * ------------------------------------
	 *	Aborts if (mat1.row != mat2.row || mat1.col != mat2.col)
	 */
	Matrix operator-(Matrix mat);

	/*
	 * Operator *
	 * Usage : mat1 * mat2
	 * Can have multiple additions in one line : mat1 * mat2 * ...
	 * ------------------------------------
	 * Returns a new matrix  which is the result of the multiplications of the 2 matrices with dimensions
	 * 	mat1.col * mat2.row
	 * ------------------------------------
	 *	Aborts if (mat1.row != mat2.col)
	 */
	Matrix operator*(Matrix mat);

	/*
	 * Operator +
	 * Usage : mat + scalar
	 * Can have multiple additions in one line : mat + scalar1 + scalar2 ...
	 * ------------------------------------
	 * Returns a new matrix  which is the result of the addition of the matrix and the scalar
	 */
	Matrix operator+(int scalar);

	/*
	 * Operator -
	 * Usage : mat - scalar
	 * Can have multiple subtractions in one line : mat - scalar1 - scalar2 ...
	 * ------------------------------------
	 * Returns a new matrix  which is the result of the subtraction of the matrix and the scalar
	 */
	Matrix operator-(int scalar);

	/*
	 * Operator *
	 * Usage : mat * scalar
	 * Can have multiple additions in one line : mat * scalar1 * scalar2 ...
	 * ------------------------------------
	 * Returns a new matrix  which is the result of the multiplication of the matrix and the scalar
	 */
	Matrix operator*(int scalar);

	/*
	 * Operator ==
	 * Usage : (mat1 == mat2)
	 * ------------------------
	 * Returns boolean true if mat1 is equal to mat2;
	 */
	Matrix operator== (Matrix &mat);

	/*
	 * Operator ==
	 * Usage : (mat1 == mat2)
	 * ------------------------
	 * Returns boolean true if mat1 is equal to mat2;
	 */
	Matrix operator!= (Matrix &mat);

	/*
	 * Method : checkDimensions
	 * Usage : bool b = checkDimensions(i, j)
	 * ---------------------------------------
	 * Returns false if i or j is out of matrix dimensions
	 */
	bool checkDimensions(int i, int j);

	friend ostream& operator<< (ostream& out, Matrix &mat);
	friend istream& operator>> (istream& in, Matrix &mat);

	/*
	 * Destructor
	 * Deletes allocated memory for Matrix when it's out of scope
	 */
	virtual ~Matrix();

};
#endif
