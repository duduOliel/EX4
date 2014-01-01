#include "Cheese.h"


const string Cheese::ADDINGS_RANGE_ERROR = "Addings for cheese must be non-negative";


Cheese::Cheese(string name, int colorsInBox, int fatPrecentage, Location location, Exposure exposure, int addingsQuantity)
	:DairyProduct(name,DairyProduct::CHEESE,colorsInBox,fatPrecentage,location,exposure)
{
	setAddingsQuantity(addingsQuantity);
}


Cheese::~Cheese(void)
{
}

int Cheese::calcPrice( int factor )
{
	return (DairyProduct::calcPrice(factor) + getAddingsQuantity());
}

void Cheese::setAddingsQuantity( int addingsQuantity )
{
	if (addingsQuantity < MIN_ADDINGS)
		throw std::range_error(ADDINGS_RANGE_ERROR);
	else
		_addingsQuantity = addingsQuantity;
}

ostream& operator<<(ostream& out, const Cheese& obj)
{
	const DairyProduct& base = (DairyProduct)obj;
	out << base << " (" << obj.getAddingsQuantity() << ")";
	return out;
}

