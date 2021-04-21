//q3_ex1 תכנית שקולטת מספר מהמשתמש  אם הספרות זוגיות זה מדפיס מידע זה ואת סכום הספרות אם ספרות אי זוגיות ידפיס את זה ואת מכפלת הספרות אם אחד שלילי ואחד חיובי ידפיס מידע שזה מספר מעורב אם המספר לא מ0 עד 100 זה ידפיס שגיאה  יהודה משה 
#include<iostream>
using namespace std;
int main()
{
    int num;
    int digit;
    int digitOne;
    int digitTwo = 0;
    int count = 0;
    int even = 0;
    int odd = 0;
    int flag = true;
    cout << "enter a number:" << endl;
    cin >> num;
    if (num < 0 || num >= 100)
    {
        cout << "ERROR" << endl;
        flag = false;
    }
    if (flag == true)
    {
        count++;
        digit = num % 10;
        num = num / 10;

        digitOne = digit;
        if (digit % 2 == 0)
            even++;
        else
            odd++;
        {if (num > 0)
        {
            count++;
            digit = num;
            digitTwo = digit;
            if (digit % 2 == 0)
                even++;
            if (digit % 2 != 0)
                odd++;
        }
        {if (count > 0)
            if ((count == (even + odd)) && (odd > 0) && (even > 0))

                cout << "mixed number" << endl;

            else if (even == count)

            {
                cout << "even digits only" << endl;
                cout << digitOne * digitTwo << endl;
            }

            else if (odd == count)
            {
                cout << "odd digits only" << endl;
                cout << digitOne + digitTwo << endl;
            }

        }
        return 0;
        }
    }
}
