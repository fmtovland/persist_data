/*
Program requirements:
Create a C program that reads a text file line by line and create two text files: even_lines.txt
and odd_lines.txt. The program saves into the file even_lines.txt the content of all the odd
lines read (first line, third line, fifth line...) and it saves into even_line.txt the content of the
even lines (second, forth, sixth line....).

Author: Liam McCormick
Date: 10-02-17
OS: Gentoo
Kernel: Linux 4.9.9
Compiler: GCC 4.9.4
*/

#include <stdio.h>
#define FILENAME 15	//max number of letters in a filename
#define CHARPERLINE 75	//max number of characters per line in the input file
int main()
{
	register int counter;		//counter for loops
	FILE *file;			//pointer to the input file
	FILE *odd,*even;		//pointers to the output files
	char filename[FILENAME];	//recieve input for the filename
	char line[CHARPERLINE];		//string to hold 1 line of input at a time

	printf("Enter the name of the file \n");
	gets(filename);		//input filename

	file=fopen(filename,"r");		//open input file
	even=fopen("even_lines.txt","w+");	//open output file for even lines
	odd=fopen("odd_lines.txt","w+");	//open output file for odd lines

	if(file == NULL)
	{
		printf("Error, file not found \n");
		return 1;	//exit disgracefully if file not found

	}//end if

	if(odd == NULL || even == NULL)
	{
		printf("Error opening output files \n");
		return 1;       //exit disgracefully if the are issues with output files

	}//end if

	counter=0;

	while(fgets(line,CHARPERLINE,file) != NULL)
	{
		if(counter%2==1)
		{
			fputs(line,odd);

		}//end if

		else
		{
			fputs(line,even);

		}//end else

		counter++;

	}//end while

}//end main

