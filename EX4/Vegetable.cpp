#include "Vegetable.h"


Vegetable::Vegetable(int vitaminAmount, string name, int ripeSeasons, int providerAmount,Location location,Exposure exposure):AgriculturalProduct(name, ripeSeasons, providerAmount, location, exposure, AgriculturalProduct::VEGETABLE) {
	_vitaminsAmount = _vitaminsAmount;
}


ostream& operator<<(ostream& out, const Vegetable& obj)
{
	AgriculturalProduct agProduct = (AgriculturalProduct)obj;
	out<<agProduct<<" ("<<obj._vitaminsAmount<<")";
	return out;
}

