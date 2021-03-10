#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

class Matrix {
public:
	Matrix();
	Matrix(unsigned const int _row, unsigned const int _col, int _val);
	Matrix(unsigned const int _row, unsigned const int _col, const char _val);
	void copyMatrix(unsigned int _row, unsigned int _col);
	void resize(int _row, int _col);
	Matrix operator+(const Matrix& m);
	Matrix operator-(const Matrix& m);
	Matrix operator*(const Matrix& m);
	Matrix operator+(const int m);
	Matrix operator-(const int m);
	Matrix operator*(const int m);
	Matrix operator/(const int m);
	Matrix operator%(const int m);
	Matrix operator^(const int m);
	void T();
	void emul(const Matrix& obj);
	void inv();
	int det();

	friend Matrix operator +(const Matrix& m1, const Matrix& m2);
	void print();
	void print(string _file);
	void print(int det);
	~Matrix();
protected:
	void Create() {
		Mtrx = new int* [row];
		for (int i = 0; i < row; i++) {
			Mtrx[i] = new int[col];
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				Mtrx[i][j] = 0;
			}
		}
	}
	int** Mtrx;
	int** cpyMtrx;
	unsigned int row, col;
	int val, determinant;
	string file;
private:

};