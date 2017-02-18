/*
Program Requirements:
Create a C program that asks the user the name of a text file (use gets() ), opens
that file1 and then asks the user to input a word.
The program will scan the file line by line and stop when it reads a line containing the
word entered by the user.
It will display an error message if the word is not in the file.

If the word is contained in the file, the program will shows:
a) The content of the line
b) The line number and the position of the word in the line.


Program Author: Liam McCormick
Date: 18-02-17
OS: Gentoo
Kernel: Linux 4.9.10
Compiler: GCC 5.4.0
*/

#include <stdio.h>
#define FILELENGTH 40	//maximum number of characters in the filename (scanf at //let user choose file to open)
#define WORDSIZE 13	//number of letters per word
#define LINESIZE 20	//max words per line

//prototypes
//void splice(char*,char[WORDSIZE][WORDNO]);

int main()
{
	//files
	FILE *subject;		//file to search for a word

	//variables
	register int i,j;			//for loops
	char hunting_ground[FILELENGTH];	//name of the file that can be searched
	char user_input[WORDSIZE];		//word to search the file for
	char line[WORDSIZE][LINESIZE];		//hold a line of text
	int line_number=0;			//line on which searched word is found
	int word_number=0;			//word of line on which searched word is found

	//let user choose file to open
	printf("Enter the name of the file\n");
	scanf("%39s",hunting_ground);
	subject=fopen(hunting_ground,"r");	//open file in readonly mode
	if(subject == NULL)	//check if file opened sucessfully
	{
		printf("ERROR: file not found\n");
		return -1;	//end program if file not found

	}//end if

	//ask the user what word to search for
	printf("What word are you looking for?\n");
	scanf("%s",user_input);

	//search through the file for the word and print line if found
	for(i=0; i<WORDSIZE; i++)
	{
		fscanf(subject,"%12s",line);
		for(j=0; j<LINESIZE; j++)
		{
			if(strcmp(line[j],user_input)==0)
			{
				printf("%s \n",line);
				return 0;

			}//end if

		}//end for

	}//end for


	//if word is not found print this error
	printf("ERROR: word not found\n");
	fclose(subject);
	return 1;

}//end main

/*
void splice(char line[WORDSIZE*WORDNO], char spliced[WORDSIZE][WORDNO])
{
	//variables
	register int i,j;

	for(i=0; i<WORDNO; i++)
	{
		j=0;
		while(*(line+(i*WORDSIZE)+j) != ' ' && j<WORDSIZE)	//until a space is encountered or 9 characters have been entered
		{
			spliced[i][j]=*(line+(i*WORDSIZE)+j);

		}//end while

	}//end for

}//end splice
*/
