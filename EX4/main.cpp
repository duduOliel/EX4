#include <iostream>
#include <string>
#include "Product.h"
#include "AgriculturalProduct.h"
#include "IllegalArgumentException.h"
#include "Package.h"

using namespace std;

void main()
{
	Product::Location loc;
	loc.setAisle('a');
	loc.setShelf(2);
	string* names = new string[2];
	names[0] ="sadfd";
	names[1] = "aaa";
	Package p (names,2,34,loc, Product::MAX);
	cout<<p;
	/*AgriculturalProduct p(AgriculturalProduct::AgriculturalProductType::FRUIT);
	AgriculturalProduct q(AgriculturalProduct::AgriculturalProductType::FRUIT);

	Product::Location loc;
	try{
		loc.setAisle('F');
		loc.setSelf(2);
		p.setLocation(loc);
		p.setExposure(Product::Exposure::HIDDEN);
		p.setRipeSeasons(3);
		p.setName("name");
		p.setProvierAmount(3);
		p.setQuantity(1000);
		//p.setSerial(324);
		cout<<p<<endl<<q;
	}
	catch(IllegalArgumentException e)
	{
		cout<<e;
	}*/
}