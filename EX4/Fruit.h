#pragma once
#include "agriculturalproduct.h"
class Fruit :
	public AgriculturalProduct
{
private:
	int _sugarAmount;

public:
	Fruit(int sugrAmount, string name, int ripeSeasons, int providerAmount,Location location,Exposure exposure);
	// No copy constructor - the default one is good enough.
	virtual ~Fruit(void) {}

	// Accessors
	void setSugarAmount(int sugarAmount) {_sugarAmount = sugarAmount;}
	int getSugarAmount() const {_sugarAmount;}

	// Calculation methods
	virtual int calcPrice(int factor) const {return AgriculturalProduct::calcPrice(factor) + (_sugarAmount / 2);}

	friend ostream& operator<<(ostream& out, const Fruit& obj);
};

