#include "Product.h"
#include <iostream>
#include "IllegalArgumentException.h"

using namespace std;

void main()
{
	Product p(Product::ProductType::PACKING);
	Product::Location loc;
	try{
		loc.setAisle('F');
		loc.setShelf(4);
		p.setLocation(loc);
		p.setExposure(Product::Exposure::MAX);
		p.setSerial(1234);
		
		cout <<p;
	}
	catch(IllegalArgumentException e)
	{
		cout<<e;
	}
}