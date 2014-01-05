// DairyProduct.cpp
// Programmer: Yuval Cohen
// Id:		  204422505

#include "DairyProduct.h"

// Error messages initialization 
const string DairyProduct::PRECENTAGE_RANGE_ERROR = "Percentage given must be between 0 and 100";
const string DairyProduct::NEGATIVE_COLORS_ERROR = "Amount of colors in boxing must be non-negative";


//******************************************************************************
// Method:    DairyProduct (CTOR)
// FullName:  DairyProduct::DairyProduct
// Access:    public 
// Returns:   New instance of a dairy product
// Qualifier: :Product(location,exposure,ProductType::DAIRY)
// Parameter: string name - name of the product
// Parameter: DairyProductType dairyProductType - sub-category of dairy product
// Parameter: int colorsInBox - Number of colors in product's boxing
// Parameter: int fatPrecentage - Percentage of fat in the product
// Parameter: Location location - location in store
// Parameter: Exposure exposure - level of exposure in the store
//******************************************************************************
DairyProduct::DairyProduct(string name, DairyProductType dairyProductType, int colorsInBox, int fatPrecentage, Location location, Exposure exposure):Product(location,exposure,ProductType::DAIRY)
{
	// Initialize date members
	setName(name);
	setDairyProductType(dairyProductType);
	setColorsInBox(colorsInBox);
	setFatPrecentage(fatPrecentage);
}


DairyProduct::~DairyProduct(void)
{
}

//*******************************************
// Method:    setFatPrecentage
// FullName:  DairyProduct::setFatPrecentage
// Access:    public 
// Returns:   void
// Parameter: int fatPrecentage
// 
// Initialize fat percentage data members
// if percentage given is within legal range
//*******************************************
void DairyProduct::setFatPrecentage( int fatPrecentage)
{
	// Percentage range check
	if (fatPrecentage < MIN_PRECENTAGE || fatPrecentage > MAX_PRECENTAGE)
		throw std::range_error(PRECENTAGE_RANGE_ERROR);
	else

		// Initialize fat percentage data member
		_fatPrecentage = fatPrecentage;
}


//**********************************************
// Method:    setColorsInBox
// FullName:  DairyProduct::setColorsInBox
// Access:    public 
// Returns:   void
// Parameter: int colorsInBox
//
// Initialize number of colors in product's box
// if number given is non-negative
//**********************************************
void DairyProduct::setColorsInBox( int colorsInBox )
{
	// Checks the number is non-negative
	if (colorsInBox < MIN_COLORS)
		throw std::range_error(NEGATIVE_COLORS_ERROR);
	else

		// Init colors in boxing data member
		_colorsInBox = colorsInBox;
}

//************************************
// Method:    calcPrice
// FullName:  DairyProduct::calcPrice
// Access:    public 
// Returns:   int
// Qualifier: const
// Parameter: int factor 
//	- price factor of containing store
//
// Calcs price of product
//************************************
int DairyProduct::calcPrice( int factor ) const
{
	// Formula for DairyProduct price : (base price + boxing colors - fat percentages) * sub-category sequental id
	return (Product::calcPrice(factor) + getColorsInBox() - int(getFatPrecentage())) * int(getDairyProductType());
}

//***************************************
// Method:    operator<<
// FullName:  operator<<
// Access:    public 
// Returns:   ostream&
// Parameter: ostream & out
// Parameter: const DairyProduct & obj
//
// Prints product information including
// product type , color in boxing and
// fat percentage
//***************************************
ostream& operator<<(ostream& out, const DairyProduct& obj)
{
	const Product& base = (Product)obj;

	// Print basic information of product
	out << base ;

	// Print the name of the product
	out << " " << obj.getName();

	// Print dairy product related information
	out << " ("<<obj.getDairyProductType() << ","<< obj.getColorsInBox() << "," << obj.getFatPrecentage() << ")";

	return (out);
}