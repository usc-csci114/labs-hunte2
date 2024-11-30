#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <matplot/matplot.h>

using namespace matplot;

int main() {
	
	std::ifstream ifile("atmosphere.txt");
	std::string line;
	std::vector<double> p, h, t;
	//follow the lab instructions to generate task1.png, task2a.png and task2b.png

	getline(std::cin, line);
	getline(std::cin, line);
	getline(std::cin, line);
	getline(std::cin, line);



	while(getline(ifile, line)){
		std::stringstream ss(line);
		double pp, hh, tt;
		ss >> pp >> hh >> tt;
		//getline(std::cin, line);
		p.push_back(pp);
		h.push_back(hh);
		t.push_back(tt);
	}

	double t_min = *std::min_element(t.begin(), t.end());
	double t_max = *std::max_element(t.begin(), t.end());

	auto fig = figure(true);
	plot(h, p, "-b")->line_width(2);
    xlabel("Height (meters)");
    ylabel("Pressure (hPa)");
	grid(on);
	//show();
	//save("task2a.png");
	hold(on);
	plot(h,t, "-rx")->use_y2(true);
	y2lim({t_min, t_max});
	y2label("Temperature (Celsius)");
	save("task2b.png");

	
	
	return 0;
}
