// Cheese.h
// Programmer: Yuval Cohen
// Id:		   204422505

#pragma once
#include "dairyproduct.h"

/************************************************************************/
/* Represents cheese type of product in the store with specified		*/
/* addings to he cheese													*/
/************************************************************************/
class Cheese : public DairyProduct
{
private:

	// Data Members
	int _addingsQuantity;

	// Static Consts
	static const int MIN_ADDINGS = 0;

	// Static Error Messages
	static const string ADDINGS_RANGE_ERROR;

public:

	// Ctor Dtor
	Cheese(string name, int colorsInBox, int fatPrecentage, Location location, Exposure exposure, int addingsQuantity);
	virtual ~Cheese(void);

	// Accessors 
	int getAddingsQuantity() const { return _addingsQuantity; }
	void setAddingsQuantity(int addingsQuantity);

	// Calculation Method
	int calcPrice(int factor);

	// Print Method
	friend ostream& operator<<(ostream& out, const Cheese& obj);
};

