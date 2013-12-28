#pragma once
#include <string>
#include "agriculturalproduct.h"

using namespace std;

class Vegetable :
	public AgriculturalProduct
{
private:
	int _vitaminsAmount;

public:
	Vegetable(int vitaminAmount, string name, int ripeSeasons, int providerAmount,Location location,Exposure exposure);
	// No copy constructor - the default one is good enough.
	virtual ~Vegetable(void) {}

	// Accessors
	void setVitaminsAmount(int vitaminsAmont) {_vitaminsAmount = vitaminsAmont;}
	int getVitaminsAmount() const {return _vitaminsAmount;}

	// Calculation methods
	virtual int calcPrice(int factor) const {return AgriculturalProduct::calcPrice(factor) + (_vitaminsAmount * 2);}

	friend ostream& operator<<(ostream& out, const Vegetable& obj);

};

