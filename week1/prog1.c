#include <stdio.h>

int main()
{
	FILE *fp;	//create pointer that represents the file

	fp=fopen("prog1.c","r");	//assign file to pointer just like regular variable
	fclose(fp);			//release the file from memory
}
