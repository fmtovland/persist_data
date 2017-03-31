#include <stdio.h>
#include "format.h"
#include "lminput.h"
#define MAX 200	//maximum number of contacts that can be stored in the phonebook

//name of phonebook
const char filename[13]="phonebook.pb";

//prototypes
void addcon(struct contact*);		//add a contact
void delcon(struct contact*);		//delete a contact
void edcon(struct contact*);		//edit a contact
void searchcon(struct contact*);	//search for a contact by name

int main()
{
	FILE *book;
	struct contact phonebook[MAX];
	int size;	//the number of contacts currently included
	char input=0;

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
					size++;
				}

				else
				printf("Phonebook full\n");

				break;
			}//end case 1

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
}
