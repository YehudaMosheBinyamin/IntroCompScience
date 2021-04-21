//Yehuda Binyamin 328972427 program for sum of digits for three digit number
#include <iostream>
using namespace std;
int main()
{
	int num;
	int achadot;
	int asarot;
	int hundreds;
	int sum;
	cout << "enter a three digit number" << endl;
	cin >> num;
	achadot = num % 10;
	asarot = num / 10 % 10;
	hundreds = num / 100;
	sum = achadot + asarot + hundreds;
	cout << "the sum is : " << sum;
	return 0;
}