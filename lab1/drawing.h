#ifndef DRAWING_H
#define DRAWING_H
#include <string>
#include <vector>

#include "bmplib.h"

using namespace std; 
//Define your structs/classes in this file
struct Point {
	double x, y;
};

struct ColorPixel {
	uint8_t red, green, blue;
};

struct Line {
	Point start, end;
	ColorPixel c;
};

class ColorImage {
	public:
		ColorImage(uint32_t xdim, uint32_t ydim);
		void setPixel(ColorPixel p, uint32_t x, uint32_t y);
		ColorPixel getPixel(uint32_t x, uint32_t y);
		void render(string filename);
			
	private:
		vector< vector<ColorPixel> > data;
}; 

class Drawing {
	public:
		Drawing();
		void parse(string filename);
		void draw();
		void write(string filename);
	private:
		ColorImage image;
		vector<Line> lines;
};

#endif