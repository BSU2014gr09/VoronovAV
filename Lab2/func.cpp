#include<iostream>
#include<iomanip>
#include"func.h"
using namespace std;

void initArr(float **a, int n, int m, ifstream &in)
{
	for (int j = 0; j < n; j++)
	{
		for (float **i = a; i < a + m; i++)
			in >> *(*i + j);
	}
}

void printArr(float ** a, int n, int m, ofstream &out)
{
	for (int j = 0; j < n; j++)
	{
		for (float **i = a; i < a + m; i++)
			out << setw(4) << *(*i + j) << " ";
		out << endl;
	}
}

void findMax(float * a, float &maxsum)
{
	float maxsumtmp = 0;
	for (int i = 0; i <= *a; i++)
	{
		maxsumtmp += a[i];
	}
	if (maxsum < maxsumtmp)
		maxsum = maxsumtmp;
}

void sortColumn(float * * a, int n, int m)
{
	int tmpmaxI = 0;
	float maxsum = **a;
	int iI;
	for (iI = 0; iI < m; iI++)
	{
		float tmpsum = maxsum;
		findMax(a[iI], maxsum);
		if (maxsum != tmpsum)
			tmpmaxI = iI;
	}
	swap(a[tmpmaxI], a[0]);
	for (int i = 1; i < m; i++)
		for (int j = i; j < m; j++)
			if (*a[i]>*a[j])
				swap(a[i], a[j]);
}