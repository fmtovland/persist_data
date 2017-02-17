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
long int sum(long int*);		//return the sum off all data in the array
int biggest(long int*);			//function to find highest number in an array

int main()
{
	register int i;			//for loops
	FILE *population;		//pointer to population data
	long int residents[NOPOPS];	//array of popultion data (number of residents only)
	long int total;			//the total population of all the cities combined
	int highest;			//will hold the line number of the city with the largest population
	char bigtown[21];		//string to hold largest city
	int bigtownpop;			//population of largest city

	population=fopen("populations.txt","r");

	if(population == NULL)
	{
		printf("Input Output Error \n");

	}//end if

	for(i=0; i<NOPOPS; i++)		//put population data into residents
	{
		fscanf(population,"%*s %*s %ld",residents+i);
//		printf("%d\n",*(residents+i));

	}//end for

	fclose(population);

	total=sum(residents);
	highest=biggest(residents);

	printf("The total population of all these cities is %ld \n",total);

	population=fopen("populations.txt","r");

	if(population == NULL)
	{
		printf("Input Output Error \n");

	}//end if


	for(i=0; i<highest; i++)
	{
		fscanf(population,"%*s %20s %d",bigtown,&bigtownpop);

	}//end for

	fclose(population);

	printf("%s has the highest population at %d people \n",bigtown,bigtownpop);

}//end main

long int sum(long int *populations)
{
	register int i;
	long int total=0;		//the value to be returned

	for(i=0; i<NOPOPS; i++)
	{
		total = total + *(populations+i);

	}//end for

	return total;

}//end total

int biggest(long int *populations)
{
	register int i;
	int highscore=0;	//the town with the largest population sofar
	int largest;		//town with largest population

	for(i=0; i<NOPOPS; i++)
	{
		if( *(populations+i) > highscore)
		{
			largest=i+1;
			highscore= *(populations+i);

		}//end if

	}//end for

	return largest;

}//end biggest
