#include <iostream>
#include <time.h>
#include "func.h"

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));

	Polynom polynom;
	Polynom result;

	InitPolynom(&polynom);
	InitPolynom(&result);

	bool isRunning = true;
	while (isRunning)
	{
		int input = 0;

		cout << "====================================================" << endl;
		cout << "==        Polynomials + operations                ==" << endl;
		cout << "==       Enter 1 to enter polynomial              ==" << endl;
		cout << "==       Enter 2 to show polynomial               ==" << endl;
		cout << "==       Enter 3 to curried polynomial            ==" << endl;
		cout << "==       Enter 4 to first-born polynomial         ==" << endl;
		cout << "==       Enter 5 to exit                          ==" << endl;
		cout << "====================================================" << endl;
		cin >> input;
		cin.ignore();
		system("cls");
		switch (input)
		{
		case 1:
			int input2;
			cout << "=================================================" << endl;
			cout << "==         Enter of polynomial                 ==" << endl;
			cout << "==       Enter 1 to manually enter             ==" << endl;
			cout << "==       Enter 2 to randomize enter            ==" << endl;
			cout << "==       Enter 3 to exit                       ==" << endl;
			cout << "=================================================" << endl;
			cin >> input2;
			if (input2 == 1)
			{
				EnterPolynom(&polynom);
				system("cls");
			}
			else if (input2 == 2)
			{
				PopulatePolynom(&polynom);
				system("cls");
				PrintPolynom(&polynom);
			}
			else if (input2 == 3)
			{
				cout << "Returning to menu!" << endl; 
				system("cls");
				break;
			}
			else
			{
				cout << "Didn't input anything!" << endl;
				system("cls");
			}
			break;
		case 2:
			PrintPolynom(&polynom);
			break;
		case 3:
			PrintPolynom(&polynom);

			CurriedPolynom(&polynom, &result);

			PrintPolynom(&result);
			break;
		case 4:
			PrintPolynom(&polynom);

			IntegralPolynom(&polynom, &result);

			PrintPolynom(&result);
			break;
		case 5:
			cout << "Good-Bye!" << endl;
			isRunning = false;
			break;
		default:
			cout << "Error, bad input!" << endl;
			break;
		}
	}
	FreePolynom(&polynom);
	FreePolynom(&result);

	return 0;
}