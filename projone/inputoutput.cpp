//Yehuda Binyamin 328972427
#include <iostream>
using namespace std;
int main()
{
    int a;
    int b;
    cout << "Enter two numbers:" << endl;
    cin >> a;
    cin >> b;
    float c;
    c = float(5 * a + 3) / float(6 * b + 2);
    cout << "c=" << c;
    return 0;
}
