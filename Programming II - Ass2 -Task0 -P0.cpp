// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 1 - Problem 0
// Program: CS213-2018-A1-T1-P0
// Purpose: Apply basic arithmetic operations on Matrices
// Author1: Mostafa Omar Mahmoud - 20170292
// Date:    25 October 2018
// Version: 1.0
/// Hanafy's commit in 26/10/18
/// done with
    ///+= operator      for 2 matrices
    ///-= operator      for 2 matrices
    ///+= operator      matrix and scalar
    ///-= operator      matrix and scalar
    /// ++ and --       both postfix and prefix
    /// isSquare isIdentity isSymmetric and transpose functions

/// v1.1
#include <iostream>

#include <cassert>
#include "Matrix.h"

Matrix input()
{
	int r, c;
	cout << "Enter rows: ";
	cin >> r;
	cout << "Enter columns: ";
	cin >> c;
	Matrix inputMat(r, c);
	cout << "Enter Matrix elements: ";
	cin >> inputMat;
	return inputMat;
}

int main(){
//	freopen("TestPlease.txt", "r", stdin);
//	Matrix mat1 = input();
	Matrix mat2 = input();
//
//	cout << mat1 << '\n' << mat2 << '\n';
//	cout << mat1 + mat2 << '\n';
//	cout << mat1 - mat2 << '\n';
//	cout << mat1 * mat2 << '\n';
//	if (mat1 == mat2 && !(mat1 != mat2))
//		cout << "Two Matrices are equal\n";
//	else
//		cout << "Two Matrices are not equal\n";
//	cout << "\nEnter scalar: ";
//	int scalar;
//	cin >> scalar;
//	cout << mat1 + scalar << '\n';
//	cout << mat1 - scalar << '\n';
//	cout << mat1 * scalar << '\n';
//	mat2 = mat1++;
	mat2.transpose();
    cout<<mat2.isIdentity()<<endl;
    cout<<mat2.isSquare()<<endl;
    cout<<mat2.isSymetric()<<endl;
}
