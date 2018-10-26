// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 1 - Problem 0
// Program: CS213-2018-A1-T1-P0
// Purpose: Apply basic arithmetic operations on Matrices
// Author1: Mostafa Omar Mahmoud - 20170292
// Date:    25 October 2018
// Version: 1.0

/**
 * File: Matrix.cpp
 *
 * This file has the implementation of the methods in Matrix.h
 * Applies basic arithmetic operations on matrices
 */


/// Hanafy's commit in 26/10/18
/// done with
    ///+= operator      for 2 matrices
    ///-= operator      for 2 matrices
    ///+= operator      matrix and scalar
    ///-= operator      matrix and scalar
    /// ++ and --       both postfix and prefix
    /// isSquare isIdentity isSymmetric and transpose functions

/// v1.1


#include <cassert>
#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix(int row, int col)
{
	this->row = row;
	this->col = col;

	this->data = new int*[row];
	for (int i = 0; i < row; ++i)
		data[i] = new int[col];
}

Matrix::Matrix(const Matrix &mat)
{
	this->row = mat.row;
	this->col = mat.col;

	this->data = new int* [this->row];
	for (int i = 0; i < this->row; ++i)
	{
		this->data[i] = new int [this->col];
		for (int j = 0; j < this->col; ++j)
			this->data[i][j] = mat.data[i][j];
	}
}

Matrix Matrix::operator=(const Matrix &mat)
{
	// deallocation of matrix
	for (int i = 0; i < this->row; ++i)
	{
		delete[] this->data[i];
		this->data[i] = 0;
	}
	delete[] this->data;
	data = 0;

	//reallocation of matrix
	this->row = mat.row;
	this->col = mat.col;
	this->data = new int* [mat.row];
	for (int i = 0; i < mat.row; ++i)
	{
		this->data[i] = new int[mat.col];
		for (int j = 0; j < mat.col; ++j)
		{
			this->data[i][j] = mat.data[i][j];
		}
	}

	return *this;
}

bool Matrix::checkDimensions(int i, int j)
{
	return i >= 0 && j >= 0 && i < this->row && j < this->col;
}

int Matrix::getCell(int i, int j)
{
	assert(Matrix::checkDimensions(i, j));
	return this->data[i][j];
}

void Matrix::setCell(int i, int j, int val)
{
	assert(Matrix::checkDimensions(i, j));
	this->data[i][j] = val;
}

ostream& operator<< (ostream& out, const Matrix &mat)
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

istream& operator>> (istream& in, Matrix &mat)
{
	for (int i = 0; i < mat.row; ++i)
	{
		for (int j = 0; j < mat.col; ++j)
		{
			int x;
			in >> x;
			mat.setCell(i, j, x);
		}
	}
	return in;
}
/**********************************************************/
 /// HANAFY'S PROTOTYPES

Matrix Matrix :: operator+= ( Matrix &mat2){      /// mat1 changes & return new matrix with the sum
                                                /// done

      ///can do this trick   *this = *this + mat2;
        int r = this->row;
        int c = this->col;

        if(r != mat2.row || c!= mat2.col){
            cout<<"can't add matrices with different sizes\n";
            return *this;
        }
        int **arr = 0;
        if(this->data != NULL)
             arr= this->data;             /// creating a double pointer to the data array in the matrix we add to it
        for (int i = 0; i <r ; ++i) {
            for (int j = 0; j <c ; ++j)
                arr[i][j] += mat2.data[i][j] ;



        }
    return  *this;
}
Matrix Matrix :: operator-= ( Matrix &mat2){      /// mat1 changes & return new matrix with the subtract
                                                /// done
        int r = this->row;
        int c = this->col;

        if(r != mat2.row || c!= mat2.col){
            cout<<"can't add matrices with different sizes\n";
            return *this;
        }
        int **arr = 0;
        if(this->data != NULL)
             arr= this->data;             /// creating a double pointer to the data array in the matrix we add to it
        for (int i = 0; i <r ; ++i) {
            for (int j = 0; j <c ; ++j)
                arr[i][j] -= mat2.data[i][j] ;



        }
    return  *this;
}
Matrix Matrix :: operator +=(int x){
    *this = *this +x;
    return *this;
}
Matrix Matrix :: operator -=(int x){
    *this = *this -x;
    return *this;
}
Matrix& Matrix :: operator ++(){            ///prefix increment
    *this = *this +1;
    return *this;
}
Matrix Matrix :: operator ++(int){          /// postfix increment
    Matrix ret = *this;
    ++(*this);
    return ret;
}
Matrix& Matrix :: operator --(){            ///prefix decrement
    *this = *this -1;
    return *this;
}
Matrix Matrix :: operator --(int){          /// postfix decrement
    Matrix ret = *this;
    --(*this);
    return ret;
}
bool Matrix :: isSquare(){
    return this->row == this->col;          /// if matrix row == matrix column then true otherwise false

}
bool Matrix ::  isSymetric (){
    if(!isSquare()) return false;
     /**            check every cell and its corresponding except the main diagonal
      *             for every i and j= i +1 because no meaning for j = i
      *             (0,0)   (0,1)   (0,2)   (0,3)
      *             (1,0)   (1,1)   (1,2)   (1,3)
      *             (2,0)   (2,1)   (2,2)   (2,3)
      *             (3,0)   (3,1)   (3,2)   (3,3)
      *
      *
      */
    int **data = 0;
    int row = this->row;
    int col = this->col;
    if(this->data != 0) data = this->data;
    else                return false;
    for (int i = 0; i <row ; ++i) {
        for (int j = i+1; j < col; ++j) {
            if (data[i][j] != data[j][i])
                return false;
        }
    }

    return true;

}
bool Matrix :: isIdentity (){
    if(!isSquare())
        return false ;
     /**             check every cell and its corresponding except the main diagonal
      *             for every i and j= i +1 because no meaning for j = i
      *             (0,0)   (0,1)   (0,2)   (0,3)
      *             (1,0)   (1,1)   (1,2)   (1,3)
      *             (2,0)   (2,1)   (2,2)   (2,3)
      *             (3,0)   (3,1)   (3,2)   (3,3)
      *
      *
      */

    int **data = 0;
    int row = this->row;
    int col = this->col;
    if(this->data != 0) data = this->data;
    else                return false;
    for(int i = 1 ; i <row ; ++i){
        if(data[i][i] != data[i-1][i-1] || data[i][i]!= 1)
            return false;
    }
    for (int i = 0; i <row ; ++i) {
        for (int j = i+1; j < col; ++j ) {
            if (data[i][j] != data[j][i]|| data[i][j]!= 0)
                return false;
        }
    }

    return true;
}
Matrix Matrix :: transpose(){
    Matrix retmat (this->col , this->row);

    for (int i = 0; i <this->row ; ++i) {
        for (int j = 0; j < this->col; ++j) {
            retmat.data[j][i]= this->data[i][j];
        }
    }
    *this = retmat;         /// saving the new matrix in this
    return *this; // i don't know how the matrix change in memory size if i returned transposed matrix 3x4 to 4x3
}






/***********************************************************/
Matrix Matrix::operator+(Matrix mat)
{
	assert(this->row == mat.row && this->col == mat.col);
	Matrix resultMat(this->row, this->col);
	for (int i = 0; i < this->row; ++i)
	{
		for (int j = 0; j < this->col; ++j)
		{
			resultMat.setCell(i, j,  this->getCell(i, j) + mat.getCell(i, j));
		}
	}
	return resultMat;
}

Matrix Matrix::operator-(Matrix mat)
{
	assert(this->row == mat.row && this->col == mat.col);
	Matrix resultMat(this->row, this->col);
	for (int i = 0; i < this->row; ++i)
	{
		for (int j = 0; j < this->col; ++j)
		{
			resultMat.setCell(i, j,  this->getCell(i, j) - mat.getCell(i, j));
		}
	}
	return resultMat;

}

Matrix Matrix::operator*(Matrix mat)
{
	assert(this->col == mat.row);
	Matrix resultMat(this->row, mat.col);
	for (int i = 0; i < this->row; ++i)
	{
		for (int j = 0; j < mat.col; ++j)
		{
			for (int k = 0; k < this->col; ++k)
			{
				if (k == 0)
					resultMat.setCell(i, j, this->data[i][k] * mat.data[k][j]);
				else
					resultMat.setCell(i, j,  resultMat.getCell(i, j) + this->data[i][k] * mat.data[k][j]);
			}
		}
	}
	return resultMat;

}

Matrix Matrix::operator+(int scalar)
{
	Matrix resultMat(*this);
	for (int i = 0; i < this->row; ++i)
	{
		for (int j = 0; j < this->col; ++j)
			resultMat.data[i][j] += scalar;
	}
	return resultMat;
}

Matrix Matrix::operator-(int scalar)
{
	Matrix resultMat(*this);
	for (int i = 0; i < this->row; ++i)
	{
		for (int j = 0; j < this->col; ++j)
			resultMat.data[i][j] -= scalar;
	}
	return resultMat;
}


Matrix Matrix::operator*(int scalar)
{
	Matrix resultMat(*this);
	for (int i = 0; i < this->row; ++i)
	{
		for (int j = 0; j < this->col; ++j)
			resultMat.data[i][j] *= scalar;
	}
	return resultMat;
}


bool Matrix::operator==(Matrix &mat)
{
	if (this->row != mat.row || this->col != mat.col)
		return false;
	for (int i = 0; i < this->row; ++i)
	{
		for (int j = 0; j < this->col; ++j)
		{
			if (this->data[i][j] != mat.data[i][j])
				return false;
		}
	}
	return true;
}

bool Matrix::operator!=(Matrix &mat)
{
	return !(*this == mat);
}

Matrix::~Matrix()
{
	for (int i = 0; i < this->row; ++i)
	{
		delete[] this->data[i];
		this->data[i] = 0;
	}
	delete[] this->data;
	this->data = 0;
	this->row = 0;
	this->col = 0;
}
