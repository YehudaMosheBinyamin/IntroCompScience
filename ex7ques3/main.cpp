#include <iostream>
using namespace std;
const int ARR_SIZE = 45;
//Sorts an array of length ARR_SIZE using insertion sort
void SortArray(int arr[ARR_SIZE]);
//328972427 A program that receives 100 numbers and prints a 10*10 matrix where each half is sorted(the diagnal is left as is)
int main()
{
    int arr[10][10];
    cout << "enter 100 numbers" << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> arr[i][j];
        }
    }
    int bottomTriangleArray[45];
    int index = -1;
    for (int i = 1; i < 10; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            index++;
            bottomTriangleArray[index] = arr[i][j];
        }
    }
    int topTriangleArray[45];
    int k = -1;
    for (int i = 0; i < 9; ++i)
    {
        for (int j = i + 1; j < 10; ++j)
        {
            k++;
            topTriangleArray[k] = arr[i][j];
        }
    }
    SortArray(bottomTriangleArray);
    SortArray(topTriangleArray);
    index = -1;
    for (int i = 1; i < 10; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            index++;
            arr[i][j] = bottomTriangleArray[index];
        }
    }
    k = -1;
    for (int i = 0; i < 9; ++i)
    {
        for (int j = i + 1; j < 10; ++j)
        {
            k++;
            arr[i][j] = topTriangleArray[k];
        }
    }
    cout << endl;
    cout << "sorted matrix:" << endl;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
//Sorts using insertion sort
void SortArray(int arr[ARR_SIZE])
{
    int j;
    int temp;
    for (int i = 1; i < 45; ++i)
    {
        j = i - 1;
        temp = arr[i];
        while (temp < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
//enter 100 numbers
//1 11 21 31 41 51 61 71 81 91
//2 12 22 32 42 52 62 72 82 92
//3 13 23 33 43 53 63 73 83 93
//4 14 24 34 44 54 64 74 84 94
//5 15 25 35 45 55 65 75 85 95
//6 16 26 36 46 56 66 76 86 96
//7 17 27 37 47 57 67 77 87 97
//8 18 28 38 48 58 68 78 88 98
//9 19 29 39 49 59 69 79 89 99
//10 20 30 40 50 60 70 80 90 100
//
//sorted matrix:
//1 11 21 22 31 32 33 41 42 43
//2 12 44 51 52 53 54 55 61 62
//3 4 23 63 64 65 66 71 72 73
//5 6 7 34 74 75 76 77 81 82
//8 9 10 13 45 83 84 85 86 87
//14 15 16 17 18 56 88 91 92 93
//19 20 24 25 26 27 67 94 95 96
//28 29 30 35 36 37 38 78 97 98
//39 40 46 47 48 49 50 57 89 99
//58 59 60 68 69 70 79 80 90 100
