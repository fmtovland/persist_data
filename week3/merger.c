/*
Program Requirements:
Create a C program that asks to the user the names of two text files and then it
creates another text file called merged.txt that contains the two files one after the
other.

Author: Liam McCormick
Date: 15-02-17
OS: Gentoo
Kernel: 4.9.9
Compiler: GCC 4.9.4
*/

#include <stdio.h>
#define NUMNO 25	//max number of characters per filename

int main()
{
	char filename1[NUMNO],filename2[NUMNO];		//strings to hold filenames
	FILE *file1,*file2;				//pointers to hold the files
	FILE *output;					//pointer to output file

	printf("Enter a filename\n");		//ask user to input filenames
	gets(filename1);
	printf("Enter another filename\n");
	gets(filename2);

	file1=fopen(filename1,"r");		//open input and output files for writing
	file2=fopen(filename2,"r");
	output=fopen("merged.txt","w+");

	if(file1 == NULL || file2 == NULL || output == NULL)
	{
		printf("Input Output Error! \n");

	}//end if


}//end main
