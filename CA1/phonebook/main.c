#include <stdio.h>
#include "format.h"
#include "lminput.h"
#define MAX 200	//maximum number of contacts that can be stored in the phonebook

//prototypes
void addcon(struct contact*);		//add a contact
void delcon(struct contact*);		//delete a contact
void edcon(struct contact*);		//edit a contact
void searchcon(struct contact*);	//search for a contact by name

int main()
{
	struct contact phonebook[MAX];
	char input=0;

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

			default:
			{
				printf("Error, invalid input\n");

			}//end default

		}//end switch

	}//end while

}//end main
