#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

void clearBoof()
{
	cin.clear();
	while (cin.get() != '\n');
}

void initArr(char * str11, int n)
{
	cin.getline(str11, n);
}

void printArr(char * str)
{
	cout << str << endl;
}

void delword(char *str, char b[]){
	char *st1 = str, *st2;
	st1 = strstr(str, b);
	st2 = st1 + strlen(b);
	strcpy(st1, st2);
}

void Length(char *str)
{
	int len;
	char *b = " !@#$%^&*()[]{},./|?<>";
	char w1[30];
	char *a1 = str;
	int i = 0;
	int wordL[500];
	while (*a1)
	{
		a1 = a1 + strspn(a1, b);
		len = strcspn(a1, b);
		for (int x = 0; x<len; x++)
			w1[x] = *(a1 + x);
		w1[len] = '\0';
		a1 = a1 + len;
		wordL[i] = strlen(w1); i++;
	}
	a1 = str;
	cout << "Строка: " << a1 << endl;
	int k = 0;
	while (*a1)
	{
		a1 = a1 + strspn(a1, b);
		cout << "str=" << a1 << endl;
		len = strcspn(a1, b);
		cout << "len=" << len << endl;
		for (int x = 0; x<len; x++)
			w1[x] = *(a1 + x);
		w1[len] = '\0';

		cout << "Cлово: " << w1 << endl;
		for (int j = 0; j < i; j++)
		{
			if (wordL[j] == strlen(w1))
				k++;
		}
		if (k == 1)
		{
			delword(str, w1);
			a1 = a1 - len - 2;
		}
		a1 = a1 + len;
		k = len = 0;

	}
	cout << "Результат: " << str << endl;
}