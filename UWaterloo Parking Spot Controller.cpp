#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

// string parkingName[], bool avalible[], bool status[]
void dataCollect(ifstream);

//b
void dataCollect(ifstream &inFile, bool status[], string names[], bool avail[]){
	bool staff = 0;
	string name = "";
	int slot = 0;
	int index = 0;
	
	while(inFile >> staff){
		status [index] = staff;
		inFile >> name;
		names[index] = name;
		inFile >> slot;
		 avail[slot] = 0;
		 index++;
	}
}

//c)
void populate(ifstream &inFile1, string names[], bool status[], bool avail[])
{
bool staff = 0;
string name = "";
for(int i = 0; i <= 50; i++){
	if(avail[i] == 1){
		inFile1 >> staff >> name;
		names[i] = name;
		status[i] = staff;
	}
}

}

//d)
void remove(string names[], bool avail[], string &name)
{
for(int count = 0; count < 50; count++){
if(names[count] == name)
avail[count] = 1;
names[count] == "";
}
}



//e
int bestSpace(bool status, bool available[]){
	bool found = 0;
	int index = 0;
	if(status == 1){
		while(found == 0 || index <= 50){
			if(available[index] == 1){
				return index;
				found = 1;
			}
			index++;
		}
}
	
	else{
		index = 26;
		while(found == 0 || index <= 50){
			if(available[index] == 1){
			return index; 	
			found = 1;
		}
		index++;
	}
	}
	if(index >= 50)
		return -1;

}

//f)
void assign(string names[], bool avail[], string &name, bool status0)
{
int space = 0;
space = bestSpace(status0, avail);
if(space != -1)
{
names[space] = name;
avail[space] = 0;
}
}

//g
void moveSpots(bool avail[], bool status[], string names[]){
	bool freeSpot[25] = {false};
	int freeSpots = 0;
	int assigned = 25;
	for(int i = 0; i < 25; i++){
		if(avail[i] == true)
			freeSpot[i] == 1;
	}
	
	for(int i = 26; i < freeSpots; i++){
		if(avail[i] == 0 && status[i] == 1){
			assign(names, avail, names[i], status[i]);
			remove(names, avail, names[i]);
			freeSpots--;
		}
	}	
	if(freeSpots > 0){
		for(int i = 26; i < freeSpots; i++){
		if(avail[i] == 0){
			assign(names, avail, names[i], status[i]);
			remove(names, avail, names[i]);
			freeSpots--;
		}	
	}
}
}

//h)
void fileCreate(ofstream &outFile, string names[], bool status[], bool avail[])
{
	/*
	int count = 0;
	cout << names;
	for(int i = 0;i < sizeof(names);i++){
		if(names[i] == ""){
			count = i;
			i = 1000;
		}
	}
	while(count >= 0){
	outFile << status[count] << " " << names[count] << " " << count << endl;
	count--;
	}
	*/
	
	int count = 0;
	while((count < 50) && (outFile << status[count] << " " << names[count] << " " << count << endl))
	count++;
	outFile << 0 << "  " << 50;
	
}

int main()
{
	string names[50] = {};
	bool status[50] = {};
	bool avail[50] = {true};
	ifstream inFile("parking_current.txt");
	ifstream inFile1("parking_add.txt");
	ifstream inFile2("parking_remove.txt");
	ofstream outFile("parking_new.txt");
	if(!inFile || !inFile1 || !inFile2)
	{
	cout << "FILE NOT FOUND";
	return EXIT_FAILURE;
	}
	dataCollect(inFile,status,names,avail);
	string add[25] = {};
	bool addStatus[25] = {0};
	bool lastStatus = 0;
	string removeable = "";
	while(inFile2 >> lastStatus){
	inFile2 >> removeable;	
	remove(names, avail, removeable);
}
	populate(inFile1, names, status, avail);
	moveSpots(avail, status, names);
	
	fileCreate(outFile, names, status, avail);
	system("PAUSE");
	return EXIT_SUCCESS;

}

/*
0 Hmeidan_Amer 0
1 Manezes_Alfred 1
0 Barakat_Abdullah 2
1 Bedi_Sanjeev 3
1 Davison_Dan 4
0 Tan_Mark 5
0 Lung_Ian 6
1 McKillop_Bob 7
1 Pritzker_Mark 8
0 Roller_Anika 9
1 Fluid_Newtonian 10
0 Hamza_Muhammad 11
0 Starratt_Kathryn 12
0 Belisle_Matt 13
0 Wang_Willian 14
1 Xie_Wei-Chau 15
1 Davidson_George 16
1 Tuncel_Levent 17
0 Malloch_Jeremy 18
0 Huot_Isabella 19
0 Mills_Joel 20
0 Jasmine_Princess 21
0 Zheng_Tim 22
0 Yousufzay_Namoos 23
0 Lau_Darren 24
0 Lau_Amanda 25
0 Paik_Chad 26
1 Gryguc_Andrew 27
0  28
0  29
0  30
0  31
0  32
0  33
0  34
0  35
0  36
0  37
0  38
0  39
0  40
0  41
0  42
0  43
0  44
0  45
0  46
0  47
0  48
0  49
0  50
*/
