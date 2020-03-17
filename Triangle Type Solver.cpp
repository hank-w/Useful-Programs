// Hank Wu

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
	cout << "Input the three sides of your triangle" << endl;
	int a = 0, b = 0, c = 0;
	
    cin >> a >> b >> c;
	
	bool ab = false;
	bool bc = false;
	bool ac = false; 
	
	string type = "";
	
	if(fabs(a-c) < 0.001){
		ac = true;
	}
	if(fabs(a-b) < 0.001){
		ab = true;
	}
	if(fabs(b-c) < 0.001){
		bc = true;
    }
    
	if(a + b < c || a + c < b || b + c < a){
		type += "Invalid";
	}
	
	else{

	if(pow(a,2) + pow(b, 2) == pow(c, 2) || pow(c,2) + pow(a, 2) == pow(b, 2) || pow(c,2) + pow(b, 2) == pow(a, 2)) {
		type += "Right angle, ";
	}
	if(ab == true && ab == bc){
		type += "Equilateral ";
		type += "and Isosceles";
	}
	else if(ab == true || bc == true || ac == true){
		type += "Isosceles";
	}
	else{
		type += "Scalene";
	}
}
	cout << "Your triangle is: " << type << endl;
	
	system("PAUSE");
	return EXIT_SUCCESS;
}

/*
Input the three sides of your triangle
1
2
5
Your triangle is: Invalid

Input the three sides of your triangle
3
3
3
Your triangle is: Equilateral and Isosceles

Input the three sides of your triangle
2
2
3
Your triangle is: Isosceles

Input the three sides of your triangle
5
6
7
Your triangle is: Scalene

Input the three sides of your triangle
5
12
13
Your triangle is: Right angle, Scalene
*/

