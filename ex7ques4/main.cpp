#include <iostream>
using namespace std;
//Sorts an two dimensional array where each row is a five letter word,according to lexicographical order using bubble sort
void BubbleSort(char arr[10][5]);
//328972427 Receives 10 words of five letters each from user and prints them in correct lexicographical order
int main() 
{
    char words[10][5];
    cout << "enter 10 words:" << endl;
    for (int i = 0; i < 10; ++i) 
    {
        for (int j = 0; j < 5; ++j) 
        {
            cin >> words[i][j];
        }
    }
    BubbleSort(words);
    cout << "after sorting:" << endl;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cout<< words[i][j];
        }
        cout << " ";
    }
    return 0;
}
void BubbleSort(char arr[10][5]) 
{
    bool flag = true;
    int end=9;
    int comparisonLetterIndex=4;
    char temp[6];
    for (comparisonLetterIndex; comparisonLetterIndex >= 0; comparisonLetterIndex--)
    {
        for (end = 9; end > 0; --end)
        {
            flag = false;
            for (int i = 0; i < end; ++i)
            {
                if (arr[i + 1][comparisonLetterIndex] < arr[i][comparisonLetterIndex])
                {
                    flag = true;
                    for (int j = 0; j < 5; ++j)
                    {
                        temp[j] = arr[i][j];
                    }
                    for (int j = 0; j < 5; ++j)
                    {
                        arr[i][j] = arr[i + 1][j];
                    }
                    for (int j = 0; j < 5; ++j)
                    {
                        arr[i + 1][j] = temp[j];
                    }
                }
            }
        }
        comparisonLetterIndex--;
    }
}
//enter 10 words:
//house apple teach array teach books point float apply begin
//after sorting :
//apple apply array begin books float house point teach teach