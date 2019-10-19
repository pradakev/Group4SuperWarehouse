#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include <sstream>


using namespace std;

class Item
{
public:
	/*******************
	* CONSTRUCTOR(S)
	********************/
	Item();
	Item(std::string name, double totalSalesPrice);
    Item(string nName, double nPrice, int nQuantityBought, string nDayBought);
	Item(std::string name, double totalSalesPrice, 
		 int quantityAvailable, int quantitySold);
    Item(const Item& paramItem);

    /*ACCESSOR(S)

	********************/
	std::string getName() const;
	double getPrice() const;
	int getQuantityAvailable() const;
	int getQuantitySold() const;
    string getDateBought() const;
	
	/*******************
	* MUTATOR(S)
	********************/
	void changeName(std::string nName);
	void changePrice(double nPrice);
	void changeQAvailable(int available);
	void changeQSold(int sold);
	
	/*******************
	* CLASS TEST(S)
	********************/	
	// void testItemClass();
    double operator+(const Item& RHSITEM) const;
    friend ostream& operator<<(ostream& os, const Item& paramItem);	
	/*******************
	* MEMBER DATA
	********************/
private:
	std::string name;			//IN OUT - Name of Item
	double totalSalesPrice;		//IN OUT - Sales orice of Item
	int quantityAvailable;		//IN OUT - Quantity available in stock
	int quantitySold;			//IN OUT - Quantity sold
    string dayBought;
};


#endif //ITEM_H

/*******************************************************************************
 * Item Class
 * This class contains 4 attributes. It has a item name, sales price of the item
 * , item quantity available, and item quantity sold.
 ******************************************************************************/

/***********************************
 * CTOR 
 * ********************************/
/*******************************************************************************
 * Item()
 * Default CTOR: Constructs a blank item object
 * Parameters:none
 * Return:none
 ******************************************************************************/

/*******************************************************************************
 * Item(name, totalSalesPrice)
 * 2 Parameter CTOR: Constructs a item object w/ name and price
 * Parameters:
 *	name:			Name of Items
 *	totalSalesPrice:Sales price of Item
 * Return:none
 ******************************************************************************/

/*******************************************************************************
 * Item(name, totalSalesPrice, quantityAvailable, quantitySold)
 * 4 Parameter CTOR: Constructs a item object w/ name, price, and quantity info
 * Parameters:
 *	name:				Name of Items
 *	totalSalesPrice:	Sales price of Item
 *	quantityAvailable:	Items available in stock
 *	quantitySold:		Items sold
 * Return:none
 ******************************************************************************/

