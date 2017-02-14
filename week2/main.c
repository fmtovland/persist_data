/*
Program Description: Program that counts the number of digits in a text file
Author(s): Eoin Lynch
Date:: 14/02/2017
OS Version(s): Windows 10 (64 bit)
*/

#include <stdio.h>

int main()
{
    // initialisation of variables
	FILE *fp;
	char ch;
	int num_digits = 0;
	int num_char = 0;
	float digits_percent = 0;

    // fopen command to open file "num_let"
	fp = fopen("num_let.txt","r");

    // error checking
	if(fp == NULL)
	{
		printf("\n\n ERROR: File is not found for opening \n\n");
	}  // end if

    // counting of digits
	while((ch = fgetc( fp )) != EOF)
	{
            num_char++;

            if(ch > '0' && ch < '9')
            {
                num_digits++;
            } // end if
	} // end while

	// calculation of percent of digits in text file total
	digits_percent = num_digits / num_char;

    if(digits_percent > .2)
    {
        printf("There are too many digits in this file \n");
    } // end if
    else
    {
        printf("There is a valid amount of digits in this file \n");
    } // end else

    printf("There are %d characters in the file \n", num_char);
	printf("There are %d digits in the file \n",num_digits);

    // close access to file
	fclose(fp);

	return 0;

}// end main
