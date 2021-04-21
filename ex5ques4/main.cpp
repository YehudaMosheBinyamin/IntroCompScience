#include <iostream>
#include <ctime>
#include <cstdlib>
#include<cmath>
using namespace std;
//328972427
//returns if a number is prime or not
int isPrime(int a);
//find the closest prime to a number
int findPrime(int a);
//Receives an integer to determine table size-the closest prime number to the number inputted(the same number or a bigger prime number),
//if input is negative the integer will be a prime number same or larger than a random number between 10 to 100
int main()
{
	srand((unsigned)time(NULL));
	int num;
	cout << "enter number of values" << endl;
	cin >> num;
	if (num < 0)
	{
		num = (rand() % (100-10+1) + 10);//random number between 10 to 100

	}
	cout << "table size:" << findPrime(num) << endl;
	return 0;
}

int isPrime(int a)
{
	int flag = true;
	for (int i = 2; i < a; i++)
	{
		if ((a % i) == 0)
			flag = false;

	}
	return flag;
}

int findPrime(int a)
{

	int falseOrTrue = isPrime(a);
	while (falseOrTrue == false)
	{
		a++;
		falseOrTrue = isPrime(a);
	}


	return a;
}
//enter number of values:   
//25
//table size : 29
//enter number of values:   
//-1
//table size : 97//(Random,will change depending on time program run)
//enter number of values :
//11
//table size : 11


