#ifndef POLYNOM_FUNCTIONS
#define POLYNOM_FUNCTIONS

struct PolynomMember
{
	int exp;
	float coef;
	PolynomMember() : exp(0), coef(0) {}
};

struct Polynom
{
private:
	PolynomMember *members;
	int numMembers;
public:
	Polynom() : members(nullptr), numMembers(0){}
	~Polynom()
	{
		delete[] members;
	}
	void friend IntegralPolynom(const Polynom *pol, Polynom *result);
	void friend CurriedPolynom(const Polynom *pol, Polynom *result);
	void friend InitMem(Polynom *polynom, int num);
	void friend InitPolynom(Polynom *polynom);
	void friend EnterPolynom(Polynom *polynom);
	void friend PopulatePolynom(Polynom *polynom);
	void friend FreePolynom(Polynom *polynom);
	void friend PrintPolynom(Polynom *polynom);
};

#endif