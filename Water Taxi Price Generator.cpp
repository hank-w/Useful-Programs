#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
	int trip = 0;
	bool dock = 0;
	int stops = 0;
	double distance = 0;
	double cost = 0;
	double totalDist = 0;
	double totalCost = 0; 
	double x = 0;
	double y = 0;
	double x1 = 0;
	double y1 = 0;
	double longest = 0;
	double cheapest = 10000;
	//assume the cost of at least one water taxi is less than 10000 
	
	
	ifstream inFile;
	inFile.open("taxi.txt");
	ofstream outFile;
	outFile.open("info.txt");
	if (!inFile){
		cout << "file invalid" << endl;
	}
	else{
	outFile << "Trip" << setw(10) << "Return" << setw(10) << "Stops" 
	<< setw(15) << "Distance" << setw(10) << "Cost" << setw(16) << "Cumulative" 
	<< setw(16) << "Cumulative" << endl	<< setw(65) << "Distance" 
	<< setw(16) << "Cost" << endl;
	
	 	
	while(inFile >> dock >> stops){
		trip += 1;
		distance = 0;
		cost = 0;
		x1 = 0;
		y1 = 0;
	for(int i = 0; i < stops; i++){
			inFile >> x >> y;
			distance += sqrt(pow(x-x1, 2) + pow(y-y1 , 2));	
			x1 = x;
			y1 = y;			
	}
		if(dock){
			distance += sqrt(pow(x , 2) + pow(y , 2));
		}
		if(distance > longest){
			longest = distance;	
		}
		
			cost = 12.00*stops + 2.30*distance;
		if(cost < cheapest){
			cheapest = cost;
		}
	
		totalDist += distance;
		totalCost += cost;
		if(trip <= 5 || (trip - 5) % 10 == 0){

		outFile << fixed << setprecision(2) << setw(5) << trip << setw(10) 
		<< dock << setw(10) << stops << setw(15) 
	<< distance << setw(10) << cost << setw(16) << totalDist 
	<< setw(16) << totalCost << endl;
}
	
}
	outFile << "August Cumulative Distance: " << totalDist << endl 
	<< "August Amount Collected: " << totalCost << endl
	<< "Length of Longest Trip: " << longest << "km" << endl
	<< "The Cost of Least Expensive Trip: " << cheapest << endl;
	
	
	system("PAUSE");
	return EXIT_SUCCESS;
	inFile.close();
}
}



