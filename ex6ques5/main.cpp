#include <iostream>
using namespace std;
//328972427 Calculates set difference of two arrays of positive numbers. If the difference set is empty, an appropriate message will be printed
int main(void)
{
    int firstArray[6];
    int countOnlyInFirst = 6;
    cout << "enter first 6 numbers:" << endl;
    for (int i = 0; i < 6; ++i) 
    {
        cin >> firstArray[i];
       while (firstArray[i] <= 0) 
        {
            cout << "ERROR" << endl;
            cin >> firstArray[i];
        }
    }
    int secondArray[6];
    cout << "enter next six numbers:" << endl;
    for (int i = 0; i < 6; ++i)
    {
        cin >> secondArray[i];
        while (secondArray[i] <= 0)
        {
            cout << "ERROR" << endl;
            cin >> secondArray[i];
        }
    }
    for (int i = 0; i < 6; ++i) 
    {
        for (int j = 0; j < 6; ++j) 
        {
            if (firstArray[i] == secondArray[j]) 
            {
                firstArray[i] = -1;
                countOnlyInFirst--;
            }
        }
        
    }
    if (countOnlyInFirst > 0)
    {
        cout << "set difference is:" << endl;
        for (int i = 0; i < 6; ++i)
        {
            if (firstArray[i] != -1)
            {
                cout << firstArray[i]<<" ";
            }
        }
    }
    else 
    {
        cout << "set difference is:" << endl;
        cout << "empty" << endl;
    }
    return 0;
}
//enter first 6 numbers:
//10 9 7 5 3 1
//enter next six numbers :
//6 5 4 3 2 1
//set difference is :
//10 9 7
//enter first 6 numbers:
//10 9 7 5 3 1
//enter next six numbers :
//1 3 5 7 9 10
//set difference is :
//empty