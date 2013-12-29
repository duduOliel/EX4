#pragma once
#include <string>
#include "product.h"


class Package :	public Product
{
private:
	int _productsAmount;
	string* _productsNames;
	int _colors;


public:
	Package(string* productNames, int productAmount, int colors,Location location,Exposure exposure);
	virtual ~Package(void);

	void addProduct(string name);
	void removeProduct(string name);
	void setColors(int colors) {_colors = colors;}
	int getColors() const {return _colors;}

	int calcPrice(int factor) const {return ((Product::calcPrice(factor) * 2) * _productsAmount) + (_colors / 3);}

	friend ostream& operator<<(ostream& out, const Package& obj);
};

