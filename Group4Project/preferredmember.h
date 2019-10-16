#ifndef PREFERREDMEMBER_H
#define PREFERREDMEMBER_H

#include "member.h"
#include <string>
#include <iostream>

using namespace std;

class PreferredMember:public Member
{
public:
	/*******************
	* CONSTRUCTOR(S)
	********************/
	PreferredMember();

private:
    double rebateAmt;       //Rebate amount for member


};


#endif //PREFERREDMEMBER_H
