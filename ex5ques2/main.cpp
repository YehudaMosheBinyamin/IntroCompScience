
#include <iostream>
//idea for algorithm thanks to geeksforgeeks 328972427
using namespace std;
const int DefaultSmaller = 500;
int perfect(int);
void perfects(int i=DefaultSmaller);
//gets a number from user and prints the perfect numbers smaller than it.Then it prints all numbers smaller than DefaultSmaller(500)
int main()
{
	int number;
	cout << "Enter a number" << endl;
	cin >> number;
	perfects(number);
	cout << endl;
	perfects();
	return 0;
}
//checks whether a number is perfect or not
int perfect(int a)
{
	int sum = 0;
	for (int i = 1; i < a - 1; i++)

	{
		if (a % i == 0)
		{
			sum += i;
		}
	}
	if (sum == a) 
	{
		return true;
	}
	else 
	{
		return false;	
	}	
}
//prints perfect number smaller than a
void perfects(int a)
{
	for (int j = 1; j < a; j++)
	{
		if (perfect(j))
		{
			cout << j << " " ;
			
		}
	}
}
//Enter a number
//445
//6 28
//6 28 496
//Enter a number
//3

//6 28 496