#include "EnhancedDairyProduct.h"

// Error messages initialization
const string EnhancedDairyProduct::NEGATIVE_NON_DAIRY_ERR = "Amount of non-dairy components must be non-negative";


//**********************************************************
// Method:    EnhancedDairyProduct
// FullName:  EnhancedDairyProduct::EnhancedDairyProduct
// Access:    public 
// Returns:   A new instance of enhanced dairy product
// Qualifier: :DairyProduct(name, DairyProduct::OTHER,colorsInBox,fatPrecentage,location,exposure)
// Parameter: string name - name of product
// Parameter: int colorsInBox - amount of colors in boxing
// Parameter: int fatPrecentage - fat percentages of product
// Parameter: Location location - location of product in store
// Parameter: Exposure exposure - exposure level of product in store
// Parameter: string * arrNonDairyComponents 
//	- array containing the names of every non-dairy component in product
// Parameter: int nonDairyQuantity - number of non-dairy components in product
//**********************************************************
EnhancedDairyProduct::EnhancedDairyProduct( string name, 
											int colorsInBox, 
											int fatPrecentage, 
											Location location,
											Exposure exposure, 
											string* arrNonDairyComponents,
											int nonDairyQuantity )
	:DairyProduct(name, DairyProduct::OTHER,colorsInBox,fatPrecentage,location,exposure)
{
	// Initialize data members
	setArrNonDairyComponents(arrNonDairyComponents);
	setNonDairyQuantity(nonDairyQuantity);
}


EnhancedDairyProduct::~EnhancedDairyProduct(void)
{
}

//************************************
// Method:    setNonDairyQuantity
// FullName:  EnhancedDairyProduct::setNonDairyQuantity
// Access:    public 
// Returns:   void
// Parameter: int nonDairyQuantity
//
// Initializes amount of non-dairy components 
// if it's non-negative
//************************************
void EnhancedDairyProduct::setNonDairyQuantity( int nonDairyQuantity )
{
	// Checks if amount of non-dairy is non-negative
	if (nonDairyQuantity < MIN_NON_DAIRY)
		throw std::range_error(NEGATIVE_NON_DAIRY_ERR);
	else

		// Initialize the data member
		_nonDairyQuantity = nonDairyQuantity;
}

//************************************
// Method:    calcPrice
// FullName:  EnhancedDairyProduct::calcPrice
// Access:    public 
// Returns:   int
// Parameter: int factor
//
// Calcs price of product according to 
// basic price of dairy product and
// non-dairy components amount
//************************************
int EnhancedDairyProduct::calcPrice( int factor )
{
	// Formula for price : basic dairy product price + 
	//	(number of non-dary component times a constant factor)
	return (DairyProduct::calcPrice(factor) + (getNonDairyQuantity() * NON_DAIRY_FACTOR));
}

ostream& operator<<(ostream& out, const EnhancedDairyProduct& obj)
{
	// Print basic DairyProduct details
	DairyProduct& base = (DairyProduct)obj;
	out << base << " ";

	int nonDairyQuantity = obj.getNonDairyQuantity();

	// Print every non-dairy component
	for (int i = 0; i < nonDairyQuantity ; i++)
	{
		out << obj.getArrNonDairyComponents()[i] << " ";
	}

	// Print amount of non-dairy components
	out << "(" << nonDairyQuantity << ")";

	return (out);
}
