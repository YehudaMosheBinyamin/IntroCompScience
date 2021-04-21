#include <iostream>
using namespace std;
#include <cstring>
//Yehuda Moshe Binyamin 328972427

//Calculates minimum skip between each letter of word in text(for example:abl is in table with gap 0,abc is in agapvbkxcoc with gaps of two),
//if word is not in text in any way,it will return -1
int minimalSkip(char text[80], char word[80]);


//determines whether a word is in text with a given minimal gap,and start index in text
bool FulfillsGap(char text[80], char word[80], int textLength, int wordLength, int index, int gap);

//receives a text and a word and prints minimal gaps.
int main(void) 
{
    char text[80];
    char word[80];
    cout << "enter text: ";
    cin.getline(text, 80);
    cout << "enter word: ";
    cin.getline(word, 80);
    cout << "size of jump: " << minimalSkip(text, word) << endl;
    return 0;
}

int minimalSkip(char text[80], char word[80])
{
    int textLength = strlen(text);
    int wordLength = strlen(word);

    if (strchr(text, word[0]) == NULL)
    {//If the first letter of word isn't in text,obviously word isn't in text in any way
        return -1;
    }

    if (strstr(text, word) != NULL)
    {//Word is a substring of text and so the jumps are zero
        return 0;
    }

    int i = 0;
    int gap = 1;
    while ((text[i] != word[0]) && (i < textLength))
    {
        i++;
    }
    do
    {
        do 
        {
            
            if (FulfillsGap(text, word, textLength, wordLength, i, gap) == true)
            {
                return gap;
            }
            i++;
            while ((text[i] != word[0]) && (i < textLength))
            {
                i++;
            }
        } while (i < textLength);
        i = 0;
        gap++;
    } while (gap < textLength-2);
    return -1;

}
bool FulfillsGap(char text[80], char word[80],int textLength,int wordLength, int index, int gap) 
{
    int j;
    for (index,j = 0; index < textLength && j < wordLength; index += gap + 1, j++)
    {
        if (text[index] != word[j])
        {
            return false;
        }
        if (text[index] == word[wordLength - 1])
        {
            return true;
        }
    }
    return false;
}
//enter text : yesterday
//enter word : xs
//size of jump : -1	enter text : yesterday
//enter word : sed
//size of jump : 1	enter text : table
//enter word : abl
//size of jump : 0

