#include <iostream>
using namespace std;
//For user input
enum choices { EXIT, ADD, DELETE, PRINT, SEARCH, AVG_TRAVEL, AVG_STOPS, SHORTEST_TRAVEL };
//Sorts an array of pointers of numBuses size by the number of the bus in ascending order
void SortArray(int**&arr,int numBuses);
//To add a line to the bus array. Sorts the array after the new bus is added
void addLine(int**& buses, int& numBuses, int line, int stops, int durationOfRide);
//Deletes a bus from the bus array
void deleteLine(int**& buses, int& numBuses, int line);
//Finds and prints all fields(Bus number, number of stops,commute length) for a bus number requested by the user
int search(int** buses, int numBuses, int line);
//Calculates average travel time of the bus lines
float averageTravel(int** buses, int numBuses);
//Calculates average number of bus stops of all lines 
int averageStops(int** buses, int numBuses);
//Finds and prints the line whose trip duration is the shortest
int shortest(int** buses, int numBuses);
//Prints bus number, number of stops,commute length for all lines 
void print(int** buses, int numBuses);
//328972427 Program that manages a bus company calculates average length of commute,number of stops on route and rints the shortest route
int  main() 
{
	int** buses=NULL;
	int numBuses = 0;
	int line;
	int stops;
	int durationOfRide;
	int choice;
	do {
		cout << "enter 0-7" << endl;
		cin >> choice;
		switch (choice) 
		{
		case ADD: // add a line to the array of buses
			cout << "enter the line to add" << endl;
			cin >> line;
			cout << "enter the number of stops" << endl;
			cin >> stops;
			cout << "enter the duration of the ride" << endl;
			cin >> durationOfRide;
			addLine(buses, numBuses, line, stops, durationOfRide);	
			print(buses, numBuses);
			break;

		case DELETE:	// delete a line from the array of buses 
			cout << "enter the line to delete" << endl;
			cin >> line;
			deleteLine(buses, numBuses, line);
			print(buses, numBuses);
			break;
		case PRINT: // print all lines
				print(buses, numBuses);
			break;
		case SEARCH: // search for a particular line
			cout << "enter the line to search for" << endl;
			cin >> line;
			cout << search(buses, numBuses, line) << endl;
			break;
		case AVG_TRAVEL: // calculate average travel time of all buses
			cout << averageTravel(buses, numBuses) << endl;
			break;
		case AVG_STOPS:  // calcuate average stops of all buses
			cout << averageStops(buses, numBuses) << endl;
			break;
		case SHORTEST_TRAVEL:// calculate the bus with the shortest travel time
			cout << shortest(buses, numBuses) << endl;
			break;
		case EXIT: break;   // exit the program

		default:  
			cout << "ERROR" << endl;	
		}
	} while (choice != 0);

	for (int i = 0; i < numBuses; i++)
	{
		delete[] buses[i];
	}
	if (numBuses > 0)
	{
		delete[] buses;
	}
	return 0;
}

void addLine(int**& buses, int& numBuses, int line, int stops, int durationOfRide)
{
	if (numBuses == 0) 
	{
		numBuses++;
		buses = new int* [numBuses];
		for (int i = 0; i < numBuses; ++i)
		{
			buses[i] = new int[3];
		}

		*(*(buses) + 0) = line;
		*(*(buses)+1) = stops;
		*(*(buses)+2) = durationOfRide;
	}
	else 
	{
		numBuses++;
		int** tempBuses = new int* [numBuses];
		for (int i = 0; i < numBuses; ++i)
		{
			tempBuses[i] = new int[3];
		}
		for (int i = 0; i < numBuses - 1; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				*(*(tempBuses + i) + j) = *(*(buses + i) + j);
			}
		}
		*(*(tempBuses + (numBuses - 1)) + 0) = line;
		*(*(tempBuses + (numBuses - 1)) + 1) = stops;
		*(*(tempBuses + (numBuses - 1)) + 2) = durationOfRide;
		for (int i = 0; i < numBuses - 1; ++i) 
		{
			delete[] buses[i];
		}
		delete [] buses;
		buses=tempBuses;
	}
	SortArray(buses, numBuses);
}

void deleteLine(int**& buses, int& numBuses, int line)
{
	int indexNotToCopy=-1;
	for (int i = 0; i < numBuses; ++i)
	{
		if (*(*(buses + i) + 0) == line)
		{
			indexNotToCopy = i;
		}
	}
	if (indexNotToCopy == -1) 
	{
		return;
	}
	int** newBuses = new int* [numBuses-1];
	for (int j = 0; j < numBuses - 1; j++) 
	{
		newBuses[j] = new int[3];
	}
	for (int i = 0; i < indexNotToCopy; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			*(*(newBuses + i) + j) = *(*(buses + i) + j);
		}
	}
	for (int i = indexNotToCopy; i <numBuses-1; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			*(*(newBuses + i) + j) = *(*(buses + i+1) + j);
		}
	}

	for (int i = 0; i < numBuses; ++i) 
	{
		delete[] buses[i];
	}
	delete[] buses;
	numBuses--;
	buses = newBuses;
}

int search(int** buses, int numBuses, int line)
{
	for (int i = 0; i < numBuses; ++i) 
	{
		if (*(*(buses + i)) == line)
		{
			return i;
		}
		
	}
	return -1;
}

float averageTravel(int** buses, int numBuses)
{   float sumTravel = 0.0f;
	for (int i = 0; i < numBuses; ++i)
	{
		sumTravel += float(*(*(buses + i) + 2));
	}

	return sumTravel/numBuses;
}

int averageStops(int** buses, int numBuses)
{
	float sumStops = 0.0f;
	for (int i = 0; i < numBuses; ++i)
	{
		sumStops += float(*(*(buses + i) + 1));
	}

	return int(sumStops / numBuses);
}

int shortest(int** buses, int numBuses)
{
	int shortestBus=0;
	if (numBuses == 0) 
	{
		return -1;
	}
	if (numBuses == 1) 
	{
		return *(*(buses + 0) + 0);
	}
	
	int shortestTime =(*(*(buses + 0) + 2));
	shortestBus= (*(*(buses + 0) + 0));
	for (int i = 1; i < numBuses; ++i)
	{
		if (*(*(buses + i) + 2) < shortestTime)
		{
			shortestBus = *(*(buses + i) + 0);
			shortestTime= *(*(buses + i) + 2);
		}
	}
	return shortestBus;
}
//Sorts using insertion sort
void SortArray(int**&arr,int numBuses)
{
	int j;
	for (int i = 1; i < numBuses; ++i)
	{
		j = i - 1;
		int temp[3] = {};
		for (int m = 0; m < 3; ++m) 
		{
			*(temp+m) = *(*(arr + i) + m);
		}
		while (j >= 0&&*(*(arr + i) + 0)< *(*(arr + j) + 0))
		{
			for (int k = 0; k < 3; ++k)
			{
				*(*(arr + j + 1) + k) = *(*(arr + j) + k);
			}
			j--;
		}
		for (int m = 0; m < 3; ++m)
		{
			*(*(arr+j + 1)+m) = *(temp+m);
		}
	}
}
// prints out the buses that are saved in the database
void print(int** buses, int numBuses)
{
	// for each bus that is present in the database
	for (int i = 0; i < numBuses; i++)
	{
		// prints the 3 pieces of data of the bus
		for (int j = 0; j < 3; j++)
		{
			cout << *(*(buses + i) + j) << " ";

		}
		cout << endl;
	}
}
//enter 0 - 7
//1
//enter the line to add
//50
//enter the number of stops
//22
//enter the duration of the ride
//333
//50 22 333
//enter 0 - 7
//1
//enter the line to add
//34
//enter the number of stops
//55
//enter the duration of the ride
//66
//34 55 66
//50 22 333
//enter 0 - 7
//1
//enter the line to add
//88
//enter the number of stops
//55
//enter the duration of the ride
//98
//34 55 66
//50 22 333
//88 55 98
//enter 0 - 7
//3
//34 55 66
//50 22 333
//88 55 98
//enter 0 - 7
//4
//enter the line to search for
//50
//1
//enter 0 - 7
//4
//enter the line to search for
//9909
//- 1
//enter 0 - 7
//5
//165.667
//enter 0 - 7
//6
//44
//enter 0 - 7
//7
//34
//enter 0 - 7
//2
//enter the line to delete
//34
//50 22 333
//88 55 98
//enter 0 - 7
//50
//ERROR
//enter 0 - 7
//2
//enter the line to delete
//50
//88 55 98
//enter 0 - 7
//2
//enter the line to delete
//88
//enter 0 - 7
//3
//enter 0 - 7
//0
