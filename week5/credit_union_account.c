#include <stdio.h>

struct credit_union_account
{
	char address[50];
	short Date_of_birth[3];	//a small array to hold date of birth in the form dd-mm-yy
	int pps;		//Personal Public Service number
	char first_name[15];	//firstname
	char surname[30];	//surname
	int contact_number;	//phone number
	int id;			//account number
	int balance=0;		//account balance

};	//end struct


