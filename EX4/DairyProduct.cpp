#include "DairyProduct.h"

const string DairyProduct::PRECENTAGE_RANGE_ERROR = "Percentage given must be between 0 and 100";
const string DairyProduct::NEGATIVE_COLORS_ERROR = "Amount of colors in boxing must be non-negative";


DairyProduct::DairyProduct(string name, DairyProductType dairyProductType, int colorsInBox, int fatPrecentage, Location location, Exposure exposure):Product(location,exposure,ProductType::DAIRY)
{
	setName(name);
	setDairyProductType(dairyProductType);
	setColorsInBox(colorsInBox);
	setFatPrecentage(fatPrecentage);
}


DairyProduct::~DairyProduct(void)
{
}

void DairyProduct::setFatPrecentage( int fatPrecentage)
{
	if (fatPrecentage < MIN_PRECENTAGE || fatPrecentage > MAX_PRECENTAGE)
		throw std::range_error(PRECENTAGE_RANGE_ERROR);
	else
		_fatPrecentage = fatPrecentage;
}

void DairyProduct::setColorsInBox( int colorsInBox )
{
	if (colorsInBox < MIN_COLORS)
		throw std::range_error(NEGATIVE_COLORS_ERROR);
	else
		_colorsInBox = colorsInBox;
}

int DairyProduct::calcPrice( int factor ) const
{
	return (Product::calcPrice(factor) + getColorsInBox() - int(getFatPrecentage())) * int(getDairyProductType());
}

ostream& operator<<(ostream& out, const DairyProduct& obj)
{
	const Product& base = (Product)obj;
	out << base << " " << obj.getName() <<" ("<<obj.getDairyProductType() << ","<< obj.getColorsInBox() << "," << obj.getFatPrecentage() << ")";
	return out;
}