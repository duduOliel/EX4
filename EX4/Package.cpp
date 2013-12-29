#include "Package.h"


Package::Package(string* productNames, int productAmount, int colors,Location location,Exposure exposure):Product(location, exposure, Product::PACKING)
{
	_colors = colors;
	_productsAmount = productAmount;
	if (_productsAmount == 0)
	{
		_productsNames = NULL;
	}else{
		_productsNames = new string[_productsAmount];
		for (int i = 0 ; i < _productsAmount ; i++)
		{
			_productsNames[i] = productNames[i];
		}
	}
}


Package::~Package(void)
{
	if (_productsNames != NULL)
	{
		delete[] _productsNames;
	}
}

void Package::addProduct(string name)
{
	string* tempArr = new string[_productsAmount + 1];
	// Copy current array to temp array
	for (int i = 0 ; i < _productsAmount ; i++)
	{
		tempArr[i] = _productsNames[i];
	}

	
	if (_productsNames != NULL)
	{
		delete[] _productsNames;
	}

	// set temporary array to be new tenp array
	_productsNames = tempArr;
	
	// put new product, increment product amount
	_productsNames[_productsAmount++] = name;

}

void Package::removeProduct(string name)
{
	// count name occurrences
	int count = 0;
	for (int i = 0 ; i < _productsAmount ; i++)
	{
		if (_productsNames[i] == name)
		{
			count++;
		}
	}

	// Copy array to temporary array, without removed products
	string* tempArr = new string[_productsAmount - count];
	for (int i = 0 ; i < _productsAmount - count ; i++)
	{
		if (_productsNames[i] != name)
		{
			tempArr[i] = _productsNames[i];
		}
	}

	// set temp arr as the new names array
	_productsNames = tempArr;
}



ostream& operator<<(ostream& out, const Package& obj)
{
	out<<(Product)obj<<" ";
	if (obj._productsAmount > 0)
	{
		out<<obj._productsNames[0];
		for (int i = 0 ; i < obj._productsAmount ; i++){
			out<<", "<<obj._productsNames[i];
		}
	}
	out<<" ("<<obj._productsAmount<<","<<obj._colors<<")";
	return out;
}