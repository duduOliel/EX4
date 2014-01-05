#include "Cheese.h"

// Error messages initialization
const string Cheese::ADDINGS_RANGE_ERROR = "Addings for cheese must be non-negative";


//************************************************************************
// Method:    Cheese
// FullName:  Cheese::Cheese
// Access:    public 
// Returns:   A new instance of cheese product
// Qualifier: :DairyProduct(name,DairyProduct::CHEESE,colorsInBox,fatPrecentage,location,exposure)
// Parameter: string name - name of the cheese
// Parameter: int colorsInBox - colors in the cheese's box
// Parameter: int fatPrecentage - fat percentage of the cheese
// Parameter: Location location - location of the cheese in the store
// Parameter: Exposure exposure - exposure level of the cheese in the store
// Parameter: int addingsQuantity - amount of addings to the cheese
//************************************************************************
Cheese::Cheese(string name, int colorsInBox, int fatPrecentage, Location location, Exposure exposure, int addingsQuantity)
	:DairyProduct(name,DairyProduct::CHEESE,colorsInBox,fatPrecentage,location,exposure)
{
	// Initialize data members
	setAddingsQuantity(addingsQuantity);
}


Cheese::~Cheese(void)
{
}

//**************************************************
// Method:    calcPrice
// FullName:  Cheese::calcPrice
// Access:    public 
// Returns:   int
// Qualifier:
// Parameter: int factor - price fatore of the store
//
// Calcs price of product according to base price 
// and amount of addings to the cheese
//**************************************************
int Cheese::calcPrice( int factor )
{
	// Price formula : basic dairy product price + amount of addings on cheese
	return (DairyProduct::calcPrice(factor) + getAddingsQuantity());
}


//***************************************
// Method:    setAddingsQuantity
// FullName:  Cheese::setAddingsQuantity
// Access:    public 
// Returns:   void
// Parameter: int addingsQuantity 
//
// Initialize amount of addings on cheese
// if the amount is non-negative
//***************************************
void Cheese::setAddingsQuantity( int addingsQuantity )
{
	// Check if amount of addings is non-negative
	if (addingsQuantity < MIN_ADDINGS)
		throw std::range_error(ADDINGS_RANGE_ERROR);
	else

		// Initialize addings quantity data member
		_addingsQuantity = addingsQuantity;
}

ostream& operator<<(ostream& out, const Cheese& obj)
{
	// Print basic dairy product details
	const DairyProduct& base = (DairyProduct)obj;
	out << base;

	// Print specific to cheese details
	out << " (" << obj.getAddingsQuantity() << ")";

	return (out);
}

