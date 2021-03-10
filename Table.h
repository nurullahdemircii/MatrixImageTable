#include "Matrix.h"
#include <string>
class Table : public Matrix {
public:
	Table();
	Table(const int, const int, const int);
	Table(const int, const int, char);
	int itemAt(int, int);
	int itemAt(string);
	int itemAt(string rs, string cs);
	void setRowNames(string s[], int n);
	void setColNames(string s[], int n);
	void print();
	~Table();
private:
	void CreateTable() {
		RowName = new string[row];
		if (col <= 26) ColName = new string[26];
		else if (col > 26 && col <= 676) ColName = new string[676];
		else ColName = new string[17576];
		Cha1 = new string[26];
		int cN = 65;
		for (int i = 0; i < row; i++) {
			RowName[i] = to_string(i);
		}
		for (int i = 0; i < 26 && i < col; i++) {
			Cha1[i] = char(cN);
			ColName[i] = Cha1[i];
			cN++;
		} cN = 26;
		if (col > 25) {
			for (int i = 1; i < 26; i++) {
				for (int j = 0; j < 26; j++) {
					ColName[cN] = Cha1[i] + Cha1[j];
					cN++;
				}
			}
		}
		if (col > 676) {
			for (int i = 1; i < 26; i++) {
				for (int j = 0; j < 26; j++) {
					for (int k = 0; k < 26; k++) {
						ColName[cN] = Cha1[i] + Cha1[j] + Cha1[k];
						cN++;
					}
				}
			}
		}
	}
	string** NameMtrx, * RowName, * ColName, * Cha1;
};
