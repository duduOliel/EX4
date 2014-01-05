#include "Includer.h"

void main()
{
	// Shop metadata
	const string STORE_NAME = "SuperShop";
	const int PUBLICITY_FACTOR = 3;
	const char FRUIT_AISLE = 'F';
	const char VEG_AISLE = 'V';
	const char DAIRY_AISLE = 'D';

	// Apple metadata
	const int APPLE_SUGAR = 20;
	const string APPLE_NAME = "Yuval's Apple";
	const int APPLE_RIPE = 2;
	const int APPLE_PROVIDORS = 3;
	const int APPLE_SHELF = 5;

	// Carrot metadata
	const int CARROT_VITAMINS = 4;
	const string CARROT_NAME = "Dudu's Carrot";
	const int CARROT_RIPE = 4;
	const int CARROT_PROVIDORS = 2;
	const int CARROT_SHELF = 4;

	// Cheese metadata
	const string CHEESE_NAME = "Yuval's gaudy";
	const int CHEESE_COLORS = 10;
	const int CHEESE_FAT_PERCENT = 30;
	const int CHEESE_SHELF = 1;
	const int CHEESE_ADDINGS = 1;

	// Icecream metadata
	const string ICECREAM_NAME = "Vanila and strawberry ice cream";
	const int ICECREAM_COLORS = 2;
	const int ICECREAM_FAT_PERCENT = 60;
	const int ICECREAM_SHELF = 4;
	const int ICECREAM_COMPONENTS_COUNT = 2;
	string ICECREAM_COMPONENTS[ICECREAM_COMPONENTS_COUNT] = {"VANILA STICK","STRAWBERRY SURBET"};

	// Almost healthy Package metadata
	const int PACKAGE_PROD_COUNT = 4;
	string PACKAGE_PRODUCTS[PACKAGE_PROD_COUNT] = {APPLE_NAME,CARROT_NAME,CHEESE_NAME,ICECREAM_NAME};
	const int PACKAGE_COLORS = 3;
	const int PACKAGE_SHELF = 1;
	
	// Printing empty Shop details
	Store superShop(STORE_NAME,PUBLICITY_FACTOR);
	cout << superShop;

	// Building an apple
	Product::Location appleLocation;
	appleLocation.setAisle(FRUIT_AISLE);
	appleLocation.setShelf(APPLE_SHELF);
	Fruit apple (APPLE_SUGAR,APPLE_NAME,APPLE_RIPE,APPLE_PROVIDORS, appleLocation,Product::MEDIUM);

	// Printing apple details
	cout << apple;

	// Adding apple to the store
	superShop.addProduct(apple);
	cout << superShop.sumAllPrices();

	// Building a carrot
	Product::Location carrotLocation;
	carrotLocation.setAisle(VEG_AISLE);
	carrotLocation.setShelf(CARROT_SHELF);
	Vegetable carrot(CARROT_VITAMINS,CARROT_NAME,CARROT_RIPE,CARROT_PROVIDORS,carrotLocation,Product::MAX);

	// Printing carrot details
	cout << carrot;

	// Adding carrot to the store
	superShop.addProduct(carrot);
	cout << superShop.sumAllPrices();

	// Building cheese
	Product::Location cheeseLocation;
	cheeseLocation.setAisle(DAIRY_AISLE);
	cheeseLocation.setShelf(CHEESE_SHELF);
	Cheese cheese(CHEESE_NAME,CHEESE_COLORS,CHEESE_FAT_PERCENT,cheeseLocation,Product::MEDIUM,CHEESE_ADDINGS);

	// Printing cheese details
	cout << cheese;

	// Adding cheese to the store
	superShop.addProduct(cheese);
	cout << superShop.sumAllPrices();

	// Building icecream 
	Product::Location icecreamLoc;
	icecreamLoc.setAisle(DAIRY_AISLE);
	icecreamLoc.setShelf(ICECREAM_SHELF);
	EnhancedDairyProduct icecream(ICECREAM_NAME,ICECREAM_COLORS,ICECREAM_FAT_PERCENT,icecreamLoc,Product::MAX,ICECREAM_COMPONENTS,ICECREAM_COMPONENTS_COUNT);

	// Printing icecream details
	cout << icecream;

	// Adding cheese to the store
	superShop.addProduct(icecream);
	cout << superShop.sumAllPrices();

	// Building package
	Product::Location pckgLoc;
	pckgLoc.setAisle(DAIRY_AISLE);
	pckgLoc.setShelf(PACKAGE_SHELF);
	Package almostHealthyPackage(PACKAGE_PRODUCTS,PACKAGE_PROD_COUNT,PACKAGE_COLORS,pckgLoc,Product::HIDDEN); // Hidden because this probably taste like shit

	// Printing package details
	cout << pckgLoc;

	// Adding package to the store
	superShop.addProduct(almostHealthyPackage);
	cout << superShop.sumAllPrices();

	// Printing full Shop details
	cout << superShop;
}