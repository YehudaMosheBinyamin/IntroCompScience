//using dynamic array of pointers
//pointer->aray of size given by user->each a pointer to a arbitrarily lengthed array.

#include <iostream>
using namespace std;
#include <cstring>

/**
 * @brief A function to add a word to its correct lexicographical location in words. If the word already exists in words,
 * it won't be added again.
 * @param words An array of pointers to strings of varying length
 * @param numWords Number of words in words
 * @param newWord A string to add to words
*/

void newStr(char**& words, int& numWords, char* newWord);


/**
 * @brief Deletes a word from dictionary
 * @param words An array of pointers to strings of varying length
 * @param numWords Number of words in words
 * @param deletedWord Word to delete from words
*/

void deleteStr(char**& words, int& numWords, char* newWord);


/**
 * @brief Checks if a word exists in words
 * @param words An array of pointers to strings of varying length
 * @param numWords Number of words in words
 * @param searchWord Word to search if exists in words
 * @return Pointer to the word, if it is in the array, else NULL
*/

char* searchStr(char** words, int numWords, char* newWord);


/**
 * @brief Prints all words in dynamic array which start with letter-letter.
 * @param words An array of pointers to words of varying length
 * @param numWords Number of words in words
 * @param letter Letter of the alphabet
*/

void printChar(char** words, int numWords, char letter);


/**
 * @brief Prints all words of dictionary
 * @param words An array of pointers to strings of varying length
 * @param numWords Number of words in words
*/

void printAll(char** words, int numWords);


/**
 * @brief Yehuda Moshe Binyamin A driver function to allow addition, deletion, search, print by first character and print all
 * functions for a dictionary
 * @param
 * @return
*/

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
            cin.getline(newWord, 79);
            newStr(words, numWords, newWord);
            printAll(words, numWords);
            break;
        case 1:
            cout << "enter the word to delete:" << endl;
            cin.ignore();
            cin.getline(newWord, 80);
            deleteStr(words, numWords, newWord);
            printAll(words, numWords);
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
            printAll(words, numWords);
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
        numWords += 1;
        words = new char* [numWords];
        for (int i = 0; i < numWords; ++i)
        {
            words[i] = new char[strlen(newWord) + 1];
        }
        for (int i = 0; i < strlen(newWord) + 1; ++i)
        {
            words[0][i] = newWord[i];
        }
    }
    else
    {

        //Return if the word is already in the dictionary
        if (searchStr(words, numWords, newWord))
        {
            return;
        }
        char** newArrWords = new char* [numWords + 1];
        int indexFirstBigger = -1;
        for (int i = 0; i < numWords; ++i)
        {
            if (strcmp(words[i], newWord) > 0)
            {
                indexFirstBigger = i;
            }
        }
        if (indexFirstBigger == -1)
        {
            indexFirstBigger = numWords;
        }
        /*Copy elements to new array until indexFirstBigger*/
        for (int i = 0; i < indexFirstBigger && i < numWords; ++i)
        {
            newArrWords[i] = new char[strlen(words[i]) + 1];
            for (int j = 0; j < strlen(words[i]) + 1; ++j)
            {
                newArrWords[i][j] = words[i][j];
            }
        }

        newArrWords[indexFirstBigger] = new char[strlen(newWord) + 1];
        for (int j = 0; j < strlen(newWord) + 1; ++j)
        {
            newArrWords[indexFirstBigger][j] = newWord[j];
        }

        /*From indexFirstBigger copy elements from original array until the end*/
        for (int i = indexFirstBigger + 1; i < numWords + 1; ++i)
        {
            newArrWords[i] = new char[strlen(words[i - 1]) + 1];
            for (int j = 0; j < strlen(words[i - 1]) + 1; ++j)
            {
                newArrWords[i][j] = words[i - 1][j];
            }
        }
        for (int i = 0; i < numWords; ++i)
        {
            delete[] words[i];
        }
        delete[] words;
        words = newArrWords;
        numWords++;
    }
}


void deleteStr(char**& words, int& numWords, char* deletedWord)
{
    int numWordNotCopy = -1;
    /*Find index of pointer to word which points to the same word as deletedWord*/
    for (int i = 0; i < numWords; ++i)
    {
        if (strcmp(*(words + i), deletedWord) == 0)//if deleted word found
        {
            numWordNotCopy = i;
        }
    }

    /*If the word for deletion isn't in dictionary-return as it cannot get deleted*/
    if (numWordNotCopy == -1)
    {
        return;
    }
    char** newWords = new char* [numWords - 1];

    for (int i = 0; (i < numWordNotCopy) && (i < numWords - 1); ++i)
    {
        newWords[i] = new char[strlen(words[i]) + 1];
        for (int j = 0; j < strlen(words[i]) + 1; ++j)
        {
            newWords[i][j] = words[i][j];
        }
    }

    for (int i = numWordNotCopy + 1; i < numWords - 1; ++i)
    {
        newWords[i - 1] = new char[strlen(words[i]) + 1];
        for (int j = 0; j < strlen(words[i]) + 1; ++j)
        {
            newWords[i - 1][j] = words[i][j];
        }
    }
    //Copy last word if it's not the word we want to delete
    if ((numWords - 1) != numWordNotCopy)
    {
        newWords[numWords - 2] = new char[strlen(words[numWords - 1]) + 1];
        for (int j = 0; j < strlen(words[numWords - 1]) + 1; ++j)
        {
            newWords[numWords - 2][j] = words[numWords - 1][j];
        }
    }
    /*Delete old dictionary*/
    for (int i = 0; i < numWords; ++i)
    {
        delete[] words[i];
    }
    delete[] words;
    numWords--;
    words = newWords;
}


void printAll(char** words, int numWords)
{
    for (int i = 0; i < numWords; i++)
    {
        // prints the word
        for (int j = 0; j < strlen(*(words + i)); j++)
        {
            cout << *(*(words + i) + j);

        }
        cout << " ";
    }
    cout << endl;
}


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
            cout << " ";
        }
    }
    cout << endl;
}
/**Sample Execution:
enter 0 - 5
0
enter the word :
good
good
enter 0 - 5
0
enter the word :
hello
good hello
enter 0 - 5
0
enter the word :
shalom
good hello shalom
enter 0 - 5
0
enter the word :
today
good hello shalom today
enter 0 - 5
2
enter the word to search for :
what
not found
enter 0 - 5
2
enter the word to search for :
hello
found
enter 0 - 5
1
enter the word to delete :
hello
good shalom today
enter 0 - 5
1
enter the word to delete :
toda
good shalom today
enter 0 - 5
3
enter the char :
s
shalom
enter 0 - 5
0
enter the word :
toda
good shalom toda today
enter 0 - 5
3
enter the char :
t
toda today
enter 0 - 5
5
    **/
