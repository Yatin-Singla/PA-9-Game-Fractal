#include "Fractal.h"

//while (x*x + y*y < 2 * 2 AND iteration < max_iteration)
//{
//	xtemp = x*x - y*y + x0
//		y= 2*x*y + y0
//		x = xtemp
//		iteration = iteration +1
//}

void Fractal::RunApp(void)
{
	//get the required input values from files...
	ifstream fin("input.txt");
	int imgWidth, imgHeight, maxN;
	double minR, maxR, minI, maxI;
	if (!fin)
	{
		cout << "couldn't open the file!" << endl;
		cin.ignore();
		return;
	}
	fin >> imgWidth >> imgHeight >> maxN;
	fin >> minR >> maxR >> minI >> maxI;
	fin.close();
	//open the oput file/ SFML file , write the PPM master
	ofstream fout("output_image.ppm");
	fout << "P3" << endl;
	fout << imgWidth << " " << imgHeight << endl; //dimensions
	fout << "256" << endl; //Max value of pixel RGB value	
	
	for (int y = 0; y < imgHeight; y++)//row
	{
		for (int x = 0; x < imgWidth; x++)//Pixels in a row
		{
			//for every pixel find imaginary and real values of c,.....
			//...corresponding to that x,y pixel in the image
			double cr =  MaptoReal(x, imgWidth, minR, maxR);//real imaginary number for c
			double ci = MaptoImaginary(y, imgHeight, minI, maxI);
			//find the number of iterations in the Mandelbrot formula (using c)
			int n = findMandelbrot(cr, ci, maxN);
			//map the number of iterations to an RGB value
			int r = ((int)(n*sinf(n)) % 256);//can change to different values for interesting values
			int g = (n*n % 256);
			int b = (n*3 % 256);


		//output it to the image
			fout << r << " " << g << " " << b << " " ;
		}
		fout << endl;
	}
	fout.close();
	cout << "Finished!" << endl;
	return;
}

double Fractal::MaptoReal(int x, int ImageWidth, double minR, double maxR)
{
	double range = maxR - minR;
	//[0, width]
	//[0, maxR - minR] - val * Range / width
	//[minR, maxR] - last step +minR
	return x*(range / ImageWidth) + minR;
}
double Fractal::MaptoImaginary(int y, int ImageHeight, double minI, double maxI)
{
	double range = maxI - minI;
	return y*(range / ImageHeight) + minI;
}

int Fractal::findMandelbrot(double cr, double ci, int max_iteration)
{
	int i = 0;
	double zr = 0.0, zi = 0.0; 
	while (i < max_iteration && (zr*zr + zi*zi < 4.0))
	{
		double temp = zr*zr - zi*zi + cr;
		zi = 2.0*zr*zi + ci;
		zr = temp; 
		i++;
	}
	return i;
}