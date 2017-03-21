struct phonebook
{
	char name[15];			//firstname and surname
	unsigned long int phone;	//phone number: always print to 8 digits
	char email[40];			//email address
	unsigned long int date;		//int the form "DDMMYYhhmmss" with no seperators
					//DD is day, MM month (01 january, 02 february etc.) YY is year (99 would be 1999, 05 would be 2005), hh would be an hour between 0 and 23, mm and ss are minutes and seconds, each between 0 and 59

};

static struct phonebook[5] sample	//a sample phonebook with 5 contacts
//1
	phonebook[0].name="John Smith";
	phonebook[0].phone=01234567;
	phonebook[0].email="john.smith@jomail.com";
	phonebook[0].date=010199000015;
//2
	phonebook[1].name="John Doe";
	phonebook[1].phone=01234568;
	phonebook[1].email="john.doe@jomail.com";
	phonebook[1].date=010198120007;
//3
	phonebook[2].name="Jane Smith";
	phonebook[2].phone=01234569;
	phonebook[2].email="jane.smith@jomail.com";
	phonebook[2].date=220312134212;
//4
	phonebook[3].name="Jane Doe";
	phonebook[3].phone=01234570;
	phonebook[3].email="jane.doe@jomail.com";
	phonebook[3].date=121212121212;

//5
	phonebook[4].name="Eugine Crabs"
	phonebook[4].phone=99124322;
	phonebook[4].email="orders@thecrustycrab.com"
	phonebook[4].date=170799160222;

