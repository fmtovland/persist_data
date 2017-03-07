#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *raw_file,*enc_file;
	char filename[51];
	int *file_in_ram;

	printf("Enter name of file to encrypt\n");
	scanf("%50s",filename);

	raw_file=fopen(filename,"r");

	enc_file=fopen(filname".sbl","w+");
	file_in_ram=malloc(sizeof(raw_file));

	free(file_in_ram);
}
