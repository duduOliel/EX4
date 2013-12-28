#include "AgriculturalProduct.h"
#include "IllegalArgumentException.h"
#include "Product.h"


AgriculturalProduct::AgriculturalProduct(string name, int ripeSeasons, int providerAmount,Location location,Exposure exposure, AgriculturalProductType agriculturalProductType):Product(location, exposure, ProductType::AGRICULTURAL)
{
	_agriculturalProductType = agriculturalProductType;
	setRipeSeasons(ripeSeasons);
	_name = name;
	_providersAmount = providerAmount;
}

AgriculturalProduct::~AgriculturalProduct(void)
{
}

void AgriculturalProduct::setRipeSeasons(int numOfSeasons)
{
	if (numOfSeasons < 1 && numOfSeasons > 4)
	{
		throw IllegalArgumentException("Ripe seasons must be between 1 and 4");
	}
	_ripeSeasons = numOfSeasons;
}

int AgriculturalProduct::calcPrice (int factor) const
{
	return Product::calcPrice(factor) * 3 * (5 - getRipeSeasons()) + (getProviderAmount() * 5) + getAgriculturalProductType();
}

ostream& operator<<(ostream& out, const AgriculturalProduct& obj)
{
	const Product& base = (Product)obj;
	out<<base<<" "<<obj.getName()<<" ("<<obj.getAgriculturalProductType()<<","<<obj.getRipeSeasons()<<","<<obj.getProviderAmount()<<")";
	return out;
}
