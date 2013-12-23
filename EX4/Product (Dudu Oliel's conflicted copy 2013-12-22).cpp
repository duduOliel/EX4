#include "Product.h"
#include <string>
#include "IllegalArgumentException.h"


Product::Product(ProductType productType)
{
	_productType = productType;
	this->_amount = 0;
}


Product::~Product(void)
{
}

void Product::Location::setAisle(char aisle)
{
	aisle = toupper(aisle);
	if (aisle < 'A' || aisle > 'Z')
	{
		throw IllegalArgumentException("Aisle must be between A and Z (case insensetive)");

	}
	_aisle = aisle;
}

void Product::Location::setShelf(int shelf)
{
	if (shelf < 0 || shelf > 5)
	{
		throw IllegalArgumentException("Shelf number should be between 1 and 5");
	}
	_shelf = shelf;
}

ostream& operator<<(ostream& out, const Product& obj)
{
	out<<obj.getSerial()<<" "<<obj.getLocation()<<" ("<<obj.getAmount()<<","<<obj.getProductType()<<","<<obj.getExposure()<<")";
	return out;
}