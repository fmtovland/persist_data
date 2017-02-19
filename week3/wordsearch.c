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
#define WORDSIZE 15	//number of characters in the word to search for (scanf at //ask the user what word to search for)
#define LINESIZE 100	//maximum characters per line

int main()
{
	//files
	FILE *subject;		//file to search for a word

	//variables
	register int i,j;			//for loops
	char hunting_ground[FILELENGTH];	//name of the file that can be searched
	char user_input[WORDSIZE];		//word to search the file for
	char line[LINESIZE];			//hold a line of text
	char word[WORDSIZE];			//hold a word to compare to user_input
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
	scanf("%14s",user_input);

	//search through the file for the word and print line if found
	line_number=0;
	while(fgets(line,LINESIZE-1,subject) != NULL)
//	while(fscanf(subject,"%[^\n]s",line) != EOF)
	{
		line_number++;
		word_number=0;
		i=0;
		while(i<LINESIZE)
		{
			j=0;
			word_number++;
			while(line[i] != ' ' && j<WORDSIZE)
			{
				word[j]=line[i];
				i++;
				j++;

			}//end while

			i++;

			if(strcmp(word,user_input) == 0)
			{
				printf("Word found at line %d word %d \n",line_number,word_number);
				return 0;

			}//end if

		}//end while

	}//end while

	//if word is not found print this error
	printf("ERROR: word not found\n");
	fclose(subject);
	return 1;

}//end main
