// יהודה משה בנימין ת.ז 328972427 תכנית שקולטת 2 מספרים ופעולה חשבונית ופועלת עם פעולה
//זו על 2 המספרים ומציגה תוצאת הפעולה עם דרך הפעולה
#include <iostream>
using namespace std;
int main()
{
    float n1;
    float n2;
    float answer;
    char operatorChosen;
    char plus = '+';
    char minus = '-';
    char multiplication = '*';
    char division = '/';
    cout << "enter 2 numbers" << endl;
    cin >> n1 >> n2;
    cout << "enter an operator" << endl;
    cin >> operatorChosen;
    switch (operatorChosen)
    {
    case '/':
        answer = n1 / n2;
        cout << n1 << "/" << n2 << " = " << answer << endl;
        break;
    case '+':
        answer = n1 + n2;
        cout << n1 << "+" << n2 << " = " << answer << endl;
        break;
    case '*':
        answer = n1 * n2;
        cout << n1 << "*" << n2 << " = " << answer << endl;
        break;
    case '-':
        answer = n1 - n2;
        cout << n1 << "-" << n2 << " = " << answer << endl;
        break;
    default:
        cout << "ERROR" << endl;
        break;
    }
    return 0;
}