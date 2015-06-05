#include<iostream>
#include<new>
#include<conio.h>
#include"func.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	const char * task = "44. Определить, сколько слов в строке имеют одинаковую длину. Вывести такие слова на экран.";
	int n = 1000;
	int choice;
	do{
		system("cls");
		cout << "1. Показать условие\n";
		cout << "2. Запустить\n";
		cout << "0. Выйти\n";
		choice = _getch() - 48;
		switch (choice)
		{
		case 0: break;
		case 1:
			system("cls");
			cout << task << endl << "Press Backspace to back in menu.";
			while (_getch() != 8) cout << "\a";
			break;
		case 2:
		{
			system("cls");
			char * str = new char[n];
			initArr(str, n);
			Length(str);
			delete[] str;
			cout << "Press Backspace to back in menu.";
			while (_getch() != 8) cout << "\a"; }
			break;
		default:
			system("cls");
			cout << "Error:\a \'" << (char)(choice + 48) << "\' undefined. ";
			cout << endl << "Press Backspace to back in menu.";
			while (_getch() != 8) cout << "\a";
			break;
		}
	} while (choice);
	//system("pause");
	return 0;
}