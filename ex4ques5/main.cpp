#include <iostream>
using namespace std;
//Prints a right triangle for single digit positive number
int main()
{
	int num;
	int flag;
	flag = false;
	int count = 0;
	cout << "enter a one digit number" << endl;
	cin >> num;
	while (num > 9 || num < 0)
	{
		cout << "ERROR" << endl;
		cin >> num;
	}

	int numSpaces = 0;
	int tempNum = num;
	for(int i=0;i<num;i++)
	{
		for (int i = 0; i < numSpaces; ++i) 
		{
			cout << "  ";
		}
		for (int i = tempNum; i > 0; i--)
		{
			if(i>1)
		    {
			cout << i << ",";	
		    }
			else 
			{
				cout << i;
			}
			
		}

		tempNum--;
		numSpaces++;
		cout << endl;
	
	}

	return 0;
}