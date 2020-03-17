// Hank Wu
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <fstream>

using namespace std;

int main(){
	double l1 = 0;
	bool all = true;
	int cantReach = 0;
	string done = "";
	double r = 0, x = 0, y = 0;
	
	ifstream inFile;
	inFile.open("A3Actual.txt");
	if (!inFile){
		cerr << "file invalid";
	}
	inFile >> l1;	
	while(inFile >> x >> y){	
		r = sqrt(pow(x, 2) + pow(y, 2));
		if (fabs(r - l1) >= 0.1){
	 		cantReach += 1;
	 		all = false;
		}	
	}
	
	if(all == true){
				cout << "It can reach all points" << endl;
			}
			if(all == false){
				cout << "It can't reach " << cantReach << " points" << endl;
			}
	
	inFile.close();
	system("PAUSE");
	return EXIT_SUCCESS;
	
}


