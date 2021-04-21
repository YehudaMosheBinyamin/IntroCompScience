//basic swap program between two numbers 328972427
#include<iostream>
using namespace std;
int main()
{
	float x;
	float y;
	cout << "enter two numbers" << endl;
	cin >> x;
	cin >> y;
	cout << "x=" << x << "," << "y=" << y << endl;
	float temp;
	temp = x;
	x = y;
	y = temp;
	cout << "x=" << x << "," << "y=" << y << endl;
	return 0;
}