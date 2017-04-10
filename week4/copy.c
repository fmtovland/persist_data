//Write a program that reads the file num1000.bin, but this time use an array and fread.

#include <stdio.h>
#define NUMNO 1000

int main()
{
	//File pointer
	FILE *num1000;
	FILE *copy;

	//variables
	register int i;
	int numbers[NUMNO];	//hold the 1000 numbers

	//open files
	num1000 = fopen("num1000.bin","r+");
	copy = fopen("num1000copy.bin","w+");

	if(num1000 == NULL)
	{
		printf("read error\n");
		return 1;
	}//end if

	//copy data from file to array
	fread(numbers,sizeof(int),NUMNO,num1000);

	//copy data from array to new file
	fwrite(numbers,sizeof(int),NUMNO,copy);

	return 0;

}//end main
