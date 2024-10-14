#include <iostream>
#include "bmplib.h"
#include "shapes.h"

using namespace std;

uint8_t*** newImage(uint8_t bground[3], uint32_t h, uint32_t w)
{
	uint8_t*** img = new uint8_t**[h];
	for(int r=0; r < h; r++) {
		img[r] = new uint8_t*[w];
		for(int c = 0; c < w; c++) {
			img[r][c] = new uint8_t[3];
			img[r][c][0] = bground[0];
			img[r][c][1] = bground[1];
			img[r][c][2] = bground[2];
		}
	}
	return img;
}

Color getColor() {
    Color c;
    cout << "Enter color (R G B): ";
    cin >> c.r >> c.g >> c.b;
    return c;
}

void drawShape(uint8_t*** image, uint32_t h, uint32_t w) {
    string shape;
    cout << "Enter shape (triangle, circle, rectangle) or 'quit' to quit: ";
    cin >> shape;

    if (shape == "quit"){
		return;
	}

    Color color = getColor();

    if (shape == "triangle") {
        Point t[3];
        for (int i = 0; i < 3; ++i) {
            cout << "Enter point coords " << i+1 << " (x y): ";
            cin >> t[i].x >> t[i].y;
        }
        Triangle triangle(t, color);
        triangle.draw(image, h, w);
    } 
    else if (shape == "circle") {
        Point center;
        uint32_t radius;
        cout << "Enter center coords (x y): ";
        cin >> center.x >> center.y;
        cout << "Enter radius: ";
        cin >> radius;
        Circle circle(center, radius, color);
        circle.draw(image, h, w);
    } 
    else if (shape == "rectangle") {
        Point topLeft;
        uint32_t width, height;
        cout << "Enter top left corner coords (x y): ";
        cin >> topLeft.x >> topLeft.y;
        cout << "Enter width and height: ";
        cin >> width >> height;
        Rectangle rectangle(topLeft, width, height, color);
        rectangle.draw(image, h, w);
    } 
    else {
        cout << "Not a valid shape." << endl;
    }
}

int main(int argc, char* argv[])
{
	uint8_t bg[] = {255,255,255};
	uint8_t*** image = newImage(bg, 1024, 1024);
	
	//add your code here
	
	//ask the user what shape the want to draw
	//collect the required information
	//instantiate the shape, draw it into the image
	//loop and ask for another shape, "quit" to stop

	string userInp;
	while(true){
		if (userInp != "quit"){
			drawShape(image, 1024, 1024);
        	cout << "Enter 'quit' to finish or enter a new shape (triangle, circle, rectangle): ";
        	cin >> userInp;
		}
		if(userInp == "quit"){
			return;
			break;
		}
	}
	
	writeRGBBMP("output.bmp", image, 1024, 1024);
}
