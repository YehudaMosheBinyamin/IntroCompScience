//328972427 receives number of month and prints number of days in that month
#include <iostream>
using namespace std;
enum Month {
	JAN = 1,
	FEB = 2,
	MARCH = 3,
	APRIL = 4,
	MAY = 5,
	JUNE = 6,
	JULY = 7,
	AUG = 8,
	SEPT = 9,
	OCT = 10,
	NOV = 11,
	DEC = 12,
};
int main()
{
	int number;
	int months;
	int  fullMonth = 31;
	int  month = 30;
	int  missingMonth = 28;
	int missingMonthLeap = 29;
	cout << "enter a number:" << endl;
	cin >> number;
	switch(number)
	{
	case JAN:
		cout << fullMonth << " " << "days in the month";
		break;
	case FEB:
		cout << missingMonth << " " << "days in the month on regular years"<<" "<<missingMonthLeap<<" on leap years"<<endl;
		break;
	case MARCH:
		cout << fullMonth << " " << "days in the month";
		break;
	case APRIL:
		cout << month << " " << "days in the month";
		break;
	case MAY:
		cout << fullMonth << " " << "days in the month";
		break;
	case JUNE:
		cout << month << " " << "days in the month";
		break;
	case JULY:
		cout << fullMonth << " " << "days in the month";
		break;
	case AUG:
		cout << month << " " << "days in the month";
		break;
	case SEPT:
		cout << fullMonth<< " " << "days in the month";
		break;
	case OCT:
		cout << month << " " << "days in the month";
		break;
	case NOV:
		cout << fullMonth << " " << "days in the month";
		break;
	case DEC:
		cout << month << " " << "days in the month";
		break;
	}
	return 0;
}