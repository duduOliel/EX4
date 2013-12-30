#pragma once
#include "product.h"
#include <string>
using namespace std;

class DairyProduct : public Product
{
	public:
		enum DairyProductType
		{
			DRINK = 1,
			YOGURT,
			CHEESE,
			OTHER
		};

private:

	// Data Members
	string _name;
	DairyProductType _dairyProductType;
	int _colorsInBox;
	int _fatPrecentage;

	// Static Consts
	static const int MIN_PRECENTAGE = 0;
	static const int MAX_PRECENTAGE = 100;
	static const int MIN_COLORS		= 0;

	// Static Error Messages
	static const string PRECENTAGE_RANGE_ERROR;
	static const string NEGATIVE_COLORS_ERROR;


public:
	DairyProduct(string name, DairyProductType dairyProductType, int colorsInBox, int fatPrecentage, Location location,Exposure exposure);
	virtual ~DairyProduct(void);

	// Accessors
	string getName() const { return _name; }
	void setName(string name) { _name = name; }
	DairyProductType getDairyProductType() const { return _dairyProductType; }
	void setDairyProductType(DairyProductType dairyProductType) { _dairyProductType = dairyProductType; }
	int getColorsInBox() const { return _colorsInBox; }
	void setColorsInBox(int colorsInBox) ;
	double getFatPrecentage() const { return _fatPrecentage; }
	void setFatPrecentage(int fatPrecentage) ;

	// Calculation Method
	int calcPrice(int factor) const;

	// Print Method
	friend ostream& operator<<(ostream& out, const DairyProduct& obj);
};

