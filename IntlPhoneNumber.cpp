/*Hyungi Kim 
025 741 125
OOP244
IntlPhoneNumber.cpp*/
#include "IntlPhoneNumber.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
using namespace std;
IntlPhoneNumber::IntlPhoneNumber():PhoneNumber(){
	Intlcode=0;
}

IntlPhoneNumber::IntlPhoneNumber(int intl,int ac, char* num):PhoneNumber(ac,num){
	if( intl <0 && ac <0 && (num !=NULL || atoi(num)>0)){
		Intlcode=intl;
	}
	else{
		*this=IntlPhoneNumber();
	}
}

void IntlPhoneNumber::display() const{
	if( Intlcode>0){
		cout<<Intlcode<<"-";
		PhoneNumber::display();
	}
}

bool IntlPhoneNumber::valid() const{
	bool flag;
	if(Intlcode >0 ){//check its right digit
		bool flag = PhoneNumber::valid();
		if(flag == true){
			return true;
		}
	}
	
return false;
}

void IntlPhoneNumber::read(istream& is){
	cout<<"International Code : ";
	is>>Intlcode;
	if(Intlcode>0){
	PhoneNumber::read(is);
	}
}

istream& operator >>(istream& is, IntlPhoneNumber& a){
	a.read(is);
	return is;
}
