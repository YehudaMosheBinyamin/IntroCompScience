//  תכנית הקולטת מהמשתשמש 3 מספרים  ומודיעה לו האם המספר שהכנסנו למשתנה נאמבר שהוא בחר נמצא
//בין המספר שהכנסנו למשתנה פירסט למשתנה לאסט או  קטן מפירסט או גדול מלאסט 
//מגיש יהודה בנימין ת.ז 328972427
#include<iostream>
using namespace std;
int main()
{
	float first;
	float last;
	float number;
	{
		cout << "enter 3 numbers" << endl;
		cin >> first;
		cin >> last;
		cin >> number;
		if (number <= last && number >= first)
			cout << "between" << endl;
		else if (number > last)
			cout << "bigger" << endl;
		else if (number < first)
			cout << "smaller" << endl;
		return 0; }
}