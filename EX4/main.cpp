#include <iostream>
#include "Product.h"
#include "AgriculturalProduct.h"
#include "IllegalArgumentException.h"

using namespace std;

void main()
{
	AgriculturalProduct p(AgriculturalProduct::AgriculturalProductType::FRUIT);
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
	}
}