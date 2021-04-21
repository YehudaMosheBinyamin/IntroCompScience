#include <iostream>
#include<vector>
using std::cin;
using std::cout;
using std::endl;

//328972427 A program that receives 10 numbers in ascending order with no duplicates. The program will then ask for a number and will inform the user at which index 
//the number can be found in the original series, if exists. Otherwise it will print "not found"

//to search array quickly for element
int binarySearch(int arr[], int size, int num);
//Returns true if the array is in ascending order.Else returns false
bool InOrder(int arr[], int size);
//returns whether a sequence has a number more than once
bool RepeatingNumbers(int arr[], int size);
int main()
{
	int flag = true;
	int previous = 0;
	int size = 10;
	int arr[10];
	cout << "enter 10 numbers:" << endl;
	int i = 0;	
	do {
		for (int i = 0; i < 10; ++i)
		{
			cin >> arr[i];
		}
		if ((RepeatingNumbers(arr, size) == true)||(InOrder(arr, size) == false))
		{
			cout << "ERROR"<< endl;
			flag = false;
			continue;
		}
		else 
		{
			flag = true;
		}
	} while (flag == false);
	int num;
	cout<< "enter one number"<<endl;
	cin >> num;
	int placement = binarySearch(arr, size, num);
	if (placement != -1)
	{
		cout << "the number " << num << " was found at index " << placement << endl;
	}
	else
	{
		cout << "not found" << endl;
	}
	return 0;
}
bool InOrder(int arr[],int size)
{
	int min = arr[0];
	for (int i = 1; i < size; ++i) 
	{
		if (arr[i] < min)
		{
			return false;
		}
		min = arr[i];
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
int binarySearch(int arr[], int size, int num)
{
	int left = 0, right = size - 1, mid;
	while (left <= right) 
	{
		mid = (left + right) / 2;
		if(num==arr[mid])
		{ 
			return mid;
		}
		else if (num<arr[mid])
		{
			right = mid - 1;
		}
		if (num>arr[mid])
		{
			left = mid + 1;
		}
		
	}
	return -1;//if not found
}
//enter 10 numbers:
//1 3 5 7 9 11 13 15 17 19
//enter one number
//12
//not found
//enter 10 numbers:
//1 3 5 5 9 11 13 15 17 19
//ERROR
//1 3 5 2 9 11 13 15 17 19
//ERROR
//1 3 5 7 9 11 13 15 17 19
//enter one number
//5
//the number 5 was found at index 2
