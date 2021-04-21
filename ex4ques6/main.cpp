#include <iostream>
using namespace std;
//328972427 answers yes where each digit is smaller than the one on its right by 1,else no
int main()
{
	int previousDigit;
	int num;
	int flag = true;
	int rightDigit;
	int leftDigit;
	cout << "enter a number:" << endl;
	cin >> num;
	while (num < 0)
	{
		cout << "ERROR" << endl;
		cin >> num;
	}
	while (num !=num%10)
	{
		rightDigit = num % 10;
		num = num / 10;
		if (num > 0)
		{
			leftDigit = num % 10;
			num = num / 10;

			if (leftDigit != rightDigit + 1)
			{
				flag = false;
			}
		}
	}
	if (flag == true)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}