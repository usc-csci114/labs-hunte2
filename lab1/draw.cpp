#include <iostream>
#include "bmplib.h"
#include "drawing.h"

using namespace std;

int main(int argc, char* argv[])
{
	//use the structs/classes you defined in drawing.h to implement the program in this file
	ColorImage test(100, 100);
	ColorPixel white = {255,255,255};
	for(int i =0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			test.setPixel(white, j, i);
		}
	}


	Drawing drawing;
	drawing.parse("input.txt");
    drawing.draw();
    drawing.write("output.bmp");

	test.render("test.bmp");
}