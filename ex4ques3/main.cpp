#include <iostream>
using namespace std;
/**
 * @brief function that  returns the nth Fibonacci number for nonnegative integers
 * @param n
 * @return nth Fibonacci number
*/
int Fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return Fib(n - 1) + Fib(n - 2);
}
int main() 
{
    int nthFibNumber=0;
    cout<<"Insert a number n to have fibonacci until place n"<<endl;
    cin>>nthFibNumber;
    while (nthFibNumber < 0) 
    {
        cout << "ERROR" << endl;
        cin >> nthFibNumber;
    }
    for (int i = 0; i <= nthFibNumber; i++) 
    {
       int answerIthFibNumber = Fib(i);
       cout<<answerIthFibNumber<<" ";
    }

    
    return 0;
}
