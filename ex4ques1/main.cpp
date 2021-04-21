//328972427
#include <iostream>
using namespace std;
#include <cstdlib>
#include<ctime>
//Program that prints a series of 10 random numbers between 1 to 1000(including) and prints whether the series is sorted or not
int main() 
{
	srand((unsigned)time(NULL));
	int n = 10;
	int flag = true;
	int previousNum=0;
	int num;
	for (int i = 0; i < 10; i++)
	{
		num = (rand() % (1000-0) + 1);
		if (num < previousNum)
		{
			flag = false;
		}
		std::cout << num<<" ";
		previousNum = num;
	}
    std::cout <<endl;
	if (flag == false)
	{
		cout << "not sorted list" << endl;
	}
	else
	{
		cout << "sorted list" << endl;
	}
	return 0;
}