#include <stdio.h>

int main()
{
	int i,r;
	char filename[90];
	FILE *random_bin;
	printf("enter filename to read\n");
	scanf("%89s",filename);
	random_bin=fopen(filename,"r");

	for(i=0; i<1000; i++)
	{
		fread(&r,1,sizeof(int),random_bin);
		printf("%d\n",r);
	}//end for
}
