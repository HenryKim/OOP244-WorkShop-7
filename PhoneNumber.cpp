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
