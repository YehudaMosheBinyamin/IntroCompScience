//Yehuda Moshe Binyamin 328972427
//X + (-1 / 3)X3 + (1 / 5)X5 + (-1 / 7)X7 + //. + ((-1) n - 1 / 2n - 1)X2n -
#include <iostream>
using namespace std;
int main()
{
	int x, n;
	int place = 0;
	float num;
	float num2;
	float right;
	float left;
	float sum = 0.0;
	float divider;
	float dividedNumber;
	cout << "enter 2 numbers:" << endl;
	cin >> x;
	cin >> n;
	while (n < 0)
	{
		cout << "ERROR" << endl;
		cin >> n;
	}
	for (int i = 0; i <= n; i++)
	{
		if ((place % 2 == 0) || (place == 1))
		{
			divider = 1;
			dividedNumber = place + 2;
			left = (divider / dividedNumber);
		}
		else
		{
			divider = -1;
			dividedNumber = place + 2;
			left = (divider / dividedNumber);
		}
		for (int j = 0; j <= i; j++)
		{
			right = x * (place + 1);
			place = place + 2;
			sum = right + left;
		}
	}
	cout << sum << endl;
	return 0;
}
