#pragma once
#include <iostream>
using namespace std;

class Product
{
public:

	// Inner structure to represent location of product in store
	struct Location
	{
	private:
		char _aisle;
		int _shelf;
	public:
		void setAisle(char aisle);
		char getAisle() const {return _aisle;}
		void setShelf(int shelf);
		int getShelf() const {return _shelf;};
		friend ostream& operator<<(ostream& out, Location obj) { return out<<obj.getAisle()<<" "<<obj.getShelf();}
	};
	enum ProductType
	{
		AGRICULTURAL = 1,
		DAIRY,
		PACKING
	};

	enum Exposure
	{
		MAX = 1,
		MEDIUM, 
		HIDDEN
	};

private:
	long _serial;
	Location _location;
	int _amount;
	ProductType _productType;
	Exposure _exposure;

protected: 
	// Only subclasses can create this class in particula as a base class
	Product(ProductType productType);

public:

	virtual ~Product(void);

	// Accessors
	void setSerial(long serival) { _serial = serival;}
	long getSerial() const {return _serial;}
	void setLocation(const Location& location) {_location = location;}
	const Location& getLocation() const {return _location;}
	int getAmount() const {return _amount;}
	ProductType getProductType() const {return _productType;}
	void setExposure(Exposure exposure) {_exposure = exposure;}
	Exposure getExposure() const {return _exposure;}
	
	// Calulation Methods
	virtual int calcPrice(int factor) {return getAmount() * getExposure() * factor;}

	// Print Method
	friend ostream& operator<<(ostream& out, const Product& obj); 
};

