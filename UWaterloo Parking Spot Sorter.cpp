#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

int main(){

int votes[6] = {};
int spoiled = 0;
int vote = 0;
string candidates[6] = {};
string name = "";
int max = 0;
int winner = 0;
bool done1 = 0;

ifstream inFile("vote1.txt");
ofstream outFile("election.txt");

if(!inFile){
	cout << "File not found";
	return EXIT_FAILURE;
}

for(int i = 0; i < 6; i++){
	inFile >> name;
	candidates[i] = name;
} 

while(inFile >> vote && done1 == 0){
	if(votes[vote-1] < 30000){
		if(vote > 6 || vote < 1)
			spoiled++;
		else{
			votes[vote-1]++;
		}	
	}
	else{
		done1 = 1;
	}
}

outFile << "RESULTS:" << endl;
 
for(int i = 0; i < 6; i++){
	outFile << candidates[i] << ": " << votes[i] <<  endl;
	if(max < votes[i]){
	max = votes[i]; 
	winner = i;
	}	
}

outFile << endl << "Winner: " << candidates[winner] << endl << spoiled << " spoiled ballots"; 	

inFile.close();
outFile.close();
system("PAUSE");
return EXIT_SUCCESS;
}
