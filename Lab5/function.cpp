#include <iostream>
#include <time.h>
#include "func.h"

using namespace std;

void IntegralPolynom(const Polynom *polynom, Polynom *result)
{
	result->numMembers = polynom->numMembers;
	InitMem(result, result->numMembers);

	for (int i = 0; i < polynom->numMembers; ++i)
	{
		result->members[i].exp = polynom->members[i].exp + 1;
		if (polynom->members[i].exp == 0)
			result->members[i].coef = polynom->members[i].coef;
		else
			result->members[i].coef = polynom->members[i].coef / result->members[i].exp;
	}
}

void CurriedPolynom(const Polynom *polynom, Polynom *result)
{
	result->numMembers = polynom->numMembers;
	InitMem(result, result->numMembers);

	for (int i = 0; i < polynom->numMembers; ++i)
	{
		result->members[i].coef = polynom->members[i].coef * polynom->members[i].exp;
		result->members[i].exp = polynom->members[i].exp - 1;
	}
}

void InitMem(Polynom *polynom, int num)
{
	polynom->members = new PolynomMember[num];
}

void InitPolynom(Polynom *polynom)
{
	polynom->members = NULL;
	polynom->numMembers = 0;
}

void EnterPolynom(Polynom *polynom)
{
	cout << "Enter num of polynoms ";
	cin >> polynom->numMembers;
	polynom->members = new PolynomMember[polynom->numMembers];
	for (int i = 0; i < polynom->numMembers; ++i)
	{
		float coef;
		cout << "Enter a coef " << i << " ";
		cin >> coef;
		polynom->members[i].coef = coef;
		polynom->members[i].exp = i;
	}
}

void PopulatePolynom(Polynom *polynom)
{
	FreePolynom(polynom);

	polynom->numMembers = rand() % 10;
	polynom->members = new PolynomMember[polynom->numMembers];

	for (int i = 0; i < polynom->numMembers; ++i)
	{
		float coef = rand() % 10 - 5;

		polynom->members[i].exp = i;
		polynom->members[i].coef = coef;
	}
}

void PrintPolynom(Polynom *polynom)
{
	for (int i = 0; i < polynom->numMembers; ++i)
	{
		const PolynomMember *member = &polynom->members[i];
		if (member->coef > 0)
			cout << " + ";
		else if (member->coef < 0)
			cout << " - ";
		else
			continue;

		if (member->exp == 0)
			cout << fabs(member->coef);
		else
			cout << fabs(member->coef) << "x^" << member->exp;
	}

	cout << endl << endl;
}

void FreePolynom(Polynom *polynom)
{
	delete[] polynom->members;
	polynom->members = NULL;
	polynom->numMembers = 0;
}