//using dynamic array of pointers
//pointer->aray of size given by user->each a pointer to a arbitrarily lengthed array.

#include <iostream>
using namespace std;
#include <cstring>
void newStr(char**& words, int& numWords, char* newWord);
void deleteStr(char**& words, int& numWords, char* newWord);
char* searchStr(char** words, int numWords, char* newWord);
void printChar(char** words,  int numWords, char letter);
void printAll(char** words,  int numWords);
void LexicographicalBubbleSort(char**& arr, int numWords);
int main(void)
{
    char** words = NULL;
    int numWords = 0;
    char* newWord = new char[80];
    char* foundWord = NULL;
    char letter;
    int choice = 5;
    do {
        cout << "enter 0-5" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "enter the word: " << endl;
            cin.ignore();
            cin.getline(newWord, 80);
            newStr(words, numWords, newWord);
            cout << words[0] << endl;
            if (numWords > 1)
            {
                cout << words[1] << endl;
            }
            break;
        case 1:
            cout << "enter the word to delete:" << endl;
            cin.ignore();
            cin.getline(newWord, 80);
            deleteStr(words, numWords, newWord);
            break;
        case 2:
            cout << "enter the word to search for:" << endl;
            cin.ignore();
            cin.getline(newWord, 80);
            foundWord = searchStr(words, numWords, newWord);
            if (!foundWord)
            {
                cout << "not found" << endl;
            }
            else
            {
                cout << "found" << endl;
            }
            break;
        case 3:
            cout << "enter the char:" << endl;
            cin >> letter;
            printChar(words, numWords, letter);
            break;
        case 4:
            printAll(words,numWords);
            break;
        case 5:
            break;
        default:
            cout << "ERROR" << endl;

        }
    } while (choice != 5);

    //free array of pointers
    for (int i = 0; i < numWords; ++i)
    {
        delete[] words[i];
    }

    //free pointer to array of pointers
    delete[] words;

    return 0;
}

void newStr(char**& words, int& numWords, char* newWord)
{
    if (numWords == 0)
    {
        numWords+=1;
        words = new char* [numWords];
        for (int i = 0; i < numWords; ++i)
        {
            words[i] = new char[strlen(newWord) + 1];
        }
        for (int i = 0; i < strlen(newWord) + 1; ++i)
        {
            words[numWords - 1][i] = newWord[i];
        }
    }
    else
    {
        numWords+=1;
        char** newArrWords = new char* [numWords];//before +1
        for (int i = 0; i < numWords-1; ++i)//before without -1
        {
            cout << "FIRST TEST:STRLEN OF ELEMENT" << i << strlen(words[i]) << endl;
            newArrWords[i] = new char[strlen(words[i])+1];
        }
        cout << "LETS PRINT NEW WORD!" << endl;
        cout << newWord << endl;
        cout << "FOR NEW WORD!" << strlen(newWord) + 1 << endl;
        newArrWords[numWords - 1] = new char[strlen(newWord)+1];//for new element

        //copy old elements to new array
        for (int i = 0; i < numWords - 1; ++i)
        {
            cout << "STRLEN OF ELEMENT" << i << strlen(words[i]) << endl;
            for (int j = 0; j < strlen(words[i])+1; ++j)
            {
                *(*(newArrWords + i) + j) = *(*(words + i) + j);
            }
        }

        //copy new element
        for (size_t j = 0; j < strlen(newWord) + 1; ++j)
        {
            newArrWords[numWords - 1][j] = newWord[j];
        }

        for (int i = 0; i < numWords - 1; ++i)
        {
            delete[] words[i];
        }
        delete[] words;
        words = newArrWords;
        LexicographicalBubbleSort(words, numWords);
    }
}
/**
 * @brief Deletes a word from dictionary
 * @param words 
 * @param numWords 
 * @param deletedWord 
*/
void deleteStr(char**& words, int& numWords, char* deletedWord)
{
    int indexNotToCopy = -1;
    for (int i = 0; i < numWords; ++i)
    {
        if (strcmp(*(words + i), deletedWord) == 0)//if deleted word found
        {
            indexNotToCopy = i;
            char** tempWords = new char* [numWords - 1];
            //initialize new array of pointers
            for (int i = 0; i <numWords - 1; ++i)
            {
                *(tempWords + i) = new char[strlen(*(words + i)) + 1];
            }

            //copy from old array to temp array
            for (int i = 0; i <indexNotToCopy; ++i)
            {
               
                    for (int j = 0; j < strlen(*(tempWords + i) + 1); ++j)
                    {
                        *(*(tempWords + i) + j) = *(*(words + i) + j);
                    }  
            }
            for (int i=indexNotToCopy+1;i<numWords-1;++i)
            {

                for (int j = 0; j < strlen(*(tempWords + i) + 1); ++j)
                {
                    *(*(tempWords + i) + j) = *(*(words + i) + j);
                }
            }

            for (int i = 0; i < numWords-1; ++i)
            {
                delete[] words[i];
            }
            delete[] words;
            words = tempWords;
            numWords--;
        }
    }
    LexicographicalBubbleSort(words, numWords);
}

/**
 * @brief Prints all words of dictionary
 * @param words 
 * @param numWords 
*/
void printAll(char** words, int numWords)
{
    for (int i = 0; i < numWords; i++)
    {
        // prints the word
        for (int j = 0; j < strlen(*(words + i)); j++)
        {
            cout << *(*(words + i) + j);

        }
        cout <<" ";
    }
    cout << endl;
}

//to check if a word exists or not
char* searchStr(char** words, int numWords, char* searchWord)
{
    for (int i = 0; i < numWords; i++)
    {
        if (strcmp(*(words + i), searchWord) == 0)//if letter the word starts with is selected letter than print it
        {

            return *(words + i);
        }
    }
    return NULL;
}

void printChar(char** words, int numWords, char letter)
{
    for (int i = 0; i < numWords; i++)
    {
        if (*(*(words + i) + 0) == letter)//if letter the word starts with is selected letter than print it
        {
            for (int j = 0; j < strlen(*(words + i)); j++)
            {
                cout << *(*(words + i) + j);
            }
            cout << endl;
        }
    }
}
//Sorts according to lexicographical order using bubble sort
void LexicographicalBubbleSort(char**& words, int numWords)
{
    int length;
    int maxLength = 0;//maximum length of a word in a dictionary
    for (int i = 0; i < numWords; ++i)
    {
        length = strlen(words[i]);
        if (length > maxLength)
        {
            maxLength = length;
        }
    }

    bool flag = true;
    int end = numWords;

    char** temp;
    temp = new char* [numWords];

    for (int i = 0; i < numWords; ++i)
    {
        *(temp + i) = new char[strlen(words[i]) + 1];
    }

    for (int comparisonLetterIndex = maxLength; comparisonLetterIndex >= 0; comparisonLetterIndex--)
    {
        cout << "HELLO!" << endl;
        for (end = numWords - 1; end > 0; --end)
        {
            flag = false;
            for (int i = 0; i < end; ++i)
            {
                //first check that index checking is a letter in each of the compared dictionaries...
                if ((strlen(words[i + 1]) - 1 >= comparisonLetterIndex) && (strlen(words[i]) - 1 >= comparisonLetterIndex) && (words[i + 1][comparisonLetterIndex - 1] < words[i][comparisonLetterIndex - 1]))
                {
                    cout << comparisonLetterIndex - 1 << endl;
                    flag = true;
                    for (size_t j = 0; j < strlen(words[i]) + 1; ++j)
                    {
                        temp[i][j] = words[i][j];
                    }
                    for (size_t j = 0; j < strlen(words[i + 1]) + 1; ++j)
                    {
                        words[i][j] = words[i + 1][j];
                    }
                    for (size_t j = 0; j < strlen(temp[i]) + 1; ++j)
                    {
                        words[i + 1][j] = temp[i][j];
                    }
                }
            }
        }
        comparisonLetterIndex--;
    }
}