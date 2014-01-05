// EnhancedDairyProduct.h
// Programmer: Yuval Cohen
// Id:		   204422505

#pragma once
#include "dairyproduct.h"
#include <string>

/************************************************************************/
/* Represents a dairy product containing non-dairy componenets in store */
/************************************************************************/
class EnhancedDairyProduct : public DairyProduct
{

private:

	// Data Members
	int _nonDairyQuantity;
	string* _arrNonDairyComponents;

	// Static Consts
	static const int MIN_NON_DAIRY = 0;
	static const int NON_DAIRY_FACTOR = 5;

	// Static Error Messages
	static const string NEGATIVE_NON_DAIRY_ERR;

public:

	// Ctor Dtor
	EnhancedDairyProduct(string name, int colorsInBox, int fatPrecentage, Location location,Exposure exposure,  string* arrNonDairyComponents ,int nonDairyQuantity);
	virtual ~EnhancedDairyProduct(void);

	// Accessors
	int getNonDairyQuantity() const { return _nonDairyQuantity; }
	void setNonDairyQuantity(int nonDairyQuantity);
	string* getArrNonDairyComponents() const { return _arrNonDairyComponents; }
	void setArrNonDairyComponents(string* nonDairyComponents) { _arrNonDairyComponents = nonDairyComponents; }

	// Calculation Method
	int calcPrice(int factor);

	// Printing Method
	friend ostream& operator<<(ostream& out, const EnhancedDairyProduct& obj);
};

