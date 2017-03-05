#include <stdio.h>
#include "credit_union_account.h"

int main()
{
	FILE *jane;
	fopen("jane.ant","r");

	struct credit_union_account dit;
	fread(&dit,1,sizeof(dit),jane);
	fclose(jane);

	printf("%s %s,\n %s,\n %s, %s\n %s,\n %s,\n %d/%s/%d\n",dit.first_name,dit.surname,dit.contact_number,dit.address.number,dit.address.street,dit.address.city,dit.pps,dit.dob.day,dit.dob.month,dit.dob.year);

}//end main
