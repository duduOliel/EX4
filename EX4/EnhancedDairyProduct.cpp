#include "EnhancedDairyProduct.h"


const string EnhancedDairyProduct::NEGATIVE_NON_DAIRY_ERR = "Amount of non-dairy components must be non-negative";


EnhancedDairyProduct::EnhancedDairyProduct( string name, 
											int colorsInBox, 
											int fatPrecentage, 
											Location location,
											Exposure exposure, 
											string* arrNonDairyComponents,
											int nonDairyQuantity )
	:DairyProduct(name, DairyProduct::OTHER,colorsInBox,fatPrecentage,location,exposure)
{
	setArrNonDairyComponents(arrNonDairyComponents);
	setNonDairyQuantity(nonDairyQuantity);
}


EnhancedDairyProduct::~EnhancedDairyProduct(void)
{
}

void EnhancedDairyProduct::setNonDairyQuantity( int nonDairyQuantity )
{
	if (nonDairyQuantity < MIN_NON_DAIRY)
		throw std::range_error(NEGATIVE_NON_DAIRY_ERR);
	else
		_nonDairyQuantity = nonDairyQuantity;
}

int EnhancedDairyProduct::calcPrice( int factor )
{
	return (DairyProduct::calcPrice(factor) + (getNonDairyQuantity() * NON_DAIRY_FACTOR));
}

ostream& operator<<(ostream& out, const EnhancedDairyProduct& obj)
{
	DairyProduct& base = (DairyProduct)obj;
	out << base << " ";
	int nonDairyQuantity = obj.getNonDairyQuantity();

	// Print every non-dairy component
	for (int i = 0; i < nonDairyQuantity ; i++)
	{
		out << obj.getArrNonDairyComponents()[i] << " ";
	}

	out << "(" << nonDairyQuantity << ")";
	return out;
}
