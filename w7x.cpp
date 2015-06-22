Script started on Fri 26 Jul 2013 04:19:05 PM EDT
hkim142@matrix:~/oop244/w7> exita.outcat PhoneNumber.cpp PhoneNumber.h IntlPhoneNumber.cppp IntlPhoneNumber.h[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[A[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[K
[K[A[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[Kwho am[K[K[Kami
hkim142
hkim142@matrix:~/oop244/w7> whoamiexit[Ka.outcat PhoneNumber.cpp PhoneNumber.h IntlPhoneNumber.cppp IntlPhoneNumber.h
/*Hyungi Kim 
025 741 125
OOP244
PhoneNumber.cpp*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
using namespace std;
#include"PhoneNumber.h"
PhoneNumber::PhoneNumber(){
	areacode=0;
	number=NULL;
}

PhoneNumber::PhoneNumber(int ac, const char *num){
	if( ac >0 && num !=NULL ){
		delete [] number;
		if(atoi(num)!=0){
		number = new char [ strlen(num)+1];
		areacode=ac;
		strcpy (number,num);
		}
	}
	else{
		*this=PhoneNumber();
	}
}

void PhoneNumber::display() const{
	if (areacode >0 && (number !='\0' || atoi(number) >0)){
		cout<<areacode<<"-";
		for(int i =0;i<8;i++){
			if(0<number[i]<8){
				if(i == 3){
				cout<<"-"<<number[i];
			}
				else if(number[i] == '\0'){
					i=10;
				}
				else{
			cout<<number[i];
				}
			}
			
		}
	}
}

bool PhoneNumber::valid() const{
	PhoneNumber temp;
	if(areacode >0 && (number !='\0' || atoi(number)>0) ){//check its right digit
			return true;
	}
	
return false;
}

void PhoneNumber::read(istream& is){
	number = new char [8];
	cout<<"Area code : ";
	is>>areacode;
	if(areacode >0){
	cout<<"Phone Number : " ;
	is.ignore(10,'\n');
	is.getline(number,8);
	}
	else{
		PhoneNumber();
	}

}

istream& operator >>(istream& is, PhoneNumber& a){
	a.read(is);
	return is;
}
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
hkim142@matrix:~/oop244/w7> cat PhoneNumber.cpp PhoneNumber.h IntlPhoneNumber.cppp IntlPhoneNumber.h[A[C[C[C[C[C[C[C[C[Cwhoami[K
[K[A[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[Cexit[Ka.out
Telephone List
==============
International Code : 1
Area code : 416
Phone Number : 5551212
International Code : 44
Area code : 131^H^H      41
Phone Number : 4441111
International Code : 49
Area code : 228
Phone Number : 6661234
International Code : 0

1-416-555-1212
44-141-444-1111
49-228-666-1234
hkim142@matrix:~/oop244/w7> exit
exit

Script done on Fri 26 Jul 2013 04:19:50 PM EDT
