#include <iostream>
#include "../container.h"
#include <cstdlib>

using namespace std;

void fill(Container<int>& cont);

int main()
{
    Container<int> someNums;
    
    fill(someNums);
    someNums.display();
    
    cout << "SOME NUMS!!\n" << someNums << endl;
    cout << endl;
    someNums.select_sort();
    cout << someNums << endl;
    
    return EXIT_SUCCESS;
}

void fill(Container<int>& cont)
{
    for(int i = 0; i < 30; i++)
        cont.push_back(rand()%30);
}
