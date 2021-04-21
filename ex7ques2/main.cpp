#include <iostream>
using namespace std;
//Merges three arrays into one array in decreasing order
void MergeArrays(int vectorOne[],int sizeOne, int vectorTwo[],int sizetwo, int vectorThree[],int sizeThree);
//Returns true if there are numbers in array apppearing more than one in the array
bool RepeatingNumbers(int arr[], int size);
//Gets input into array,until 10 elements or until a zero is inserted
int InputIntoArray(int arr[]);
//Checks if the numbers in array are in decreasing order
bool InOrder(int arr[], int size);
//328972427 Program that receives from user 3 arrays of 10 or less elements(until zero is inserted,without that zero) and combines them into a merged nondecreasing array
int main()
{
	int vectorOne[10];
	int vectorTwo[10];
	int vectorThree[10];
	cout << "enter values for the first vector:" << endl;
	int sizeOne=InputIntoArray(vectorOne);
	cout << "enter values for the second vector:" << endl;
	int sizeTwo=InputIntoArray(vectorTwo);
	cout << "enter values for the third vector:" << endl;
	int sizeThree=InputIntoArray(vectorThree);
	cout << "merged array is:" << endl;
	MergeArrays(vectorOne, sizeOne, vectorTwo, sizeTwo, vectorThree, sizeThree);
	return 0;
}
int InputIntoArray(int arr[])
{
	int numElements=0;
	int flag = true;
	int i = 0;
	do {
		for (int i = 0; i < 10; ++i)
		{
			 cin >> arr[i];
			 numElements++;
			 if (arr[i] == 0) 
			 {
				 numElements--;//number of elements is actually lower by one since we don't consider zeroes as valid input
				 break;
			 }
		}

		if (InOrder(arr,numElements) == false||RepeatingNumbers(arr,numElements)==true)
		{
			cout << "ERROR" << endl;
			flag = false;
			numElements = 0;
			continue;
		}
		else
		{
			flag = true;
		}
	} while (flag == false);
	return numElements;
}
void MergeArrays(int vectorOne[],int sizeOne,int vectorTwo[],int sizeTwo, int vectorThree[],int sizeThree)
{
	int i= 0;
	int j = 0;
	int k = 0;
	int m = 0;
	int mergedVector[30];
	
	while ((i < sizeOne) || (j < sizeTwo) || (k < sizeThree))
	{
		if ((vectorOne[i] >= vectorTwo[j]) && (vectorOne[i] >= vectorThree[k])&&(i<sizeOne))
		{	
			mergedVector[m] = vectorOne[i];
			i++;		
		}

		else if ((vectorTwo[j] >= vectorThree[k]) && (vectorTwo[j] >= vectorOne[i])&&(j<sizeTwo))
		{
			mergedVector[m] = vectorTwo[j];
			j++;
		}
		else if(k<sizeThree)
		{
			mergedVector[m] = vectorThree[k];
			k++;
		}
		m++;
	}
	int combinedSize = sizeOne + sizeTwo + sizeThree;
	for (int i = 0; i < combinedSize; ++i) 
	{
		cout << mergedVector[i] << " ";
	}
	cout << endl;
}

bool InOrder(int arr[], int size)
{
	int max = arr[0];
	for (int i = 1; i < size; ++i)
	{
		if (arr[i] > max)
		{
			return false;
		}
		max = arr[i];
	}
	return true;
}
bool RepeatingNumbers(int arr[], int size)
{
	if (size == 0)
	{
		return false;
	}
	for (int p = 0; p < size; p++)
	{
		for (int q = 0; q < size; q++)
		{//if there's an element  in array equal to another element
			if (arr[p] == arr[q] && (p != q))
			{
				return true;
			}
		}
	}
	return false;
}
//enter values for the first vector :
//6 4 2 0
//enter values for the second vector :
//21 19 17 14 13 12 9 6 3 2
//enter values for the third vector :
//3 2 1 0
//merged array is:
//21 19 17 14 13 12 9 6 6 4 3 3 2 2 2 1

//enter values for the first vector :
//4 2 0
//enter values for the second vector :
//5 4 3 3 0
//ERROR
//5 23 0
//ERROR
//4 3 0
//enter values for the third vector :
//7 6 5 4 3 2 1 0
//merged array is:
//7 6 5 4 4 4 3 3 2 2 1