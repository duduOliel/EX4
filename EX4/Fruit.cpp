#include "Fruit.h"


Fruit::Fruit(int sugarAmount, string name, int ripeSeasons, int providerAmount,Location location,Exposure exposure):AgriculturalProduct(name, ripeSeasons, providerAmount, location, exposure, AgriculturalProduct::VEGETABLE) {
	_sugarAmount = sugarAmount;
}

ostream& operator<<(ostream& out, const Fruit& obj)
{
	AgriculturalProduct agProduct = (AgriculturalProduct)obj;
	out<<agProduct<<" ("<<obj._sugarAmount<<")"
}