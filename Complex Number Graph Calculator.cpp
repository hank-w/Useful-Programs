#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

const double TOL = 1e-3;

double modulusComplex(double real, double imaginary)
{
	return sqrt(pow(real, 2) + pow(imaginary, 2));
}

double angleComplex(double real, double imaginary)
{
	// check if real= 0
	if (fabs(real) < TOL)
	{
		if (imaginary > 0)
			return 90;
		else if (imaginary < 0)
			return 270;
		else
			return -1; // Error
	}
	double angle = atan(fabs(imaginary/real)) * 180 / M_PI;
	
	// quadrant 2
	if (real < 0 && imaginary >= 0)
		angle = 180 - angle;

	// quadrant 3	
	else if (real < 0 && imaginary < 0)
		angle += 180;
		
	// quadrant 4
	else if (real > 0 && imaginary < 0)
		angle = 360 - angle;
	
	return angle;
}


int main()
{
	// 8 test cases
	for (int counter = 0; counter < 8; counter++)
	{
		cout << "Enter the real and imaginary parts of the complex number: "
			 << endl;
		
		double real = 0, imaginary = 0;
		cin >> real >> imaginary;
		
		cout << "The magnitude of the complex number is: " 
			 << modulusComplex(real, imaginary) << endl;
			
		double angle = angleComplex(real, imaginary);
		cout << "The angle of the complex number is: ";
		
		if (angle == -1)
			cout << "N/A" << endl << endl;
		else
			cout << angle << " degrees" << endl << endl;
	}
}

/*
Enter the real and imaginary parts of the complex number:
0 4
The magnitude of the complex number is: 4
The angle of the complex number is: 90 degrees

Enter the real and imaginary parts of the complex number:
0 0
The magnitude of the complex number is: 0
The angle of the complex number is: N/A

Enter the real and imaginary parts of the complex number:
1.5 -2
The magnitude of the complex number is: 2.5
The angle of the complex number is: 306.87 degrees

Enter the real and imaginary parts of the complex number:
20 8.08
The magnitude of the complex number is: 21.5705
The angle of the complex number is: 21.9987 degrees

Enter the real and imaginary parts of the complex number:
1 0
The magnitude of the complex number is: 1
The angle of the complex number is: 0 degrees

Enter the real and imaginary parts of the complex number:
-4 4
The magnitude of the complex number is: 5.65685
The angle of the complex number is: 135 degrees

Enter the real and imaginary parts of the complex number:
-7 0
The magnitude of the complex number is: 7
The angle of the complex number is: 180 degrees

Enter the real and imaginary parts of the complex number:
0 -3
The magnitude of the complex number is: 3
The angle of the complex number is: 270 degrees
*/
