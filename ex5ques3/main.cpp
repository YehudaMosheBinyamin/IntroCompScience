#include <iostream>
using namespace std;
//calculates sum of digits in a number
int SumOfDigits(int num);
//calculates check digit of ID
int CheckDigit(int num);
//receives a ID without last digit and prints it complete with check digit
int main()
{
	int idNumberChosen;
	cout << "enter your ID:" << endl;
	cin >> idNumberChosen;
	cout << "your full ID is:" <<idNumberChosen<< CheckDigit(idNumberChosen);
	return 0;
}
//calculates sum of digits of number
int SumOfDigits(int num)
{
	int sum = 0;
	int currentDigit = 0;
	while (num > 0)
	{
		currentDigit = num % 10;
		sum += currentDigit;
		num /= 10;
	}
	return sum;
}
//returns check digit for id
int CheckDigit(int num)
{
	int sum = 0;
	int eightDigits = 8;
	int arrDigits[8];
	int arrWeights[8];
	int numDigitsInEach[8];
	for (int j = eightDigits - 1; j >= 0; j--)
	{
		arrDigits[j] = num % 10;
		num /= 10;
	}
	for (int j = eightDigits - 1; j >= 0; j--) 
	{
		if (j % 2 == 0) 
		{
			arrWeights[j] = 1;
		}
		else 
		{
			arrWeights[j] = 2;
		}
	}
	for (int i = 0; i < eightDigits; i++) 
	{
		numDigitsInEach[i] = SumOfDigits(arrDigits[i] * arrWeights[i]);
	}
	for (int i = 0; i < eightDigits; i++) 
	{
		sum += numDigitsInEach[i];
	}
	return 10-(sum%10);//10 minus ones' digit of number is the last digit

	}
//enter your ID :
//12345678
//your full ID is : 123456782