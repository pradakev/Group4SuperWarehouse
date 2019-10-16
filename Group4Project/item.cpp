#include "item.h"

//Default CTOR
Item::Item():name("Item Name"), totalSalesPrice(0), quantityAvailable(0), quantitySold(0)
{
}

Item::Item(std::string name, double totalSalesPrice):name(name), totalSalesPrice(totalSalesPrice), quantityAvailable(0), quantitySold(0)
{
}

Item::Item(std::string name, double totalSalesPrice, int quantityAvailable, int quantitySold):name(name), totalSalesPrice(totalSalesPrice), quantityAvailable(quantityAvailable), quantitySold(quantitySold)
{
}

Item::Item(string nName, double nPrice, int nQuantityBought, string nDayBought)
{
    name = nName;
    totalSalesPrice = nPrice;
    quantitySold = nQuantityBought;
    dayBought = nDayBought;
}

/*******************
* ACCESSOR(S)
********************/
string Item::getDateBought()
{
    return dayBought;
}
std::string Item::getName()
{
	return name;
}

double Item::getPrice()
{
	return totalSalesPrice;
}

int Item::getQuantityAvailable()
{
	return quantityAvailable;
}

int Item::getQuantitySold()
{
	return quantitySold;
}

string Item::allInfo()
{
    stringstream ss;
    ss << name << endl;
    ss << totalSalesPrice << "\t";
    ss << quantitySold << endl;
    ss << dayBought << endl;

    string all;
    all = ss.str();
    return all;
    
}
/*******************
* MUTATOR(S)
********************/

void Item::changeName(std::string nName)
{
	name = nName;
}

void Item::changePrice(double nPrice)
{
	totalSalesPrice = nPrice;
}

void Item::changeQSold(int sold)
{
	quantitySold = sold;
}

void Item::changeQAvailable(int available)
{
	quantityAvailable = available;
}

/*******************
* CLASS TEST(S)
********************/	
// void Item::testItemClass()
// {
// 	cout << "=================================" << endl;
// 	cout << "Testing Default CTOR Item" << endl;
// 	Item a;
// 	a.outputInfo();
// 	cout << "=================================" << endl;
// 	cout << "Testing 2 Parameter CTOR Item" << endl;
// 	Item b("Cereal", 12.50);
// 	b.outputInfo();
// 	cout << "=================================" << endl;
// 	cout << "Testing 4 Parameter CTOR Item" << endl;
// 	Item c("Cereal", 12.50, 100, 50);
// 	c.outputInfo();
// 	cout << "=================================" << endl;
// }

void Item::outputInfo()
{
	cout << "Item: " << getName() << endl;
	cout << "Sales Price: " << getPrice() << endl;
	cout << "Quantity Available: " << getQuantityAvailable() << endl;
	cout << "Quantity Sold: " << getQuantitySold() << endl;
}

double Item::operator+(const Item& RHSITEM) const
{
    return(totalSalesPrice + RHSITEM.totalSalesPrice);
}

