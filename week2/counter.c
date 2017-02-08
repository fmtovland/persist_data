#include <stdio.h>

int main()
{
	FILE *fp;
	int number_of_char=0;

//	printf("opening file \n");
	fp=fopen("num_let.txt","r");

	if(fp == NULL)
	{
		printf("\n\n ERROR: File is not found for opening \n\n");	//error checking
	}

	while(fp+number_of_char != NULL)
	{
		number_of_char++;
		printf("%c",(fp+number_of_char));
	}

	printf("File contains %d characters \n",number_of_char);

}//end main
