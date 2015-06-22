/*Hyungi Kim 
025 741 125
OOP244
PhoneNumber.h*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
using namespace std;
class PhoneNumber{
	int areacode;
	char *number;
public:
	PhoneNumber();
	PhoneNumber(int ac, const char *num);
	void display() const;
	bool valid() const;
	void read(istream&);

};
istream& operator >>(istream&, PhoneNumber&);
