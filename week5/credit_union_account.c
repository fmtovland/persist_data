#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "credit_union_account.h"

int main()
{
	FILE *jane;
	jane=fopen("jane.ant","w+");
	struct credit_union_account *dit;
	dit=malloc(sizeof(struct credit_union_account));

	strcpy((*dit).first_name,"Jane");
	strcpy((*dit).surname,"Ferris");
	strcpy((*dit).contact_number,"01 402300");
	strcpy((*dit).address.number,"DIT");
	strcpy((*dit).address.street,"Kevin Street");
	strcpy((*dit).address.city,"Dublin");
	(*dit).dob.day=1;
	strcpy((*dit).dob.month,"jan");
	(*dit).dob.year=1999;
	strcpy((*dit).pps,"123456X");

	fwrite(&dit,1,sizeof(struct credit_union_account),jane);

	free(dit);
}
