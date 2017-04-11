#include <stdio.h>
#include <stdlib.h>
#include "lminput.h"
#define NAMLEN 16	//for a name of max length 15 letters
#define TWEET 401	//number of characters in a tweet (plus null). should be enough for a short description

struct time	//for the time of the phonecall
{
	short hours;
	short mins;
	short secs;
};

struct queue
{
	char name[NAMLEN];		//name of client
	long unsigned int contact_no;	//number client can be reached on
	char issue[TWEET];		//short description of issue.
	struct time calllen;		//time of phone call in hours, minutes and seconds
	struct queue *next;		//pointer to next person in queue

};

int main()
{
	struct queue *in,*out,*last;
	char input;
	int q_size=0;
	int i;		//for loops

	do
	{
		printf("Press 1 to add to queue.\nPress 2 to pop from queue.\nPress 0. to exit program.\n");
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
				//allocate element of queue

				if(q_size == 5)		//prevent the queue being overfilled
				{
					printf("Queue is full\n");
					break;
				}

				else if(q_size == 0)
					in=out=malloc(sizeof(struct queue));
				else
				{
					in->next=malloc(sizeof(struct queue));
					in=in->next;
				}

				q_size++;

				//enter information
				printf("Enter name of customer: ");
				wordget(in->name,NAMLEN);

				printf("Enter their contact number: ");
				scanf("%lu",&in->contact_no);
				overflow();

				printf("Enter a short description of the issue: (max %d characters)\n",TWEET-1);
				wordget(in->issue,TWEET);

				printf("enter the time of the phonecall in form hh:mm:ss\n");
				//input time
				for(i=0; i<3; i++)
				{
					scanf("%hd",&in->calllen.hours+i);
					scanf("%*c");
				}

				break;
			}

			case '2':
			{
				//pop from queue
				if(q_size == 0)		//check you can pop from the queue
				{
					printf("Queue is empty\n");
					break;
				}//end if

				//remove from queue
				last=out;
				out=out->next;

				//print information
				printf("name: %s\n",last->name);			//print name
				printf("contact number: %lu\n",last->contact_no);	//print contact number
				printf("issue: %s\n",last->issue);			//print issue

				//print time of call
				printf("Time of call: ");
				for(i=0; i<3; i++)
				{
					printf("%hd",in->calllen.hours+i);

					if(i%3 != 2)
						printf(":");
					else
						printf("\n");
				}

				printf("\n");

				free(last);
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
