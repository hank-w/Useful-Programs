#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int digit = 0;
void read(int number, int digits[],int &digit){
		for (int i = 10; i >= 0; i--) {
    	digits[i] = number % 10;
    	digit++;
    	number /= 10;
	}
}

bool isPalindrome(int start, int digit, int digits[]){ 
    if(digits[start] == digits[digit]){
    	start++;
    	digit--;
    	isPalindrome(start, digit, digits);
    	if(start == digit)
    		return 1;
	}
	else
		return 0;
    
} 

int main() {
	int number = 0;
	while(number >= 0){
	int digits[10] = {};
	int digit = 0;
	bool palindrome = 0;
	cout << "Enter a number" << endl;
	cin >> number;
	read(number, digits, digit);
	palindrome = isPalindrome(0, digit, digits);
	if (palindrome && number >= 0)
		cout << "Your number is a palindrome" << endl;
	else
		cout << "Your number is not a palindrome" << endl;
	}
	system("PAUSE");
	return 0;
}

