#include <iostream>
using namespace std;
//Function that receives an array with floating point numbers and sorts them in ascending order
void SortArray(float arr[], int arraySize = 6);

//Prints the index array of an array
void PrintIndexArray(float arr[], int arraySize=6);

//Function that initializes an array
int* InitializeArray(int arr[], int arraySize = 6);

//328972427 Program that Receives a float array and prints the place of every element in array from smallest to largest in the unsorted array
int main(void) 
{
    float arr[6];
    bool inputFlag = true;
    cout << "enter 6 numbers between 0 to 1:" << endl;
    do{
        for (int i = 0; i < 6; ++i)
        {
            cin >> arr[i];
            if ((arr[i]<=0.0) ||(arr[i]>=1.0)) 
            {
                inputFlag = false;
                cout << "ERROR" << endl;
                break;
            }
            else 
            {
                inputFlag = true;
            }
      }
    } while (inputFlag == false);
    PrintIndexArray(arr);
    return 0;
}
void SortArray(float arr[], int arraySize)
{
    int flag = 1;
    int end = arraySize - 1;
    while (flag == 1 && end > 0)
    {
        flag = 0;
        for (int i = 0; i < end; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                float temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                flag = 1;
            }
        }
        end--;
    }
}
int* InitializeArray(int arr[], int arraySize) 
{
    for (int i = 0; i < arraySize; ++i) 
    {
        arr[i] = 0;
    }
    return arr;
}

void PrintIndexArray(float arr[], int arraySize)
{
    float oldArray[6];
    for (int i = 0; i < 6; ++i) 
    {
        oldArray[i] = arr[i];
    }
    SortArray(arr);
    int indices[6];
    InitializeArray(indices, 6);
    for (int i = 0; i < 6; ++i)
    {
        indices[i] = 0;
    }
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (arr[i]==oldArray[j])
            {
                indices[i] = j;
            }
        }
    }
    cout << "ordered indices:" << endl;
    for (int i = 0; i < 6; ++i)
    {
        cout << indices[i] << " ";
    }
}
//enter 6 numbers between 0 to 1:
//0.9 0.05 0.1 0.4 0.2 0.3
//ordered indices:
//1 2 4 5 3 0
//enter 6 numbers between 0 to 1:
//0.9 0.5 2.7 0.9 0.05 0.1 0.4 0.2 0.3
//ERROR
//ordered indices:
//1 2 4 5 3 0
//(NO INPUT)
//enter 6 numbers between 0 to 1:
//