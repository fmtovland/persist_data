#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "eoin.h"

int main(int argc, char *argv[])
{
	FILE *raw_file,*dec_file;
	char filename[51];
	char *wissbl;	//pointer to sbl in the filename
	int *file_in_ram;
	int filesize;	//the size of the file
	int i;

	//set file to scrambele to first argument
	if(argv[1] != NULL)
	strcpy(filename,argv[1]);

	//ask user to enter filename if none provided
	else
	{
		printf("Enter name of file to decrypt\n");
		scanf("%50s",filename);
	}

	//open input file
	raw_file=fopen(filename,"r");
	if(raw_file==NULL)
	{
		printf("Error opening input file\n");
		return 1;
	}

	//open output file
	wissbl=strstr(filename, ".sbl");
	if(wissbl==NULL)
	{
		printf("Not a scrambled file\n");
		return 2;	//program exits
	}

	for(i=0; i<4; i++);
	*(filename+i-1)='\0';
	dec_file=fopen(filename,"w+");

	//verify opening output file was sucessful
	if(dec_file==NULL)
	{
		printf("Error opening output file\n");
		return 3;
	}

	//find filesize
	fseek(raw_file, 0, SEEK_END);
	filesize=ftell(raw_file);
	rewind(raw_file);

	//load file into ram
	file_in_ram=malloc(filesize);
	fread(file_in_ram,1,filesize,raw_file);

	//perform encryption algorithm on file
//	unscramble(file_in_ram);	//or whatever eion calls it

	//save encrypted file to disk
	fwrite(file_in_ram,1,filesize,dec_file);

	//free ram taken by file and close files
	fclose(raw_file);
	fclose(dec_file);
	free(file_in_ram);
}
