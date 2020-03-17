// Hank Wu
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(){
	int cases = 9;
	string number = "";
	string time = "";
	string borrow = "Can borrow for ";
	
	ifstream inFile;
	inFile.open("test.txt");
	if(!inFile){
		cerr << "file invalid";
	}
	
	cout << "Are you a staff, student, or alumni?" << endl;
	
	string user = "";
	cin >> user;
	
	cout << "What would you like to borrow" << endl;
	string type = ";";
	cin >> type;
	
	
	if(user != "alumni"){
		number = "unlimited number";
		time = "without time limits";
		if(type == "journals" || (type == "books" && user == "student")){
			time = "two weeks";
		}
		else if(type == "books"){
			time = "an entire term";
		}
		borrow += time + " and " + number;
	}
	else{
		number = "up to 20 books";
		time = "two weeks";
		if(type != "books"){
			borrow = "Cannot borrow";
		}
			
		}
		
	cout << borrow << endl;
	
system("PAUSE");
return EXIT_SUCCESS;

}
