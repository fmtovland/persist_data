/* requirements:
Write a program that uses fseek to set the 3rd and 10th number to 0 in
either of your random number files.
*/

#include <stdio.h>

int main()
{
	int num=0;
	//open file for reading and writing
	FILE *num1000;
	num1000=fopen("num1000.bin","a");

	//write to third number
	fseek(num1000, 3, SEEK_SET);
	fwrite(&num,sizeof(int),1,num1000);

	//write to tenth number
	fseek(num1000, 10, SEEK_SET);
	fwrite(&num,sizeof(int),1,num1000);

}//end main
