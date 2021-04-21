//מגיש יהודה משה בנימן ת.ז 328972427 תכנית הקולטת 3 מספרים מהמשתמש ואומרת לו איזה סוג של משולש אפשר ליצור מזה 
//תודה ל WIKI HOW על האופן שבו יתן להחליט אם המשולש תקין
#include <iostream>
using namespace std;
int main()
{
    int flag = true;
    float n1;
    float n2;
    float n3;
    cout << "enter 3 numbers:"<<endl;
    cin >> n1;
    cin >> n2;
    cin >> n3;
    if ((n2 + n3 < n1) || (n1 + n2 < n3) || (n1 + n3 < n2))
    {
        flag = false;
        cout << "cannot form a triangle" << endl;
    }
    if (flag == true)
    {
        if (n1 == n2)
        {
            if (n1 == n3)
                cout << "equilateral triangle" << endl;
            else
                cout << "isosceles triangle" << endl;
        }
        else
        {
            if (n1 == n3)
                cout << "isosceles triangle" << endl;
            else

                cout << "scalene triangle" << endl;
        }
    }
    return 0;
}
