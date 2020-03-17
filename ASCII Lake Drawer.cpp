#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

void storeDepths(ifstream & inFile, int depths[82][78]){
	int depth = 0;
	int row = 0;
	int col = 0;
	
	while(inFile >> depth){
		depths[row][col] = (depth*0.1);
		col++;
		if(col % 78 == 0)
			row++;
	}
}

void drawLake(int depths[82][78], int seaLevel){
	for(int i = 0; i <= 82; i++){
		for(int j = 0; j <= 78; j++){
			if(depths[i][j] < seaLevel)
				cout << "w";
			else
				cout << "l";
		}
		cout << endl;
	}
}

void getAreaVolumne (int depths[82][78], double seaLevel){
	double surfaceArea = 0;
	double volumne = 0;
	for(int i = 0; i <= 82; i++){
		for(int j = 0; j <= 78; j++){
			if(depths[i][j] < seaLevel)
				surfaceArea++;
				volumne += depths[i][j] - seaLevel;	
		}		
	}
	cout << "The Surface Area below boundary is" << surfaceArea/100 << "m^2" << endl;
	cout << "The Volumne below boundary is" << volumne/100 << "m^3" << endl;	
}

int highLow(int depths[82][78], bool land){
	if(land == 1){
		int highest = 0;
		int highest_x = 0;
		int highest_y = 0;
		for(int i = 0; i <= 82; i++){
			for(int j = 0; j <= 78; j++){
			if(depths[i][j] > highest){
				highest = depths[i][j];
				highest_x = i;
				highest_y = j;	
			}
			}		
		}
		cout << "The coordinates of the highest elevation is (" << highest_x <<
		"," << highest_y << ")" << endl;  	
	}
	
	else{
		int deepest = 0;
		int deepest_x = 0;
		int deepest_y = 0;
		for(int i = 0; i <= 82; i++){
			for(int j = 0; j <= 78; j++){
			if(depths[i][j] < deepest){		
				deepest = depths[i][j];
				deepest_x = i;
				deepest_y = j;	
			}
			}		
		}
		cout << "The coordinates of the deepest depth is (" << deepest_x <<
		"," << deepest_y << ")" << endl;  	
		
	}	
}

int main() {
	int depths[82][78] = {};
	ifstream inFile("depths.txt");
	if(!inFile){
		cout << "FILE NOT FOUND";
		return -1;
	}
	
	storeDepths(inFile, depths);
	getAreaVolumne(depths, 0);
	getAreaVolumne(depths, -2.50);
	drawLake(depths,0);
	
	system("PAUSE");
	return 0;
	inFile.close();
}



