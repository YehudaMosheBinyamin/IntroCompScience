//328972427 program that prints time of landing HH:MM:SS credit to guptayashgupta53 (stackoverflow)for setfill and iomanip explanations
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{   int secondsInMinute = 60;
	int hours;
	int minutes;
	int seconds;
	int durationInHours;
	int durationInSeconds;
	int durationInMinutes;
	int minutesInHour =60;
	int hoursInDay = 24;
	cout << "enter flight takeoff" << endl;
	cin >> hours;
	cin >> minutes;
	cin >> seconds;
	cout << "enter flight duration" << endl;
	cin >> durationInHours;
	cin >> durationInMinutes;
	cin >> durationInSeconds;
	seconds = seconds + durationInSeconds;
	while (seconds >= 60)
	{
		seconds = seconds - secondsInMinute;
		minutes++;
	}
	minutes = minutes + durationInMinutes;
	while (minutes >= minutesInHour)
	{
		minutes = minutes - minutesInHour;
		hours++;
	}

	hours = hours + durationInHours;
	while (hours >= 24)
	{
		hours = hours - hoursInDay;
	}
	cout << "flight arrival is:" << setfill('0')<<setw(2)<<hours << ":" <<
		setfill('0') << setw(2) << minutes << ":" << setfill('0') << setw(2)<< seconds;

	return 0;
}
