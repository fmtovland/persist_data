//Write a program that reads the file num1000.bin, but this time use an array and fread.

#include <stdio.h>
#define NUMNO 1000

int main()
{
	//File pointer
	FILE *num1000;

	//variables
	register int i;
	int numbers[NUMNO];	//hold the 1000 numbers

	//open file
	num1000 = fopen("num1000.bin","r");
	if(num1000 == NULL)
	{
		printf("read error\n");
		return 1;
	}//end if

	//copy data from file to array
	fread(numbers,sizeof(int),NUMNO,num1000);

	for(i=0; i<NUMNO; i++)
	{
		printf("%d \n",numbers[i]);

	}//end for

	return 0;

}//end main
