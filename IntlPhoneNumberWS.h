/*Hyungi Kim 
025 741 125
OOP244
IntlPhoneNumber.h*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
using namespace std;
#include"IntlPhoneNumber.h"
class IntlPhoneNumberWS:public IntlPhoneNumber{
	char *name;
public:
	IntlPhoneNumberWS();
	IntlPhoneNumberWS(int intl, int ac, char *num, char *nam);
	void display() const;
	bool valid() const;
	void read(istream&);
};
istream& operator >>(istream&, IntlPhoneNumberWS&);