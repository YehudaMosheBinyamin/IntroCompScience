#include <iostream>
using namespace std;
//328972427 
float area(float a, float b);
float area(float a);
//Program gets two sides of rectangle and prints the area of rectangle,and a radius,and prints the area of the circle the radius belongs to
int main()
{
	float side1, side2, radius;
	cout << "Enter length and width of the rectangle:" << endl;
	cin >> side1 >> side2;
	while ((side1 <= 0) || (side2 <= 0))
	{
		cout << "ERROR" << endl;
		cin >> side1 >> side2;
	}
	area(side1, side2);
	cout << area(side1, side2) << endl;
	cout << "enter radius of the circle:" << endl;
	cin >> radius;
	while (radius <= 0)
	{
		cout << "ERROR" << endl;
		cin >> radius;
	}
	area(radius);
	cout << area(radius) << endl;
	return 0;
}
//for area of rectangle
float area(float a, float b)
{
	float area;
	area = (a * b);
	return area;
}
//for area of circle
float area(float a)
{
	const double PI = 3.14159;
	float areaOfCircle;
	areaOfCircle = (PI * a*a);
	return areaOfCircle;
}

//enter length and width of the rectangle :
//1
//-3 
//ERROR
//2
//2
//4
//enter radius of the circle :
//4 -
//ERROR
//3
//28.2743

//enter length and width of the rectangle :
//2 4
//8
//enter radius of the circle :
//1
//3.14159

