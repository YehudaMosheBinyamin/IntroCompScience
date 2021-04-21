#include <iostream>
using namespace std;
void eraseRepeatingNumbers(int arr[], int size);
//328972427
//Makes an array contain only one of each element
int main()
{
	int size = 0;
	int arr[100] = { 0 };
	cout << "enter  up to 100 values, to stop enter 0" << endl;
	int i = 0;
	int count=0;//so we know where the array ends
	int temp = -1;//what the previous arr[i] was so we know when to stop the input
	for (int i = 0; i < 100 && temp != 0; i++)
	{
		cin >> arr[i];
		temp = arr[i];
		count++;
	}
	size = count - 1;
	eraseRepeatingNumbers(arr, size);
	return 0;
}
//Makes an array where each element is found inside only once
void eraseRepeatingNumbers(int arr[], int size)
{
	for (int p = 0; p < size; p++)
	{
		for (int q = 0; q < size; q++)
		{//if there's an element later on in array equal to another element
			if (arr[p] == arr[q]&&(p!=q))
			{
				    int min = (p < q)?q:p;
					//delete extraneous element by making all elements move to the left by one
					for (int s=min; s <= size - 2; s++)
					{
						arr[s] = arr[s + 1];
					}
					size--;//the size decreases by one because we removed an extraneous element
			}
		}
	}
	cout << "the new vector is" << endl;
	for (int s = 0; s < size; s++)
	{
		cout << arr[s]<<" ";
	}

	cout << "the number of elements:" << size << endl;
}
//enter  up to 100 values, to stop enter 0
//2 8 9 6 4 1 4 5 8 4 5 9 6 5 8 4 7 0
//the new vector is
//2 8 9 6 4 1 5 7 the number of elements : 8
