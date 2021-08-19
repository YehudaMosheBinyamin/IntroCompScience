#include <iostream>
using namespace  std;
//328972427
/**
 * @brief A function to swap two elements in an array.
 * @param a An array of integers.
 * @param i An index of an element in a.
 * @param j An index of an element in a
*/
void swap(int* &a, int i, int j);

/**
 * @brief A recursive function that returns the index of the smallest element between begin and begin+numElements
 * @param arr an array of integers
 * @param numElements number of elements from begin to the end of the array
 * @param begin The index to start searching for the smallest index from. By default it is zero
 * @param minIndex The index where the smallest number of the elements searched so far. By default it is zero
 * @return minIndex
*/

int smallest(int* arr, int numElements, int begin=0, int minIndex=0);
/**
 * @brief A recursive function that sorts an array of integers using selection sort
 * @param arr An array of integers.
 * @param numElements The number of elements in the array.
 * @param currentIndex the index to start the sorting from. Is 0 by default.
*/
void sort(int* arr, int numElements,int currentIndex=0);
int main()
{
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
	cout << "before: \n";
	for (int i = 0; i < num; i++)
		cout << arr[i] << " ";
	cout << endl;
	sort(arr, num);
	cout << "after: \n";
	for (int i = 0; i < num; i++)
		cout << arr[i] << " ";
	cout << endl;
	delete [] arr;
	return 0;
}

void swap(int* &a, int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;

}
int smallest(int* arr, int numElements, int begin, int minIndex)
{
	//Base case:if there is only one element,either it or the previously found minimum is the smallest element
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
void sort(int* arr, int numElements, int currentIndex)
{
	//base case:an empty array needs no sorting
	if (numElements == 0)
	{
		return;
	}
	int minIndex = smallest(arr, numElements, currentIndex,currentIndex);	
	swap(arr,currentIndex, minIndex);
	return sort(arr, numElements-1, currentIndex + 1);
}
//enter a number :
//6
//enter array values : 2 5 7 5 3 1
//before :
	//2 5 7 5 3 1
	//after :
	//1 2 3 5 5 7