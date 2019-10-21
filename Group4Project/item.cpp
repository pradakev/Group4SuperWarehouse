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
/**************************************************************************
* Mutator changeName(std::string nName)
*__________________________________________________________________________
* changes the object name to the passed in nName
*__________________________________________________________________________
* PRO-CONDITIONS:
*   nName: a new item name
* POST-CONDITIONS:
*   name is set to nName.
*   no return.
**************************************************************************/
void Item::changeName(std::string nName)
{
	name = nName;
}
/**************************************************************************
* Mutator changePrice(double nPrice)
*__________________________________________________________________________
* changes the object totalSalesPrice to the passed in parameter nPrice
*__________________________________________________________________________
* PRO-CONDITIONS:
*   nPrice: a new item price
* POST-CONDITIONS:
*   totalSalesPrice = nPrice
*   no return
**************************************************************************/
void Item::changePrice(double nPrice)
{
	totalSalesPrice = nPrice;
}
/**************************************************************************
* Mutator changeQSold(int sold)
*__________________________________________________________________________
* changes the object quantitySold to the passed in parameter sold
*__________________________________________________________________________
* PRO-CONDITIONS:
*   sold: new quantity sold
* POST-CONDITIONS:
*   quantitySold = sold
*   bo return
**************************************************************************/
void Item::changeQSold(int sold)
{
	quantitySold = sold;
}
/**************************************************************************
* Mutator changeQAvailable(int available)
*__________________________________________________________________________
* changes the object quantityAvailable to the passed in paramter available
*__________________________________________________________________________
* PRO-CONDITIONS:
*   available: new item quantity available
* POST-CONDITIONS:
*   quantityAvailable = available
*   no return
**************************************************************************/
void Item::changeQAvailable(int available)
{
	quantityAvailable = available;
}
/**************************************************************************
* Mutator operator+(const Item& RHSITEM) const
*__________________________________________________________________________
* Adds together the totalSalesPrice of the 2 items together
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Item object being passed in must exist
* POST-CONDITIONS:
*   Returns the total sales price of the two items
**************************************************************************/
double Item::operator+(const Item& RHSITEM) const
{
    return(totalSalesPrice + RHSITEM.totalSalesPrice);
}
/**************************************************************************
* Mutator operator<<(ostream& os, const Item& paramItem)
*__________________________________________________________________________
* Returns an ostream (os) with the name, totalSalesPrice, quantity sold and the
* day bought of the item.
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Item must already exist with a name, totalSalesPrice, quantitySold and the
* day bought
* POST-CONDITIONS:
*   retuns a formatted os stream with all the filled out data
**************************************************************************/
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
