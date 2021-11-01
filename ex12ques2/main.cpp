#include<iostream>
using namespace std;
#include <fstream>
/**
 * @brief Replaces alphabetic letters as AZaz i.e A will be Z B will by Y
 * Replaces digit to be one digit bigger, and '9' to become '0'
 * @param text 
 * @return text after encryption
*/
char Crypto(char text);
/**
 * @brief Encrypts the contents of inputFile and prints them into outputFile
 * @param inputFileName 
 * @param outputFileName 
*/
void CryptoFiles(char inputFileName[25], char outputFileName[25]);
/**
 * @author yehuda Moshe Binyamin
 * @brief Driver code for program that encrypts the contents of a file to another file
 * @param  
 * @return 
*/
int main(void)
{
    char inputFileName[25] = "input.txt";
    char outputFileName[25] = "output.txt";
    CryptoFiles(inputFileName,outputFileName);
    return 0;
}
char Crypto(char text)
{
    
        if (isupper(text))
        {
            char difference = text - 'A';
            text = 'Z' - difference;
        }
        else if (islower(text))
        {
            char difference = text - 'a';
            text = 'z' - difference;
        }
        else if (isdigit(text))
        {
            text = text + 1;
            if (text == '9')
            {
                text = '0';
            }
        }
    return text;
}

void CryptoFiles(char inputFileName[25], char outputFileName[25])
{
    char currentInput;
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName); 
    inputFile >> currentInput;
    while (!inputFile.eof())
    {
        outputFile << Crypto(currentInput);
        outputFile << endl;
        inputFile >> currentInput;
    }
}
/**
Sample execution taking input file and outputting it:(no output to the screen)
In input.txt:
1
A
z
!

In output.txt:
2
Z
a
!
**/