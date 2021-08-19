#include <iostream>
using namespace std;
//328972427
void printABs(int);

//Receives a digit to print a string of a's followed by b's in the amount requested by the user.

int main() {
	int num;
	cout << "enter a number:" << endl;
	cin >> num;
	printABs(num);
	return 0;
}

//Uses recursion to print a string of a's followed by a string of b's
void printABs(int timesPrint)
{
	if (timesPrint == 0)
	{
		return;
	}
	cout << "a";
	printABs(timesPrint - 1);
	cout << "b";
}
//enter a number :
//3
//aaabbb