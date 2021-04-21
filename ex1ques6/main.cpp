//Yehuda Binyamin 328972427 
#include <iostream>
using namespace std;
int main()
{
	float x;
	float y;
	float sum;
	float subtraction;
	float multiplication;
	float division;
	cout << "enter two numbers" << endl;
	cin >> x;
	cin >> y;
	sum = x + y;
	cout << x << " + " << y << " = " << sum << endl;
	subtraction = x - y;
	cout << x << " - " << y << " = " << subtraction << endl;
	multiplication = x * y;
	cout << x << " * " << y << " = " << multiplication << endl;
	division = x / y;
	cout << x << " / " << y << " = " << division;
	return 0;
}
