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

	//open file
	raw_file=fopen(filename,"r");

	//open output file
	strcat(filename,".sbl");
	enc_file=fopen(filename,"w+");

	//load file into ram
	file_in_ram=malloc(sizeof(*raw_file));
	fread(file_in_ram,1,sizeof(*raw_file),raw_file);
	printf("File is %lud\n",sizeof(*raw_file));

	//save encrypted file to disk
	fwrite(file_in_ram,1,sizeof(*raw_file),enc_file);

	//free ram taken by file and close files
	fclose(raw_file);
	fclose(enc_file);
	free(file_in_ram);
}
