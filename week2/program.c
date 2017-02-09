#include <stdio.h>
#define BRICKS 150

int main()
{
	FILE *fp;
	char line[BRICKS];

//	printf("opening file \n");
	fp=fopen("num_let.txt","r");

	if(fp == NULL)
	{
		printf("\n\n ERROR: File is not found for opening \n\n");	//error checking
	}

//	printf("File opened \n");

	while(fgets(line,BRICKS,fp) != NULL)
	//while it is sucessfull reading
	{
		printf("%s",line);
	}//end while

	fclose(fp);			//lose access to the file

	return 0;

}//end main
