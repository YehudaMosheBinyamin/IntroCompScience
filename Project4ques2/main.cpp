//program to input two positive numbers and then input more numbers until one of the following conditions are met:1)the sum of the numbers is bigger than the first number of the amount of numbers inputted is equal to the second number
#include <iostream>
using namespace std;
int main()
{
	int flag = true;
	int sum = 0;
	int count = 0;
	int n1;
	int n2;
	int num;
	cout << "enter 2 positive numbers:" << endl;
	cin >> n1;
	while (n1 <= 0)
	{
		cout << "ERROR" << endl;
		cin >> n1;
	}
	cin >> n2;
	while (n2 <= 0)
	{
		cout << "ERROR" << endl;
		cin >> n2;
	}
	cout << "enter a list of numbers:" << endl;
	while (sum < n1 && count < n2)
	{
		cin >> num;
		sum += num;
		count++;
	}
	cout << sum << endl;
	return 0;
}