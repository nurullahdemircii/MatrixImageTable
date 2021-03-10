
#include "Matrix.h"
class Image : public Matrix {
public:
	struct RGB {
		int r, g, b, a; // red green blue
		RGB() : r(0), g(0), b(0), a(1) {}
		RGB(double v) : r(v), g(v), b(v), a(1) {}
		RGB(double _r, double _g, double _b, double _a) : r(_r), g(_g), b(_b), a(_a) {}
	};
	Image();
	Image(unsigned int _height, unsigned int _width);
	Image(string filename, string format);
	void imRead(string filename, string format);
	void imWrite(string filename, string format);
	void Image::Gray_BW();
	void color2gray();
	void gray2Binary(int thr);
	void erosion();
	void dilation();
	void opening();
	void closing();
	void print();
	~Image();
private:
	void CreateRGB() {
		RGBA = new Image::RGB * [h];
		for (int i = 0; i < h; i++) {
			RGBA[i] = new Image::RGB[w];
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				RGBA[i][j].r = 0;
				RGBA[i][j].g = 0;
				RGBA[i][j].b = 0;
				RGBA[i][j].a = 1;
			}
		}
	}
	unsigned int w, h;
	int GrayBW = 0;
	streampos size;
	char* memblock, * buffer;
	char bfsize, bfoffset, bppixel;
	int	 padding;

	Image::RGB** RGBA;
};
/*Rgb() : r(0), g(0), b(0) {}
Rgb(float c) : r(c), g(c), b(c) {}
Rgb(float _r, float _g, float _b) : r(_r), g(_g), b(_b) {}
bool operator != (const Rgb &c) const
{ return c.r != r || c.g != g || c.b != b; }
Rgb& operator *= (const Rgb &rgb)
{ r *= rgb.r, g *= rgb.g, b *= rgb.b; return *this; }
Rgb& operator += (const Rgb &rgb)
{ r += rgb.r, g += rgb.g, b += rgb.b; return *this; }
friend float& operator += (float &f, const Rgb rgb)
{ f += (rgb.r + rgb.g + rgb.b) / 3.f; return f; }
float r, g, b; */
