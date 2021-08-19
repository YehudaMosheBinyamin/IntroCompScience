/**
 * @brief A function to swap two elements in an array.
 * @param a An array of integers.
 * @param i An index of an element in a.
 * @param j An index of an element in a
*/
#include <iostream>
using namespace std;
//328972427
/**
 * @brief A function to swap two elements in an array.
 * @param a An array of integers.
 * @param i An index of an element in a.
 * @param j An index of an element in a
*/
void swap(int*& a, int i, int j);
/**
 * @brief A function to reverse the order of an array
 * @param arr An array of integers
 * @param numElements Number of elements in arr
*/
void reverse(int* arr, int numElements);

/**
 * @brief driver code
*/
int main() {
	int* arr;
	int num;
	cout << "enter a number: ";
	cin >> num;
	arr = new int[num];
	cout << "enter array values: ";
	for (int i = 0; i < num; i++)
		cin >> arr[i];

	cout << "before: \n";
	for (int i = 0; i < num; i++)
		cout << arr[i] << " ";
	cout << endl;
	reverse(arr, num);
	cout << "after: \n";
	for (int i = 0; i < num; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
void swap(int*& a, int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;

}


void reverse(int* arr, int numElements)
{
	//Base case: Nothing to reverse if there is only one element or less
	if (numElements<=1)
	{		
		return;
	}
	swap(arr, 0, numElements - 1);
	return reverse(arr + 1, numElements-2);
}
//enter a number : 6
//enter array values : 1 2 3 4 5 6
//before :
	//1 2 3 4 5 6
	//after :
	//6 5 4 3 2 1
