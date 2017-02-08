#include <stdio.h>

int main()
{
	FILE *fp;		//pointer to memory address of file. can be used like a regular variable, only it is persistant.

	char filename[20];	//declares variable to hold file name to open

	printf("\n\nPlease enter the file name you wish to open:  ");
	gets(filename);	//recieve user input. the compiler complains about this

	fp=fopen(filename,"r");	//define memory address on disk for pointer

	if(fp == NULL)
	{
	printf("\n\n ERROR: File is not found for opening \n\n");	//error checking
	}

	else
	{
		printf("\n\n File was sucessfully opened\n\n");		//^^^^^^^^^^^^^
		fclose(fp);	//release file
		printf("\n\n File was sucessfully closed\n\n");		//^^^^^^^^^^^^^
	}
}
