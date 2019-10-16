#ifndef SALES_H
#define SALES_H
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
class Sales
{
public:
    Sales(string temp);
       ifstream reader;
       ofstream writer;
       void process();
       void sort(int& profit);
       void reset();

   private:
      string date;
      string file;
      string member;
      string item_name;
      string item_price;
      string item_quantity;
      int sz;
      string arr[40];
};


#endif //SALES_H
