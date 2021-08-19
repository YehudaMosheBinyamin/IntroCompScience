#include <iostream>
using namespace std;
//328972427

/**
 * @brief A recursive function that returns the index of the smallest element between begin and begin+numElements
 * @param arr an array of integers
 * @param numElements number of elements from begin to the end of the array
 * @param begin The index to start searching for the smallest index from. By default it is zero
 * @param minIndex The index where the smallest number of the elements searched so far. By default it is zero
 * @return minIndex
*/
int smallest(int* arr, int numElements,int begin=0,int minIndex=0);


/*Program that receives as many elements as the user wants and prints the smallest element*/
int main() {
	int* arr;
	int num;
	do {
		cout << "enter a number:" << endl;
		cin >> num;
		if (num <= 0)
			cout << "ERROR" << endl;
	} while (num <= 0);
	arr = new int[num];
	cout << "enter array values: ";
	for (int i = 0; i < num; i++)
		cin >> arr[i];
	cout << "the smallest is: " << arr[smallest(arr, num)] << endl;
	delete[] arr;
	return 0;
}


int smallest(int* arr, int numElements,int begin,int minIndex)
{
	if (numElements == 1)
	{
		if (arr[begin] < arr[minIndex])
		{
			minIndex = begin;
		} 
		return minIndex;
	}
	if (arr[begin] < arr[minIndex])
	{
		minIndex = begin;
	}
	return smallest(arr, numElements - 1, begin + 1, minIndex);
}
//enter a number :
//6
//enter array values : 2 4 5 1 5 6
//the smallest is : 1