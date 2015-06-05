#ifndef POLYNOM_FUNCTIONS
#define POLYNOM_FUNCTIONS

struct PolynomMember
{
	int exp;
	float coef;
};

struct Polynom
{
	PolynomMember *members;
	int numMembers;
};
void IntegralPolynom(const Polynom *pol, Polynom *result);
void CurriedPolynom(const Polynom *pol, Polynom *result);
void InitMem(Polynom *polynom, int num);
void InitPolynom(Polynom *polynom);
void EnterPolynom(Polynom *polynom);
void PopulatePolynom(Polynom *polynom);
void FreePolynom(Polynom *polynom);
void PrintPolynom(Polynom *polynom);

#endif