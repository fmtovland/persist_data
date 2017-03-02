#include <stdio.h>
#define NUMNO 1000

int main()
{
	register int i;	//for loops
	int num1=0,num2=0;

	//file pointer
	FILE *num1000,*num1000copy;
	num1000= fopen("num1000.bin","r");
	num1000copy= fopen("num1000copy.bin","r");

	for(i=0; i<NUMNO; i++)
	{
		fread(&num1, 1, sizeof(int), num1000);
		fread(&num2, 1, sizeof(int), num1000copy);
		printf("%d %d \n",num1,num2);

	}//end for

}//end main
