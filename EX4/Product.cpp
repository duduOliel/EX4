#include "Product.h"
#include <string>
#include "IllegalArgumentException.h"

// Static initialization
int Product::nextSerial = 1;

Product::Product(Location location,Exposure exposure, ProductType productType)
{
	_productType = productType;
	_serial = nextSerial++;
	_location = location;
	_quantity = 0;
	_exposure = exposure;
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

ostream& operator<<(ostream& out, const Product::Location& obj)
{
	out<<obj.getAisle()<<" "<<obj.getShelf();
	return out;
}

ostream& operator<<(ostream& out, const Product& obj)
{
	out<<obj.getSerial()<<" "<<obj.getLocation()<<"("<<obj.getQuantity()<<","<<obj.getProductType()<<","<<obj.getExposure()<<")" << endl;
	return out;		
}