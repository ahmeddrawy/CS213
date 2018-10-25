/*
 * File: Matrix.cpp
 *
 * This file has the implementation of the methods in Matrix.h
 * Applies basic arithmetic operations on matrices
 */

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
