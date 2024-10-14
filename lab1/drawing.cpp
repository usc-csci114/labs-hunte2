#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>
#include "bmplib.h"
#include "drawing.h"

//implement your classes in this file
//Point is given for the line drawing algorithm
void ColorImage::setPixel(ColorPixel p, uint32_t x, uint32_t y){
	uint32_t ysize = data.size();
	uint32_t xsize = data[0].size();
	if (x < xsize && y < ysize){
		data[y][x] = p;
	}

}
ColorPixel ColorImage::getPixel(uint32_t x, uint32_t y){
	uint32_t ysize = data.size();
	uint32_t xsize = data[0].size();
	if (x < xsize && y < ysize){
		return data[y][x];
	}
	throw std::range_error("bad size on getPixel()");
}

//adapted from https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
std::vector<Point> plotLine(Point start, Point end)
{
	double x0 = start.x;
	double y0 = start.y;
	double x1 = end.x;
	double y1 = end.y;
	
	double dx = abs(x1 - x0);
	double sx = x0 < x1 ? 1 : -1;
	double dy = -abs(y1 - y0);
	double sy = y0 < y1 ? 1 : -1;
	double error = dx + dy;
	
	std::vector<Point> line;
	
	while(true)
	{
		double dx0 = x0;
		double dy0 = y0;
		Point p = {dx0, dy0};
		//Point p;
		//p.x = x0;
		//p.y = y0;
		line.push_back(p);
		if (x0 == x1 && y0 == y1) break;
		int e2 = 2 * error;
		if(e2 >= dy) {
			error = error + dy;
			x0 = x0 + sx;
		}
		if(e2 <= dx) {
			error = error + dx;
			y0 = y0 + sy;
		}
	}
	return line;
}

ColorImage::ColorImage(uint32_t xdim, uint32_t ydim){
    data.resize(ydim);
    for(size_t i = 0; i < data.size(); ++i){
        data[i].resize(xdim);
    }
}

void ColorImage::render(string filename){
	size_t ydim = data.size();
	size_t xdim = data[0].size();
	uint8_t*** image = new uint8_t**[data.size()];
	for(int i=0; i < data.size(); i++){
		image[i] = new uint8_t*[xdim];
		for(int j = 0; j < xdim; j++){
			image[i][j] = new uint8_t[3];
			image[i][j][R] = data[i][j].red;
			image[i][j][G] = data[i][j].green;
			image[i][j][B] = data[i][j].blue;
		}
	}
	writeRGBBMP(filename.c_str(), image, ydim, xdim);
}
