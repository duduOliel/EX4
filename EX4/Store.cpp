#include "Store.h"


Store::Store(string name, int factor)
{
	_name = name;
	_publicityFactor = factor;
	_products = NULL;
	_productsAmount = 0;
}


Store::~Store(void)
{
	if (_products != NULL)
	{
		delete[] _products;
	}
}

void Store::addProduct(const Product& product)
{
	Product** tempArr = new Product*[_productsAmount + 1];
	
	// Copy the old array to temp
	for (int i = 0 ; i < _productsAmount ; i++)
	{
		tempArr[i] = _products[i];
	}

	tempArr[_productsAmount++] = new Product(product);

	if (_products != NULL)
	{
		delete[] _products;
	}

	_products = tempArr;
}

int Store::sumAllPrices() const
{
	int sum = 0;
	for (int i = 0 ; i < _productsAmount ; i++)
	{
		sum+=_products[i]->calcPrice(_publicityFactor);
	}

	return sum;
}

ostream& operator<<(ostream& out, const Store& obj)
{
	out<<"Store Name: "<<obj._name<<" Products Amount: "<<obj._productsAmount<<" Publicity Factor: "<<obj._publicityFactor<<endl;
	for(int i = 0 ; i < obj._productsAmount ; i++)
	{
		out<<*obj._products[i]<<endl;
	}
	return 	out;
}