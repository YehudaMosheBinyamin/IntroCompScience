//328972427
// Calculate formula : X + (-1 / 3)X^3 + (1 / 5)X^5 + (-1 / 7)X^7 + 
// + ((-1) n - 1 / 2n - 1)X^2n -
#include <iostream>
using namespace std;
int main()
{
	int x, n;
	int tempX = 0;
	int place = 0;
	int tempRight = 0;
	int denominatorAndExponent = 0;
	int right=0;//right side of expression;
	float left;
	int sum = 0;
	int divider;
	int dividedNumber;
	int timesBy=0;
	cout << "enter 2 numbers x and then n:" << endl;
	cin >> x;
	cin >> n;
	while (n < 0)
	{
		cout << "ERROR" << endl;
		cin >> n;
	}
	
	for (int i = 0; i < n; i++)
	{   denominatorAndExponent = place * 2 + 1;
		if (place % 2 == 0)
		{
			divider = 1;
			dividedNumber = denominatorAndExponent;
			left = ((float)divider / dividedNumber);
		}
		else
		{
			divider = -1;
			dividedNumber = denominatorAndExponent;
			left = ((float)divider / dividedNumber);
		}

		timesBy = denominatorAndExponent;
		//for right-hand side
		tempX = x;//for every time in j loop the power is calculated using x,without changing x
		int jTempX = x;//for every time in j loop,must be constant value of x on right side
		for (int j = 1; j < timesBy; j++) 
		{
			tempX *= x;
		}
		right = tempX;
		sum += right *left;
		place = place +1;
	}

	cout << sum << endl;
	return 0;
}
