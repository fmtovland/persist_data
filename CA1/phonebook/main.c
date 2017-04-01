#include <stdio.h>
#include "format.h"
#include "lminput.h"
#define MAX 200	//maximum number of contacts that can be stored in the phonebook

//name of phonebook
const char filename[13]="phonebook.pb";

//prototypes
void addcon(struct contact*);			//add a contact
void delcon(struct contact*);			//delete a contact
void edcon(struct contact*);			//edit a contact
void searchcon(char*,struct contact*,int);	//search for a contact by name
void display(struct contact*,int);		//display entire phonebook
void dateprint(time_t);				//display the date

int main()
{
	FILE *book;
	struct contact phonebook[MAX];
	int size;	//the number of contacts currently included
	char input=0;
	int num;	//which number to edit
	char name[NAMLEN];

	//load phonebook into ram (12kb of ram required)
	book=fopen(filename,"rb");
	if(book==NULL)	//if file does not exist, write 5 sample contacts
	{
		write_sample(phonebook);
		size=5;
	}

	else
	{
		fread(phonebook,MAX,sizeof(struct contact),book);
		fread(&size,1,sizeof(int),book);
		fclose(book);

	}//end else

	while(input!='0')
	{
		printf("Enter a number to select an option from the menu:\n");
		printf("\n 1: Add new contact");
		printf("\n 2. Delete old contact");
		printf("\n 3. Edit contact");
		printf("\n 4. Find contact");
		printf("\n 5. Record contacts");
		printf("\n 6. Print entire phonebook");
		printf("\n 0. Exit");

		printf("\n");
		scanf("%c",&input);
		overflow();		//can be found on lminput.h
		printf("\n");

		switch(input)
		{

			case '0':
			{
				printf("Have a nice day\n");
				break;

			}//end case 0

			case '1':
			{
				if(size<MAX)
				{
					addcon(phonebook+size);
					//sort(phonebook);
					size++;
				}

				else
				printf("Phonebook full\n");

				break;
			}//end case 1

			case '3':
			{
				display(phonebook,size);
				printf("Enter the number of a contact, to edit that contact\n");
				scanf("%d",&num);
				overflow();

				if(num<size)
				edcon(phonebook+num);
				else
				printf("Error: contact not found\n");

				break;

			}//end case 3

			case '4':	//Find contact
			{
				printf("Enter name of contact to search for: ");
				wordget(name,NAMLEN);
				searchcon(name,phonebook,size);
				break;
			}

			case '5':	//save phonebook
			{
				printf("saving...\n");
				book=fopen(filename,"w+b");

				if(book==NULL)
				printf("Error creating file\n");

				else
				{
					fwrite(phonebook,MAX,sizeof(struct contact),book);
					fwrite(&size,1,sizeof(int),book);
					fclose(book);
					printf("saved sucessfully\n");

				}//end else

				break;

			}//end case

			case '6':
			{
				display(phonebook,size);
				break;

			}//end case 6

			default:
			{
				printf("Error, invalid input\n");

			}//end default

		}//end switch

	}//end while

}//end main

void addcon(struct contact *newcontact) 	//add a contact
{
	printf("Enter name of new contact: ");
	wordget((*newcontact).name,NAMLEN);

	printf("Enter their phone number: ");
	scanf("%lud",&(*newcontact).phone);
	overflow();

	printf("Enter their email address: ");
	wordget((*newcontact).email,MAILLEN);

	(*newcontact).date=time(0);	//see http://stackoverflow.com/questions/2242963/get-the-current-time-in-seconds

}//end addcon

void edcon(struct contact *con)
{
	char input;

	do
	{
		printf("\n");
		display(con,1);
		printf("Press 1 to change name\n");
		printf("Press 2 to change phonenumber\n");
		printf("Press 3 to change email address\n");
		printf("Press 0 to finish editing\n");
		scanf("%c",&input);
		overflow();

		switch(input)
		{
			case '1':
			{
				printf("Enter new name: ");
				wordget(con->name,NAMLEN);
				break;

			}//end case 1

			case '2':
			{
				printf("Enter new phonenumber: ");
				scanf("%lu",&con->phone);
				overflow();
				break;

			}//end case 2

			case '3':
			{
				printf("Enter new email: ");
				wordget(con->email,MAILLEN);
				break;

			}//end case 3

			case '0':
			{
				break;

			}

			default:
			{
				printf("What?\n");

			}//end default

		}//end switch
	}
	while(input != '0');

}//end edcon

void searchcon(char *search_term,struct contact *phonebook, int size)
{
	int j;
	int result=MAX;	//final result, number of elements verified correct
	char subject[NAMLEN];	//term to compare will be placed here, then prematurly be null terminated


	for(j=0; j<size; j++)
	{
		strcpy(subject,(phonebook+j)->name);
		*(subject+strlen(search_term)+1)='\0';	//in this case, a string called name
		printf("%s %s\n",subject,search_term);

		if( strcmp(subject,search_term)==0 )
		result=j;

	}//end for

	if(result!=MAX)
	{
		printf("Found ");
		display(phonebook+result,1);
	}//end if

	else
	printf("Contact not found\n");

}//end searchcon

void display(struct contact *phonebook,int size)
{
	int i;
	struct tm* date;

	for(i=0; i<size; i++)
	{
		printf("Contact %d\n",i);
		printf(" %s\n %lu\n %s\n",(phonebook+i)->name,(phonebook+i)->phone,(phonebook+i)->email);
		//dateprint((*(phonebook+i)).date);
		printf("\n");

	}//end for

}//end display


