#include<iostream>
using namespace std;
//receives SIZE numbers from user and determines whether series contains all numbers from 1 to 15
int main()
{
	bool properSeries = true;
	cout << "enter 15 numbers:" << endl;
	const int SIZE = 15;
	int arr[SIZE] = {0};
	//receiving input
	for (int i = 0; i < 15; i++)
	{

			cin >> arr[i];
	}
	//array containing all numbers between 1 to 15 and(0 that won't be used)(0 is for ease of writing the code,so that the element at ith cell of matrice is i
	int found[SIZE+1] = {0,1,2,3,4,6,7,8,9,10,11,12,13,14,15};
	for (int i = 0; i < 15; i++)
	{      
		if ((arr[i] >= 1) && (arr[i] <= 15))
		{//each time an element is found its cell will be worth zero is found array
			found[arr[i]] = 0;
		}
	}

	for (int i = 1; i < 16; i++)
	{//if n element isn't zero it hasn't been found at all so the series doesn't have all numbers from 1 to 15
		if (found[i] != 0)
		{
			properSeries = false;
		}
	}

	if (properSeries == true)
	{
		cout << "GOOD" << endl;
	}
	else
	{
		cout << "NOT GOOD" << endl;
	}


	return 0;
}
//enter 15 numbers:
//15 8 9 7 1 3 4 2 10 14 6 5 13 12 11
//GOOD
//enter 15 numbers:
//15 8 9 16 1 3 4 2 10 14 6 5 13 12 11
//NOT GOOD


