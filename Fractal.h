#pragma once

#include <fstream>
#include <iostream>

using namespace std;

class Fractal
{
public:
	void RunApp(void);
	double MaptoReal(int x, int ImageWidth, double minR, double maxR);
	double MaptoImaginary(int y, int ImageHeight, double minI, double maxI);
	int findMandelbrot(double cr, double ci, int max_iteration);
};

