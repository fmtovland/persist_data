#include <stdio.h>
#define BRICKS 150

int main()
{
	FILE *fp;
	char ch;
	int number=0;		//will count the number of characters in a file

//	printf("opening file \n");
	fp=fopen("num_let.txt","r");

	if(fp == NULL)
	{
		printf("\n\n ERROR: File is not found for opening \n\n");	//error checking
	}

//	printf("File opened \n");

	while((ch = fgetc( fp )) != EOF)
	{
	        number++;
	}

	printf("There are %d characters in the file \n",number);

	fclose(fp);			//lose access to the file

	return 0;

}//end main
