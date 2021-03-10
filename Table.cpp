#include "Table.h"

Table::Table() :Matrix(10, 10, 0) { CreateTable(); }
Table::Table(const int	_TRow, const int	_TCol, const int	_TVal)
	: Matrix(_TRow, _TCol, _TVal) {
	CreateTable();
}
Table::Table(const int	_TRow, const int	_TCol, char _TVal)
	: Matrix(_TRow, _TCol, _TVal) {
	CreateTable();
	if (_TVal == 'e') {
		for (int i = 0; i < _TRow; i++) {
			for (int j = 0; j < _TCol; j++) {
				Mtrx[i][j] = 0;
			}
		}
	}
}
int Table::itemAt(int _r, int _c) {
	return Mtrx[_r][_c];
}
int Table::itemAt(string _s) {
	NameMtrx = new string * [this->row];
	for (int i = 0; i < this->row; i++)
		NameMtrx[i] = new string[this->col];
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++) {
			NameMtrx[i][j] = ColName[j] + RowName[i];
			//cout << NameMtrx[i][j] << " ";
		}	//cout << endl;
	}
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++) {
			if (NameMtrx[i][j] == _s) {
				delete NameMtrx;
				return Mtrx[i][j];
			}
		}
	}
	delete NameMtrx;
	return 0;
}
int Table::itemAt(string rs, string cs) {
	string swap = cs + rs;
	NameMtrx = new string * [this->row];
	for (int i = 0; i < this->row; i++)
		NameMtrx[i] = new string[this->col];
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++) {
			NameMtrx[i][j] = ColName[j] + RowName[i];
			//cout << NameMtrx[i][j] << " ";
		}	//cout << endl;
	}
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++) {
			if (NameMtrx[i][j] == swap) {
				delete NameMtrx;
				return Mtrx[i][j];
			}
		}
	}
	delete NameMtrx;
	return 0;
}
void Table::setRowNames(string s[], int n) {
	for (int i = 0; i < n; i++) {
		RowName[i] = s[i];
	}
}
void Table::setColNames(string s[], int n) {
	for (int i = 0; i < n; i++) {
		ColName[i] = s[i];
	}
}
void Table::print() {
	//cout << std::setfill(' ') << std::setw(n) << ' ';
	//string rn, cn;
	//int rno, cno;
	//cn = to_string(this->row) + to_string(this->col);
	//cno = cn.size() + 1;
	//cno = (8 - cno);
	string MtrxName = to_string(this->row) + "x" + to_string(this->col);
	for (int j = 0; j < this->col; j++) {
		if (j == 0) {
			cout << left << setw(8) << MtrxName << "|";
		}
		if (ColName[j].length() <= 4) {
			cout << right << setw(4) << ColName[j] << " ";
		}
		else {
			string colString = ColName[j];
			for (int k = 0; k < 4; k++)
				cout << colString[k];
			cout << " ";
		}
	}
	cout << endl;
	cout << setfill('-') << setw((col + 2) * 5) << "" << endl << setfill(' ');
	for (int i = 0; i < this->row; i++) {
		if (RowName[i].length() <= 8) {
			cout << left << setw(8) << RowName[i] << "|";
		}
		else {
			string rowString = RowName[i];
			for (int k = 0; k < 4; k++)
				cout << rowString[k];
			cout << "|";
		}
		for (int j = 0; j < this->col; j++) {
			cout << right << setw(4) << this->Mtrx[i][j] << " ";
		}
		cout << endl;
	}
	cout << setfill('-') << setw((col + 2) * 5) << "" << endl << setfill(' ');
}
Table::~Table() {}