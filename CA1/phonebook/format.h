struct contact
{
	char name[15];			//firstname and surname
	unsigned long int phone;	//phone number: always print to 8 digits
	char email[40];			//email address
	unsigned long int date;		//int the form "DDMMYYhhmmss" with no seperators
					//DD is day, MM month (01 january, 02 february etc.) YY is year (99 would be 1999, 05 would be 2005), hh would be an hour between 0 and 23, mm and ss are minutes and seconds, each between 0 and 59

};

/*
const struct contact sample[5]	//a sample contact with 5 contacts
//1
	sample[0].name="John Smith";
	sample[0].phone=01234567;
	sample[0].email="john.smith@jomail.com";
	sample[0].date=010199000015;
//2
	sample[1].name="John Doe";
	sample[1].phone=01234568;
	sample[1].email="john.doe@jomail.com";
	sample[1].date=010198120007;
//3
	sample[2].name="Jane Smith";
	sample[2].phone=01234569;
	sample[2].email="jane.smith@jomail.com";
	sample[2].date=220312134212;
//4
	sample[3].name="Jane Doe";
	sample[3].phone=01234570;
	sample[3].email="jane.doe@jomail.com";
	sample[3].date=121212121212;

//5
	sample[4].name="Eugine Crabs"
	sample[4].phone=99124322;
	sample[4].email="orders@thecrustycrab.com"
	sample[4].date=170799160222;
*/
