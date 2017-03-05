#include <stdio.h>
#include <string.h>

int main()
{
	struct credit_union_account dit;

	strcpy(dit.first_name,"Jane");
	strcpy(dit.surname,"Ferris");
	strcpy(dit.contact_number,"01 402300");
	strcpy(dit.address.number,"DIT");
	strcpy(dit.address.street,"Kevin Street");
	strcpy(dit.address.city,"Dublin");
	dit.dob.day=1;
	strcpy(dit.dob.month,"jan");
	dit.dob.year=1999;

}
