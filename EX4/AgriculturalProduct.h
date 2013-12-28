#pragma once
#include <string>
#include "product.h"

using namespace std;

class AgriculturalProduct :	public Product
{
	public:
		enum AgriculturalProductType
		{
			VEGETABLE = 1,
			FRUIT
		};

private:
	string _name;
	AgriculturalProductType _agriculturalProductType;
	int _ripeSeasons;
	int _providersAmount;

public:
	AgriculturalProduct(string name, int ripeSeasons, int providerAmount,Location location,Exposure exposure, AgriculturalProductType agriculturalProductType);
	virtual ~AgriculturalProduct(void);

	// Accessors
	void setName(string name) {_name = name;}
	const string& getName() const {return _name;}
	void setAgriculturalProductType(AgriculturalProductType agriculturalProductType) {_agriculturalProductType = agriculturalProductType;}
	AgriculturalProductType getAgriculturalProductType() const {return _agriculturalProductType;}
	void setRipeSeasons(int numOfSeasons);
	int getRipeSeasons() const {return _ripeSeasons;}
	void setProvierAmount(int providersAmount) {_providersAmount = providersAmount;}
	int getProviderAmount() const {return _providersAmount;}

	// Calulation Methods
	int calcPrice(int factor) const;

	// Print Method
	friend ostream& operator<<(ostream& out, const AgriculturalProduct& obj);
};

