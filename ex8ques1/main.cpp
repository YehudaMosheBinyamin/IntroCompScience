#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
typedef struct Item 
{
	int code;
	char name[20];
	int numInStock;
	int minAllowed;
	float price;
}Item;
void addItem(Item* store, int maxItems, int *numItems);
void findPrice(Item *store, int numItems);
void sold(Item *store,int numItems);
void order(Item *store,int *numItems);
void print(Item * store,int numItems);
int main() 
{
	Item* store;
	int maxItems;
	int numItems = 0;
	int choice;
	cout << "enter max number of items: " << endl;
	cin >> maxItems;
	store = new Item[maxItems];

	do {
		cout << "enter 0-5:\n";
		cin >> choice;
		switch (choice) {
		case 0:	
			break;

		case 1:	
			addItem(store, maxItems, &numItems);
			break;

		case 2: 	
			findPrice(store, numItems);
			break;

		case 3:	
			sold(store, numItems);
			break;

		case 4:	
			order(store, &numItems);
			break;

		case 5: 	
			print(store, numItems);
			break;

		default: 	
			cout << "ERROR" << endl;
		}
	} while (choice != 0);

	return 0;
}

void addItem(Item* store, int maxItems, int *numItems)
{
	Item newItem;
	cout << "enter code:" << endl;
	cin >> newItem.code;
	cout << "enter name:" << endl;
	cin >> newItem.name;
	cout << "enter amount:" << endl;
	cin >> newItem.numInStock;
	cout << "enter minimum amount:" << endl;
	cin >> newItem.minAllowed;
	cout << "enter price:" << endl;
	cin >> newItem.price;
	int i = 0;
	for (i; i < *numItems; i++) 
	{
		if((store[i].code==newItem.code)&&(strcmp(store[i].name,newItem.name)==0))
		{
			store[i].numInStock+=newItem.numInStock;
			store[i].minAllowed = newItem.minAllowed;
			store[i].price = newItem.price;
			return;
		}
		else if (store[i].code == newItem.code) 
		{
			cout << "ERROR" << endl;
			return;
		}
	}
	if (*numItems == maxItems) 
	{
		cout << "ERROR" << endl;
		return;
    }
	*numItems = *numItems + 1;
	store[i] = newItem;
}

void findPrice(Item* store, int numItems)
{
	int wantedItemCode;
	cout << "enter code" << endl;
	cin >> wantedItemCode;
	for (int i = 0; i < numItems; i++) 
	{
		if (store[i].code == wantedItemCode) 
		{
			cout << "price:" << store[i].price << endl;
			return;
	    }
	}
	cout << "ERROR" << endl;
}

void sold(Item* store, int numItems)
{
	int wantedItemCode;
	int wantedItemAmount;
	cout << "enter code" << endl;
	cin >> wantedItemCode;
	cout << "enter amount" << endl;
	cin >> wantedItemAmount;
	for (int i = 0; i < numItems; i++)
	{
		if (store[i].code == wantedItemCode)
		{
			if (store[i].numInStock < wantedItemAmount) 
			{
				cout << "ERROR" << endl;
				return;
			}
			else 
			{
				store[i].numInStock -= wantedItemAmount;
				return;
			}
		}
	}
	cout << "ERROR" << endl;
}

void order(Item* store, int *numItems)
{
	int* indexesToOrder = new int[*numItems];
	int* amountsToOrder = new int[*numItems];
	for (int i = 0; i < *numItems; i++) 
	{
		if (store[i].numInStock < store[i].minAllowed) 
		{
			cout << "item name" << store[i].name << endl;
			cout << "code" << store[i].code << endl;
			amountsToOrder[i] = store[i].minAllowed + 5 - store[i].numInStock;
			cout << "amount to order" <<amountsToOrder[i]<< endl;
			indexesToOrder[i] = 1;
		}
		else 
		{
			indexesToOrder[i] = 0;
		}
	}
	for (int j = 0; j < *numItems; j++) 
	{
		if (indexesToOrder[j] == 1) 
		{
			store[j].numInStock += amountsToOrder[j];
		}
	}
	delete[] indexesToOrder;
	delete[] amountsToOrder;
}

void print(Item* store, int numItems)
{
	for (int i = 0; i < numItems; i++) 
	{
		cout << "name: " << store[i].name << endl;
		cout << "code: " << store[i].code << endl;
		cout << "amount: " << store[i].numInStock << endl;
		cout << "minimum amount: " << store[i].minAllowed << endl;
		cout << "price: " <<fixed<<setprecision(2)<<store[i].price << endl;
		cout << endl;
	}
}
