#include <iostream>
using namespace std;
#include <cstring>
//328972427 Yehuda Moshe Binyamin
/**
 * @brief function that receives a string with a maximal length of 80 including null bytes, the function returns the string encrypted according to AZBY
 * @param text 
 * @return char[]
*/
char* Crypto(char text[80]);
//driver function
int main(void) 
{
    char text[80];
    cout << "enter string: ";
    cin >> text;
    cout << "after crypto:\n" << Crypto(text) << endl;
    return 0;
}
char* Crypto(char text[80])
{
    for (size_t i = 0; i < strlen(text); ++i) 
    {
        if (isupper(text[i])) 
        {
            char difference = text[i] - 'A';
            text[i] = 'Z' - difference;
        }
        else if (islower(text[i])) 
        {
            char difference = text[i] - 'a';
            text[i] = 'z' - difference;
        }
    }
    return text;
}
//enter a string : baA?ba
//after crypto :
//yzZ?yz	
//enter a string : bamba
//after crypto :
//yznyz
