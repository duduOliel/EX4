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
		friend ostream& operator<<(ostream& out, const Location& obj);
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
	static int nextSerial;

	long _serial;
	Location _location;
	int _quantity;
	ProductType _productType;
	Exposure _exposure;

protected:
	// Only subclasses can create this class in particular as a base class
	Product(Location location,Exposure exposure, ProductType productType);

public:
	// No copy constructor since there is no special copy requirements
	
	// Destructor
	virtual ~Product(void);
	
	// Accessors
	long getSerial() const {return _serial;}
	void setLocation(const Location& location) {_location = location;}
	const Location& getLocation() const {return _location;}
	int getQuantity() const {return _quantity;}
	void setQuantity(int quantity) {_quantity = quantity;}
	ProductType getProductType() const {return _productType;}
	void setExposure(Exposure exposure) {_exposure = exposure;}
	Exposure getExposure() const {return _exposure;}
	
	// Calculation Methods
	virtual int calcPrice(int factor) const {return getQuantity() * getExposure() * factor;}

	// Print Method
	friend ostream& operator<<(ostream& out, const Product& obj); 
};

