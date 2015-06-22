/*Hyungi Kim 
025 741 125
OOP244
IntlPhoneNumberWS.cpp*/
#include"IntlPhoneNumberWS.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
using namespace std;


IntlPhoneNumberWS::IntlPhoneNumberWS():IntlPhoneNumber(){
	name=NULL;
}

IntlPhoneNumberWS::IntlPhoneNumberWS(int intl,int ac, char* num, char* nam):IntlPhoneNumber(intl,ac,num){
	if( intl >0 && ac >0 && (num !=NULL || atoi(num)>0) && nam != NULL){
		if(name != NULL){
			delete [] name;
		}
		name = new char [ strlen(nam) +1 ];
	}
	else{
		*this=IntlPhoneNumberWS();
	}
}

void IntlPhoneNumberWS::display() const{
	if(name!=NULL){
		IntlPhoneNumber::display();
		cout <<" "<<name;
	}
}

bool IntlPhoneNumberWS::valid() const{
	bool flag;
	if(name != NULL ){
		bool flag = IntlPhoneNumber::valid();
		if(flag == true){
			return true;
		}
	}
	
return false;
}

void IntlPhoneNumberWS::read(istream& is){
	name = new char [40];
	IntlPhoneNumber::read(is);
	if( IntlPhoneNumber::valid() == true){
	cout<<"Subscriber :";
	cin.getline(name,40);
	}
}

istream& operator >>(istream& is, IntlPhoneNumberWS& a){
	a.read(is);
	return is;
}