#include "Image.h"
/* ** Image Class Of Constructor Without Parameters ** */
Image::Image() :Matrix(13, 13, 0) {
	w = this->col;
	h = this->row;
	CreateRGB();
}
/* ** Image Class Of Constructor With Parameters ** */
Image::Image(unsigned int _height, unsigned const int _width) :Matrix(_height, _width, 0) {
	h = _height;
	w = _width;
	CreateRGB();
}
/* ** Image Class Of Constructor With Parameters Read File ** */
Image::Image(string filename, string format) :Matrix(255, 255, 0) {
	ifstream file(filename, ios::in | ios::binary | ios::ate);
	if (format == "bin") {
		if (file.is_open()) {
			size = file.tellg(); //cout << "Boyut: " << size << endl;
			memblock = new char[size];
			file.seekg(0, ios::beg);
			file.read(memblock, size);
			file.close(); //cout << "Tum Dosya Icerigi Hafizada!";
		}
		else {}//cout << "Dosya Acilamadi.";
		w = (int(memblock[0]) + 256) % 256;
		h = (int(memblock[1]) + 256) % 256;

		Matrix temp;
		temp.resize(h, w);
		this->row = h;
		this->col = w;
		CreateRGB();
		int count = 2;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				RGBA[i][j].r = memblock[count];
				RGBA[i][j].g = memblock[count + 1];
				RGBA[i][j].b = memblock[count + 2];
				RGBA[i][j].a = 1;
				count += 3;
			}
		}
		delete memblock;
	}
	else if (format == "bmp") {
		if (file.is_open()) {
			/* **Header Values** */
			memblock = new char[54];
			buffer = new char[54];
			file.seekg(0, ios::beg);
			file.read(memblock, 54);
			for (int i = 0; i < 54; i++) {
				buffer[i] = memblock[i];
			}
			bfsize = memblock[2];
			bfoffset = memblock[10];
			w = (int(memblock[18]) + 256) % 256;
			h = (int(memblock[22]) + 256) % 256;
			bppixel = memblock[28];
			padding = 4 - (3 * w) % 4;
			if (padding = 4) padding = 0;
			delete memblock;
			/* **RGB Values** */
			file.seekg(0, ios::end);
			size = file.tellg(); //cout << "Boyut: " << size << endl;
			memblock = new char[3];
			CreateRGB();
			file.seekg(54, ios::beg);
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					file.read(memblock, 3);
					//if (j != w - 1) { file.seekg(3, ios::cur); }
					RGBA[i][j].r = (int(memblock[0]) + 256) % 256; //cout << RGBA[i][j].r << "\t";
					RGBA[i][j].g = (int(memblock[1]) + 256) % 256; //cout << RGBA[i][j].g << "\t";
					RGBA[i][j].b = (int(memblock[2]) + 256) % 256; //cout << RGBA[i][j].b << "\n";
				} file.seekg(padding, ios::cur);
			}
			delete memblock;
			file.close();
		}
		else { cout << "Dosya Acilamadi.\n"; }
	}
	else { cout << "Dosya formatý Uygun Degil!\n"; }
}
void Image::imRead(string filename, string format) {
	Image(filename, format);
}
void Image::imWrite(string filename, string format) {
	if (format == "bin") {
		ofstream outfile(filename, ios::in | ios::binary | ios::out);
		outfile << char(w);
		outfile << char(h);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				outfile << char(RGBA[i][j].r) << char(RGBA[i][j].g) << char(RGBA[i][j].b);
			}
		}
		outfile.close();
		delete RGBA;
	}
	else if (format == "bmp") {
		ofstream outfile(filename, ios::in | ios::binary | ios::out);
		for (int i = 0; i < 54; i++) {
			outfile << buffer[i];
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				outfile.write((char*)&RGBA[i][j].r, 1);
				outfile.write((char*)&RGBA[i][j].g, 1);
				outfile.write((char*)&RGBA[i][j].b, 1);
			}	outfile.seekp(padding, ios::cur);
		}
		outfile.close();
		delete buffer;
		delete RGBA;
	}
	else { cout << "Format Taninmadi!\n"; }
}
void Image::color2gray() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int m = ((int)RGBA[i][j].r + (int)RGBA[i][j].g + (int)RGBA[i][j].b) / 3;
			RGBA[i][j].r = m;
			RGBA[i][j].g = m;
			RGBA[i][j].b = m;
		}
	}
}
void Image::Gray_BW() {
	int _r, _g, _b;
	if (GrayBW == 0) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				_r = (int)RGBA[i][j].r;
				_g = (int)RGBA[i][j].g;
				_b = (int)RGBA[i][j].b;
				if (_r == _g && _g == _b) GrayBW = 1;
				else { GrayBW = 0; break; }
			}
		}
	}
	else if (GrayBW == 1) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				_r = (int)RGBA[i][j].r;
				_g = (int)RGBA[i][j].g;
				_b = (int)RGBA[i][j].b;
				if ((_r == 0 || _r == 255) && (_g == 0 || _g == 255) && (_b == 0 || _b == 255)) GrayBW = 2;
				else { GrayBW = 0; break; }
			}
		}
	}
	else if (GrayBW == 2) {}
	else { cout << "Gri Olmayan Resim Siyah Beyaz Yapýlamaz\n"; }
}
void Image::gray2Binary(int thr) {
	Gray_BW();
	if (GrayBW == 1) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if ((int)RGBA[i][j].r < thr) {
					RGBA[i][j].r = 0;
					RGBA[i][j].g = 0;
					RGBA[i][j].b = 0;
				}
				else {
					RGBA[i][j].r = 255;
					RGBA[i][j].g = 255;
					RGBA[i][j].b = 255;
				}
			}
		}
	}
	else cout << "Image Is Not Gray\n";
}
void Image::erosion() {
	Gray_BW();
	int** mask;
	mask = new int* [h];
	for (int i = 0; i < h; i++) {
		mask[i] = new int[w];
	}
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			mask[i][j] = 255;
	if (GrayBW == 2) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (RGBA[i][j].r == 0) {
					if (i != 0 && j != 0 && j != w - 1 && i != h - 1 &&
						RGBA[i - 1][j].r == 0 && RGBA[i][j - 1].r == 0 &&
						RGBA[i][j + 1].r == 0 && RGBA[i + 1][j].r == 0)
					{
						mask[i][j] = 0;
					}
				}
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				RGBA[i][j].r = mask[i][j];
				RGBA[i][j].g = mask[i][j];
				RGBA[i][j].b = mask[i][j];
			}
		}
	}
	else {
		cout << "Image Is Not Black&White For Erosion\n";
	}
	delete mask;
}
void Image::dilation() {
	Gray_BW();
	int** mask;
	mask = new int* [h];
	for (int i = 0; i < h; i++) {
		mask[i] = new int[w];
	}
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			mask[i][j] = 255;
	if (GrayBW == 2) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (RGBA[i][j].r == 0) {
					if (i != 0) { mask[i - 1][j] = 0; }
					if (j != 0) { mask[i][j - 1] = 0; }
					if (j != w - 1) { mask[i][j + 1] = 0; }
					if (i != h - 1) { mask[i + 1][j] = 0; }
				}
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				RGBA[i][j].r = mask[i][j];
				RGBA[i][j].g = mask[i][j];
				RGBA[i][j].b = mask[i][j];
			}
		}
	}
	else {
		cout << "Image Is Not Black&White For Dilation\n";
	}
	delete mask;
}
void Image::opening() {
	erosion();
	dilation();
}
void Image::closing() {
	dilation();
	erosion();
}
void Image::print() {
	int k = 0;
	for (int i = 0; i < 1; i++) {
		cout << endl;
		for (int j = 0; j < w; j++) {
			k++;
			cout << k << ". pixel: " << this->Mtrx[i][j]
				<< " " << Image::RGBA[i][j].r
				<< " " << Image::RGBA[i][j].g
				<< " " << Image::RGBA[i][j].b << "\n";
		}
	}
}
/* ** Image Class Of Destructor ** */
Image::~Image() {

}