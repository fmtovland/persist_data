#include <stdio.h>

int main()
{
	int i,r;
	FILE *random_bin;
	random_bin=fopen("random.bin","r");

	for(i=0; i<1000; i++)
	{
		fread(&r,1,sizeof(int),random_bin);
		printf("%d\n",r);
	}//end for
}
