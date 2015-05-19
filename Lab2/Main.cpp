#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>
#include<new>
#include"func.h"
using namespace std;

int main()
{
	ifstream in("in.txt");
	ofstream out("out.txt");
	setlocale(LC_ALL, "Rus");
	const char * task = "69. В массиве А(N,M) переставить столбцы так, чтобы столбец с максимальной суммой элементов стал первым, а остальные столбцы расположить в порядке возрастания элементов первой строки. Указатели на столбцы.";
	int n, m;
	int choice;
	do{
		system("cls");
		cout << "Press 1 to show task\n";
		cout << "Press 2 to run task\n";
		cout << "Press 0 to exit\n";
		choice = _getch() - 48;
		switch (choice)
		{
		case 0: break;
		case 1:
			system("cls");
			cout << task << endl << "\nPress Backspace to back in menu.";
			while (_getch() != 8) cout << "\a";
			break;
		case 2:
		{
			system("cls");
			cout << "Считываем n. \n";
			in >> n;
			cout << "Считываем m. \n";
			in >> m;
			if (n < 0 || m < 0){
				out << "Ошибка: некорректные данные.\n";
				continue;
			}
			float ** arr = new float *[m];
			for (float ** i = arr; i < arr + m; i++)
			{
				*i = new float[n];
			}
			initArr(arr, n, m, in);
			sortColumn(arr, n, m);
			printArr(arr, n, m, out);
			for (float ** i = arr; i < arr + m; i++)
				delete[] * i;
			delete[] arr;
			cout << "Press Backspace to back in menu.";
			in.close();
			out.close();
			while (_getch() != 8) cout << "\a"; }
			break;
		default:
			system("cls");
			cout << "Error!!!\a";
			cout << endl << "Press Backspace to back in menu.";
			while (_getch() != 8) cout << "\a";
			break;
		}
	} while (choice);
	return 0;
}