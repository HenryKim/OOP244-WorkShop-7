/*Hyungi Kim 
025 741 125
OOP244
IntlPhoneNumber.h*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
using namespace std;
#include "PhoneNumber.h"
class IntlPhoneNumber: public PhoneNumber{
	int Intlcode;
public:
	IntlPhoneNumber();
	IntlPhoneNumber(int intl, int ac, char *num);
	void display() const;
	bool valid() const;
	void read(istream&);
};
istream& operator >>(istream&, IntlPhoneNumber&);
