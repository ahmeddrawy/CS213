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

Matrix Matrix::operator=(const Matrix mat)
{
	assert((this->row == mat.row) && (this->col == mat.col));

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
		this->data[i] = new int[mat.col];

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

ostream& operator<< (ostream& out, Matrix &mat)
{
	for (int i = 0; i < mat.row; ++i)
	{
		for (int j = 0; j < mat.col; ++j)
		{
			out << mat.getCell(i, j) << ' ';
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
