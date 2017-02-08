#include <stdio.h>

int main()
{
	FILE *fp;	//create pointer that represents the file

	fp=fopen("prog1.c","r");	//assign file to pointer just like regular variable

	if(fp == NULL)
	{
	printf("\n\n ERROR: File is not found for opening \n\n");	//error checking
	}

	else
	{
		printf("\n\n File was sucessfully opened\n\n");	//more error checking
		fclose(fp);//release the file from memory
		printf("\n\n File was sucessfully closed\n\n");	//yet more error checking
	}
}
