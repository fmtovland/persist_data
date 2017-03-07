#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *raw_file,*enc_file;
	char filename[51];
	int *file_in_ram;

	//set file to scrambele to first argument
	if(argv[1] != NULL)
	strcpy(filename,argv[1]);

	//ask user to enter filename if none provided
	else
	{
		printf("Enter name of file to encrypt\n");
		scanf("%50s",filename);
	}

	raw_file=fopen(filename,"r");

	strcat(filename,".sbl");

	enc_file=fopen(filename,"w+");
	file_in_ram=malloc(sizeof(raw_file));

	free(file_in_ram);
}
