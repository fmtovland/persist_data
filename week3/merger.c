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
	char file1[NUMNO],file2[NUMNO];		//strings to hold filenames

	printf("Enter a filename\n");		//ask user to input filenames
	gets(file1);
	printf("Enter another filename\n");
	gets(file2);

}//end main
