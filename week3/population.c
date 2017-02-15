/*
Program Requirements:
Download the file population.txt from webcourses/content.
The file is a formatted text file with 3 columns: country, city and population.
Read the file using fscanf() and create a short C program to do the following:

a) Display on the screen the sum of all the population of all the cities.
b) Display the name and the population of the city with the highest population.
c) Create a file with all the name of the cities in Ireland.

Author: Liam McCormick
Date: 15-02-17
OS: Gentoo
Kernel: 4.9.9
Compiler: 4.9.4
*/

#include <stdio.h>
#define NOPOPS 15	//the maximum number of populations there can be (with some breathing room)

//prototypes
int highest(int*,int);		//function to find highest number in an array

int main()
{
	FILE *population;		//pointer to population data
	long int residents[NOPOPS];	//array of popultion data (number of residents only)

	population=fopen("populations.txt","r");

	if(population == NULL)
	{
		printf("Input Output Error \n");

	}//end if

	fscanf(population,"%*s %*s %ld",residents);

	printf("%ld",residents[6]);

}//end main
