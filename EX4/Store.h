#pragma once
#include <string>
#include "Product.h"

using namespace std;

class Store
{
private:
	string _name;
	int _publicityFactor;
	int _productsAmount;
	Product** _products;

public:
	Store(string name, int factor);
	~Store(void);

	// Accessors
	void setName(string name) {_name = name;}
	string getName() const {return _name;}
	void setPublicityFactor(int factor) {_publicityFactor = _productsAmount;}
	int getPublicityFactor() const {return _publicityFactor;}


	void addProduct(const Product& product);
	int sumAllPrices() const;

	friend ostream& operator<<(ostream& out, const Store& obj);
};

