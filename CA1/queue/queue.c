#include <stdio.h>
#include <stdlib.h>
#include "lminput.h"
#define NAMLEN 16	//for a name of max length 15 letters
#define TWEET 400	//number of characters in a tweet. should be enough for a short description

struct queue
{
	char name[NAMLEN];		//name of client
	long unsigned int contact_no;	//number client can be reached on
	char issue[TWEET];		//short description of issue.
	int time;			//time of phone call in seconds
	struct queue *next;		//pointer to next person in queue

};

int main()
{
	struct queue *in,*out;
	char input;

	do
	{
		printf("Press 1 to add to queue.\n Press 2 to pop from queue.\n Press 0. to exit program.\n");
		scanf("%c",&input);
		if(overflow() != 0)
		input='\0';

		switch(input)
		{
			case '0':
			{
				printf("Have a nice day!\n");
				break;
			}

			case '1':
			{
				//add to queue
				break;
			}

			case '2':
			{
				//pop from queue
				break;
			}

			default:
			{
				printf("Invalid input\n");
			}

		}//end switch

	}
	while(input != '0');

}//end main
