#include <string.h>
#include <time.h>
#define NAMLEN 15
#define MAILLEN 40

struct contact
{
	char name[NAMLEN];		//firstname and surname
	unsigned long int phone;	//phone number: always print to 8 digits
	char email[MAILLEN];		//email address
	time_t date;			//see http://stackoverflow.com/questions/2242963/get-the-current-time-in-seconds
};


void write_sample(struct contact *sample)	//a sample contact with 5 contacts
{
//1
	strcpy((*(sample+0)).name,"John Smith");
	(*(sample+0)).phone=1234567;
	strcpy((*(sample+0)).email,"john.smith@jomail.com");
	(*(sample+0)).date=915148815;
//2
	strcpy((*(sample+1)).name,"John Doe");
	(*(sample+1)).phone=1234568;
	strcpy((*(sample+1)).email,"john.doe@jomail.com");
	(*(sample+1)).date=883656007;
//3
	strcpy((*(sample+2)).name,"Jane Smith");
	(*(sample+2)).phone=1234569;
	strcpy((*(sample+2)).email,"jane.smith@jomail.com");
	(*(sample+2)).date=1332417607;
//4
	strcpy((*(sample+3)).name,"Jane Doe");
	(*(sample+3)).phone=1234570;
	strcpy((*(sample+3)).email,"jane.doe@jomail.com");
	(*(sample+3)).date=1355314332;

//5
	strcpy((*(sample+4)).name,"Eugine Crabs");
	(*(sample+4)).phone=99124322;
	strcpy((*(sample+4)).email,"orders@thecrustycrab.com");
	(*(sample+4)).date=932227342;
}
