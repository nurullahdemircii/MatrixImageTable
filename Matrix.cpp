#include "Matrix.h"

/* ** Constructor Function Without Parameters ** */
Matrix::Matrix() {
	this->row = 10;
	this->col = 10;
	this->Create();
	//cout << "parametresiz yapýcý çalýþtý. \n";
}

/* ** Constructor Function With Parameters ** */
Matrix::Matrix(unsigned const int _row, unsigned const int _col, int _val) {
	this->row = _row;
	this->col = _col;
	this->val = _val;
	this->Create();
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			Mtrx[i][j] = val;
}

/* ** Constructor Function With Parameters ** */
Matrix::Matrix(unsigned const int _row, unsigned const int _col, const char _val) {
	this->row = _row;
	this->col = _col;
	this->Create();
	if (_val == 'e' && row == col) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (i == j) Mtrx[i][j] = 1;
			}
		}
	}
	if (_val == 'r') {
		srand(time(NULL));
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				Mtrx[i][j] = rand() % 255 + 0;
			}
		}
	}
}
/* ** Matrix Copy Function ** */
void Matrix::copyMatrix(unsigned int _row, unsigned int _col) {
	int r, c;
	if (row > _row)    r = row;
	else              r = _row;
	if (col > _col)    c = col;
	else              c = _col;
	cpyMtrx = new int* [r];
	for (int i = 0; i < r; i++) {
		cpyMtrx[i] = new int[c];
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cpyMtrx[i][j] = 0;
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cpyMtrx[i][j] = Mtrx[i][j];
		}
	}
}

/* ** Resize Of Matrix Function ** */
void Matrix::resize(int _row, int _col) {
	this->copyMatrix(_row, _col);
	this->row = _row;
	this->col = _col;
	this->Create();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			Mtrx[i][j] = cpyMtrx[i][j];
		}
	}
	for (int i = 0; i < row; i++)
		delete[] cpyMtrx[i];
	delete[] cpyMtrx;/**/
}

/* ** '+' Operator Overloading Function With Object ** */
Matrix Matrix::operator+(const Matrix& m) {
	Matrix temp(this->row, this->col, 0);
	int i, j;
	if (this->row == m.row && this->col == m.col)
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				temp.Mtrx[i][j] = this->Mtrx[i][j] + m.Mtrx[i][j];
			}
		}
	else {
		cout << "matrix'ler denk deðil!\n";
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				temp.Mtrx[i][j] = this->Mtrx[i][j];
			}
		}
	}
	return temp;
}

/* ** '-' Operator Overloading Function With Object ** */
Matrix Matrix::operator-(const Matrix& m) {
	Matrix temp(this->row, this->col, 0);
	int i, j;
	if (this->row == m.row && this->col == m.col)
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				temp.Mtrx[i][j] = this->Mtrx[i][j] - m.Mtrx[i][j];
			}
		}
	else {
		cout << "matrix'ler denk deðil!\n";
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				temp.Mtrx[i][j] = this->Mtrx[i][j];
			}
		}
	}
	return temp;
}

/* ** '*' Operator Overloading Function With Object ** */
Matrix Matrix::operator*(const Matrix& m) {
	Matrix temp(this->row, this->col, 0);
	int i, j;
	if (this->row == m.row && this->col == m.col)
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				temp.Mtrx[i][j] = this->Mtrx[i][j] * m.Mtrx[i][j];
			}
		}
	else {
		cout << "matrix'ler denk deðil!\n";
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				temp.Mtrx[i][j] = this->Mtrx[i][j];
			}
		}
	}
	return temp;
}

/* ** '+' Operator Overloading Function With Int Value ** */
Matrix Matrix::operator+(const int m) {
	Matrix temp(this->row, this->col, 0);
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			temp.Mtrx[i][j] = this->Mtrx[i][j] + m;
		}
	}
	return temp;
}

/* ** '-' Operator Overloading Function With Int Value ** */
Matrix Matrix::operator-(const int m) {
	Matrix temp(this->row, this->col, 0);
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			temp.Mtrx[i][j] = this->Mtrx[i][j] - m;
		}
	}
	return temp;
}

/* ** '*' Operator Overloading Function With Int Value ** */
Matrix Matrix::operator*(const int m) {
	Matrix temp(this->row, this->col, 0);
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			temp.Mtrx[i][j] = this->Mtrx[i][j] * m;
		}
	}
	return temp;
}

/* ** '/' Operator Overloading Function With Int Value ** */
Matrix Matrix::operator/(const int m) {
	Matrix temp(this->row, this->col, 0);
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			temp.Mtrx[i][j] = this->Mtrx[i][j] / m;
		}
	}
	return temp;
}

/* ** '%' Operator Overloading Function With Int Value ** */
Matrix Matrix::operator%(const int m) {
	Matrix temp(this->row, this->col, 0);
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			temp.Mtrx[i][j] = this->Mtrx[i][j] % m;
		}
	}
	return temp;
}

/* ** '^' Operator Overloading Function With Int Value ** */
Matrix Matrix::operator^(const int m) {
	Matrix temp(this->row, this->col, 0);
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			temp.Mtrx[i][j] = pow(this->Mtrx[i][j], m);
		}
	}
	return temp;
}

/* ** '+' Operator Overloading Friend Function With Object ** */
Matrix operator+(const Matrix& m1, const Matrix& m2) {
	Matrix temp(m1.row, m1.col, 0);
	int i, j;
	if (m1.row == m2.row && m1.col == m2.col)
		for (i = 0; i < temp.row; i++) {
			for (j = 0; j < temp.col; j++) {
				temp.Mtrx[i][j] = m1.Mtrx[i][j] + m2.Mtrx[i][j];
			}
		}
	else
		cout << "matrix'ler denk deðil!\n";

	return temp;
}

/* ** Take Matrix Transpose Function ** */
void Matrix::T() {
	int _row, _col;
	_row = this->col;
	_col = this->row;
	Matrix temp(_row, _col, 0);
	for (int i = 0; i < _col; i++) {
		for (int j = 0; j < _row; j++) {
			temp.Mtrx[j][i] = this->Mtrx[i][j];
		}
	}
	row = _row;
	col = _col;
	this->Create();
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++) {
			this->Mtrx[i][j] = temp.Mtrx[i][j];
		}
	}
}
/* ** Matrix Elementwise Multiply Function ** */
void Matrix::emul(const Matrix& obj) {
	int _val, total = 0;
	Matrix temp(this->row, obj.col, 0);
	if (this->col == obj.row) {
		for (int i = 0; i < this->row; i++) {
			for (int k = 0; k < obj.col; k++) {
				for (int j = 0; j < obj.row; j++) {
					_val = this->Mtrx[i][j] * obj.Mtrx[j][k];
					total += _val;
				}
				temp.Mtrx[i][k] = total;
				total = 0;
			}
		}
		this->col = obj.col;
		this->Create();
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < this->col; j++) {
				this->Mtrx[i][j] = temp.Mtrx[i][j];
			}
		}
	}
	else cout << "Bu iki Matris Eleman Düzeyinde Çarpýlamaz!\n";
}

/* ** Inversion Of Matrix Function With Gauss Jordan Rule ** */
void Matrix::inv() {
	int _det = det();
	if (_det != 0 && _det != 999999) {
		int length = this->row;
		int minor;
		double** temporaryM;
		double** identityM;
		double* temporaryD;
		double* identityD;
		temporaryM = new double* [length];
		identityM = new double* [length];
		temporaryD = new double[length];
		identityD = new double[length];
		for (int i = 0; i < length; i++) {
			temporaryM[i] = new double[length];   //Temporary Parent Matrix
			identityM[i] = new double[length];     //Supersession Matrix
			temporaryD[i] = 0.0;                  //Temporary Array
			identityD[i] = 0.0;                    //Supersession Array
		}
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				temporaryM[i][j] = this->Mtrx[i][j];
				if (i == j) identityM[i][j] = 1.0;
				else identityM[i][j] = 0.0;
			}
		}
		for (int tur = 0; tur < 2; tur++) {
			for (minor = 0; minor < length - 1; minor++) {
				int zero = minor + 1;
				double division, cofactor; //Çarpýlan
				if (temporaryM[minor][minor] == 0.0) {
					for (int i = zero; i < length; i++) {
						if (temporaryM[i][minor] != 0.0) {
							for (int j = 0; j < length; j++) {
								//Parent Matrix Supersession
								temporaryD[j] = temporaryM[minor][j];
								temporaryM[minor][j] = temporaryM[i][j];
								temporaryM[i][j] = temporaryD[j];
								//Identity Matrix Supersession
								identityD[j] = identityM[minor][j];
								identityM[minor][j] = identityM[i][j];
								identityM[i][j] = identityD[j];
							}
							i = length;
						}
					}
				}
				division = (1 / temporaryM[minor][minor]);
				for (int i = 0; i < length; i++) {
					temporaryM[minor][i] *= division;
					identityM[minor][i] = identityM[minor][i] * division;
				}
				for (zero = minor + 1; zero < length; zero++) {
					if (temporaryM[zero][minor] != 0.0) {
						cofactor = temporaryM[zero][minor] / temporaryM[minor][minor];
						if ((temporaryM[minor][minor] < 0.0 && temporaryM[zero][minor] > 0.0) || (temporaryM[minor][minor] > 0.0 && temporaryM[zero][minor] < 0.0)) {
							//cout << "if\n";//sýkýntý var
							for (int i = 0; i < length; i++) {
								temporaryD[i] = temporaryM[minor][i] * cofactor;
								identityD[i] = identityM[minor][i] * cofactor;
							}
							for (int i = 0; i < length; i++) {
								temporaryM[zero][i] -= temporaryD[i];
								identityM[zero][i] -= identityD[i];
							}
						}
						else {
							//cout << "else\n";
							for (int i = 0; i < length; i++) {
								temporaryD[i] = (-1 * (temporaryM[minor][i] * cofactor));
								identityD[i] = (-1 * (identityM[minor][i] * cofactor));
							}
							for (int i = 0; i < length; i++) {
								temporaryM[zero][i] += temporaryD[i];
								identityM[zero][i] += identityD[i];
							}
						}
					}
					else {
						temporaryM[zero][minor] = 0.0;
						//cout << "zeroMinor = 0\n";
					}
				}
			}
			// Change For Simetri in Matrix
			int uzunluk = length;
			for (int y = 0; y < length / 2; y++) {
				uzunluk--;
				for (int z = 0; z < length; z++) {
					double changeT = temporaryM[z][y];
					double changeI = identityM[z][y];
					temporaryM[z][y] = temporaryM[z][uzunluk];
					temporaryM[z][uzunluk] = changeT;
					identityM[z][y] = identityM[z][uzunluk];
					identityM[z][uzunluk] = changeI;
				}
			}
			uzunluk = length;
			for (int y = 0; y < length / 2; y++) {
				uzunluk--;
				for (int z = 0; z < length; z++) {
					double changeT = temporaryM[y][z];
					double changeI = identityM[y][z];
					temporaryM[y][z] = temporaryM[uzunluk][z];
					temporaryM[uzunluk][z] = changeT;
					identityM[y][z] = identityM[uzunluk][z];
					identityM[uzunluk][z] = changeI;
				}
			}
		}
		/*for(int i = 0; i < length; i++){
		for(int j = 0; j < length; j++){
		cout << fixed << setprecision(2) << temporaryM[i][j] << "\t";
		} cout << endl;
		}cout << endl;*/
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				cout << fixed << setprecision(2) << identityM[i][j] << "\t";
			} cout << endl;
		}
		delete temporaryM;
		delete identityM;
		delete temporaryD;
		delete identityD;
	}
	else if (_det == 999999) {
		//cout << "Kare olmayan Matrisin Tersi Yoktur.\n";
	}
	else {}
	//cout << "Matrisin Determinantý Sýfýr(0)'dýr. Dolayýsýyla Matrisin Tersi Yoktur.\n";
}

/* ** Determinant Of Matrix Function With Gauss Jordan Rule ** */
int Matrix::det() {
	int det = 1;
	if (this->row == this->col) {
		int length = this->row, minor;
		double** temporaryM;
		double* temporaryD;
		temporaryM = new double* [length];
		temporaryD = new double[length];
		for (int i = 0; i < length; i++) {
			temporaryM[i] = new double[length];
			temporaryD[i] = 0.0;
		}
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				temporaryM[i][j] = this->Mtrx[i][j];
			}
		}
		for (minor = 0; minor < length - 1; minor++) {
			for (int zero = minor + 1; zero < length; zero++) {
				if (temporaryM[zero][minor] != 0.0) {
					if ((temporaryM[minor][minor] < 0.0 && temporaryM[zero][minor] > 0.0) || (temporaryM[minor][minor] > 0.0 && temporaryM[zero][minor] < 0.0)) {
						//cout << "if\n";//sýkýntý var
						for (int i = 0; i < length; i++) {
							temporaryD[i] = (temporaryM[minor][i] * (temporaryM[zero][minor] / temporaryM[minor][minor]));
						}
						for (int i = 0; i < length; i++) {
							temporaryM[zero][i] -= temporaryD[i];
							temporaryD[i] = 0.0;
						}
					}
					else if (temporaryM[minor][minor] == 0.0) {
						//cout << "else if\n";
						for (int i = 0; i < length; i++) {
							temporaryD[i] = temporaryM[minor][i];
							temporaryM[minor][i] = temporaryM[zero][i];
							temporaryM[zero][i] = -1 * temporaryD[i];
						}
						for (int i = 0; i < length; i++) {
							temporaryD[i] = (-1 * (temporaryM[minor][i] * (temporaryM[zero][minor] / temporaryM[minor][minor])));
						}
						for (int i = 0; i < length; i++) {
							temporaryM[zero][i] += temporaryD[i];
							temporaryD[i] = 0.0;
						}
					}
					else {
						//cout << "else\n";
						for (int i = 0; i < length; i++) {
							temporaryD[i] = (-1 * (temporaryM[minor][i] * (temporaryM[zero][minor] / temporaryM[minor][minor])));
						}
						for (int i = 0; i < length; i++) {
							temporaryM[zero][i] += temporaryD[i];
							temporaryD[i] = 0.0;
						}
					}
				}
				else {
					temporaryM[zero][minor] = 0.0;
					//cout << "zeroMinor = 0\n";
				}
			}
		}
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				//cout << fixed << setprecision(2) << temporaryM[i][j] << "\t";
			} //cout << endl;
			det *= temporaryM[i][i];
		}

		delete temporaryM;
		delete temporaryD;
		this->determinant = det;
		return det;
	}
	else {
		this->determinant = 999999;
		return 999999;
	}
}
/* **Matrix Print Function Without Parameters** */
void Matrix::print() {
	for (int j = 0; j <= col; j++)
		if (j == 0) cout << row << "x" << col << "\t";
		else cout << j - 1 << "\t";
	cout << endl;
	for (int j = 0; j <= col; j++)
		if (j == 0) cout << "\t";
		else cout << "-\t";
	cout << endl;/**/
	for (int i = 0; i < this->row; i++) {
		cout << i << "|\t";
		for (int j = 0; j < this->col; j++) {
			cout << this->Mtrx[i][j] << "\t";
		}cout << endl;
	}
	cout << "------------------------------------------\n";
}

/* **Matrix Print Function With File Parameter** */
void Matrix::print(string _file) {
	file = _file;
	ofstream outfile;
	outfile.open(file, ios::trunc);
	for (int i = 0; i < this->row; i++) {
		outfile << "|\t";
		for (int j = 0; j < this->col; j++) {
			outfile << this->Mtrx[i][j] << "\t";
		}outfile << "|\t\n";
	}
	outfile.close();
}

/* **Matrix Print Determinant Function With File Parameter** */
void Matrix::print(int _det) {
	if (this->det() == 999999)
		cout << "* Kare olmayan Matrisin Determinantý Söz Konusu Deðildir!\n";
	else
		cout << "Determinant = " << this->det() << endl;
}

/* **Destructor Function** */
Matrix::~Matrix() {
	//cout << "yýkýcý çalýþtý" << endl ;
	/*for(int i =0; i < row; i++)
	delete [] Mtrx[i];
	delete [] Mtrx;*/
}