#include <stdio.h>
#include <string.h>

struct date
{
	short day;	// 1 => day => 31
	char month[4];	//can be jan, feb, mar...
	short year;	//eg 1999
};

struct postal_address
{
	char number[10];	//the house name or number
	char street[20];	//the street name
	char city[10];		//eg. dublin

};//end address

struct credit_union_account
{
	int pps;		//Personal Public Service number
	char first_name[15];	//firstname
	char surname[30];	//surname
	char contact_number[10];//phone number
	int id;			//account number
	int balance;		//account balance

	struct postal_address address;

	struct date dob;//end dob


};	//end struct

int main()
{
	struct credit_union_account dit;

	strcpy(dit.first_name,"Jane");
	strcpy(dit.surname,"Ferris");
	strcpy(dit.contact_number,"01 402300");
	strcpy(dit.address.number,"DIT");
	strcpy(dit.address.street,"Kevin Street");
	strcpy(dit.address.city,"Dublin");

}
