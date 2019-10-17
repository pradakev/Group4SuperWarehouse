#include "item.h"

/*******************************************************************************
 * CONSTRUCTOR : Class Item
 * -----------------------------------------------------------------------------
 * This constructor initializes a name, item price, quantity available,
 * & quantity sold. It is ready for implementation.
 * -----------------------------------------------------------------------------
 * PRECONDITIONS
 * POSTCONDITIONS
 *  A charStack object is created
 ******************************************************************************/
Item::Item():name("Item Name"), totalSalesPrice(0), quantityAvailable(0), quantitySold(0)
{
}

/*******************************************************************************
 * CONSTRUCTOR : Class Item
 * -----------------------------------------------------------------------------
 * This constructor initializes a name, & item price. It is ready for implementation.
 * -----------------------------------------------------------------------------
 * PRECONDITIONS
 * POSTCONDITIONS
 *  A charStack object is created
 ******************************************************************************/
Item::Item(std::string name, double totalSalesPrice):name(name), totalSalesPrice(totalSalesPrice), quantityAvailable(0), quantitySold(0)
{
}

/*******************************************************************************
 * CONSTRUCTOR : Class Item
 * -----------------------------------------------------------------------------
 * This constructor initializes a name, item price, quantity available,
 * & quantity sold. It is ready for implementation.
 * -----------------------------------------------------------------------------
 * PRECONDITIONS
 * POSTCONDITIONS
 *  A charStack object is created
 ******************************************************************************/
Item::Item(std::string name, double totalSalesPrice, int quantityAvailable, int quantitySold):name(name), totalSalesPrice(totalSalesPrice), quantityAvailable(quantityAvailable), quantitySold(quantitySold)
{
}

/*******************************************************************************
 * CONSTRUCTOR : Class Item
 * -----------------------------------------------------------------------------
 * This constructor initializes a name, item price, day purchased
 * & quantity sold. It is ready for implementation.
 * -----------------------------------------------------------------------------
 * PRECONDITIONS
 * POSTCONDITIONS
 *  A charStack object is created
 ******************************************************************************/
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
/*******************************************************************************
 * getDateBought() : Class Item
 * -----------------------------------------------------------------------------
 * This method returns the day bought parameter of the Item object.
 * -----------------------------------------------------------------------------
 * PRECONDITIONS
 * POSTCONDITIONS
 *  Appropriate parameter is returned.
 ******************************************************************************/
string Item::getDateBought()
{
    return dayBought;
}

/*******************************************************************************
 * getName() : Class Item
 * -----------------------------------------------------------------------------
 * This method returns the name parameter of the Item object.
 * -----------------------------------------------------------------------------
 * PRECONDITIONS
 * POSTCONDITIONS
 *  Appropriate parameter is returned.
 ******************************************************************************/
std::string Item::getName()
{
	return name;
}

/*******************************************************************************
 * getPrice() : Class Item
 * -----------------------------------------------------------------------------
 * This method returns the sales price parameter of the Item object.
 * -----------------------------------------------------------------------------
 * PRECONDITIONS
 * POSTCONDITIONS
 *  Appropriate parameter is returned.
 ******************************************************************************/
double Item::getPrice()
{
	return totalSalesPrice;
}

/*******************************************************************************
 * getQuantityAvailable() : Class Item
 * -----------------------------------------------------------------------------
 * This method returns the quantity available parameter of the Item object.
 * -----------------------------------------------------------------------------
 * PRECONDITIONS
 * POSTCONDITIONS
 *  Appropriate parameter is returned.
 ******************************************************************************/
int Item::getQuantityAvailable()
{
	return quantityAvailable;
}

/*******************************************************************************
 * getQuantitySold() : Class Item
 * -----------------------------------------------------------------------------
 * This method returns the quantity sold parameter of the Item object.
 * -----------------------------------------------------------------------------
 * PRECONDITIONS
 * POSTCONDITIONS
 *  Appropriate parameter is returned.
 ******************************************************************************/
int Item::getQuantitySold()
{
	return quantitySold;
}

/*******************************************************************************
 * allInfo() : Class Item
 * -----------------------------------------------------------------------------
 * This method returns the items info in a string.
 * -----------------------------------------------------------------------------
 * PRECONDITIONS
 * POSTCONDITIONS
 *  String with info of Item is returned.
 ******************************************************************************/
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

