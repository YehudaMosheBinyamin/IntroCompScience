#include <iostream>
using namespace std;
//328972427
//searches how many times an array(vector2) is contained in vector 1
int linearSearch(int vector1[], int sizeOfVector1, int vector2[], int sizeOfVector2);
//Receives two arrays and their sizes from user and prints how many times an array(vector2) is contained in vector 1
//328972427
int main()
{
	int vector1[500] = {0};
	int vector2[1000] = {0};
	int sizeOfVector1Array;
	int sizeOfVector2Array;
	cout << "enter size of first array" << endl;
	cin >> sizeOfVector1Array;
	while (sizeOfVector1Array <= 0)
	{
		cout << "ERROR" << endl;
		cin >> sizeOfVector1Array;
	}
	cout << "enter first array values" << endl;
	for (int i = 0; i < sizeOfVector1Array; i++)
	{
		cin >> vector1[i];
	}

	cout << "enter size of second array" << endl;
	cin >> sizeOfVector2Array;
	while (sizeOfVector2Array <= 0)
	{
		cout << "ERROR" << endl;
		cin >> sizeOfVector2Array;
	}
	cout << "enter second array values" << endl;
	for (int i = 0; i < sizeOfVector2Array; i++)
	{
		cin >> vector2[i];
	}
	cout << "result:" << " " << linearSearch(vector1, sizeOfVector1Array, vector2, sizeOfVector2Array) << " " << "times" << endl;

}
int linearSearch(int vector1[], int sizeOfVector1Array, int vector2[], int sizeOfVector2Array)
{
	int elementsInOrder = 0;//amount of elements that are both in vector2 and vector 1 one after each other
	int numberOfContainment = 0;
	int i = 0;
	int j = 0;
	if (sizeOfVector1Array == 0 || sizeOfVector2Array == 0) 
	{
		return 0;
	}
	do 
	{
		while (vector1[i] != vector2[j]&&i<sizeOfVector1Array)
		{
			i++;
		}
		//checking whether the equality continues for sizeOfVector2ArrayTimes,and incrementing count accordingly
		for (int j = 0; j < sizeOfVector2Array; j++)
		{
			if (vector1[i] == vector2[j])
			{
				elementsInOrder++;
			}				
			i++;
			if (elementsInOrder == sizeOfVector2Array)
			{
				numberOfContainment++;
			}
		}
		i--;//maybe the next sub series of vector2Array in vector1 array starts from the last element of this subseries
		elementsInOrder = 0;
	} while (i < sizeOfVector1Array);
	return numberOfContainment;
}
//enter size of first array
//18
//enter first array values
//6 5 4 3 2 1 6 5 4 3 2 1 6 5 4 3 2 1
//enter size of second array
//4
//enter second array values
//5 4 3 2
//result: 3 times
//enter size of first array
//11
//enter first array values
//1 2 1 2 1 2 1 2 1 2 1
//enter size of second array
//3
//enter second array values
//1 2 1
//result: 5 times
//enter size of first array
//10
//enter first array values
//1 2 3 1 2 3 1 2 3 1
//enter size of second array
//3
//enter second array values
//3 2 2
//result: 0 times