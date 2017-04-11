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

