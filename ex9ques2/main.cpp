#include <iostream>
using namespace std;
#include<cstring>
//328972427 Yehuda Moshe Binyamin
//function to reverse a string up to 80 chars length(including null byte)
char* reverse(char sentence[80]);

//Function that receives a string up to 80 chars long from user and prints each word in reverse
int main(void) 
{
    char sentence[80];
    cout << "enter a string:" << endl;
    cin.getline(sentence, 80);
    cout << "after reverse:" << reverse(sentence) << endl;
    return 0;
}


char* reverse(char sentence[80])
{
    char space[] = " ";
    size_t i = 0;
    int nextSpace=i;
    size_t sentenceLength = strlen(sentence);
    while ((i < sentenceLength)&&(nextSpace<sentenceLength)) 
    {
        while ((sentence[nextSpace] != space[0])&&(nextSpace<sentenceLength)) 
        {
            nextSpace++;
        }
        cout << nextSpace << endl;
        int beginningOfWord = i;
        int lengthOfWord = nextSpace - beginningOfWord-1;
        int middleOfWord = floor((lengthOfWord) / 2)+beginningOfWord;
        int distanceFromSpace = 0;
        while (i<=middleOfWord)
        {
                char temp = sentence[i];
                sentence[i] = sentence[nextSpace - distanceFromSpace-1];
                sentence[nextSpace - distanceFromSpace-1] = temp;
                i++;
                distanceFromSpace++;
        }
        i = nextSpace + 1;
        nextSpace++;
    }
    return sentence;
}
//enter a string :
//This is a silly88 sentence
//after reverse : sihT si a 88yllis ecnetnes
