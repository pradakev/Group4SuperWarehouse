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
{cout << "\n========INSIDE CONSTRUCTOR 1========\n";
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
{cout <<"\n========INSIDE CONSTRUCTOR 2========\n";
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
{cout << "\n========INSIDE CONSTRUCTOR 3========\n";
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
    cout << "\n========INSIDE CONSTRUCTOR 4========\n";
    name = nName;
    totalSalesPrice = nPrice;
    quantitySold = nQuantityBought;
    dayBought = nDayBought;
}

Item::Item(const Item& paramItem)
{
	name = paramItem.name;
	totalSalesPrice = paramItem.totalSalesPrice;
	quantityAvailable = paramItem.quantityAvailable;
	quantitySold = paramItem.quantitySold;
    dayBought = paramItem.dayBought;
}

//DELETE IF NOT NEEDED - TONI
/*
Item::~Item()
{
    cout << "\n=====Item DESTRUCTOR CALLED======" << endl;
}
*/


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
string Item::getDateBought() const
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
std::string Item::getName() const
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
double Item::getPrice() const
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
int Item::getQuantityAvailable() const
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
int Item::getQuantitySold() const
{
	return quantitySold;
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

double Item::operator+(const Item& RHSITEM) const
{
    return(totalSalesPrice + RHSITEM.totalSalesPrice);
}

ostream& operator<<(ostream& os, const Item& paramItem)
{
    os << "\n========ITEM OBJECT========\n"
        << "++NAME: " << paramItem.name << "\n"
        << "++TOTAL SALES PRICE: " << paramItem.totalSalesPrice << "\n"
//        << "++QTY: " << paramItem.quantityAvailable << "\n"
        << "++SOLD: " << paramItem.quantitySold << "\n"
        << "++DATE BOUGHT: " << paramItem.dayBought << "\n"
        << "==============================\n";
    return os;
}
