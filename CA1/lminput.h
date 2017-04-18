//prototypes
int overflow();
int wordget(char*,int);

//make sure too many characters were not entered (good for scanfs)
int overflow()
{
	char a='\0';	//hold a character to check if input is done
	register int i=-1;

	do	//suck input to the ether until a newline is detected
	{
		scanf("%c",&a);
		i++;

	}//end while
	while(a != '\n');

	return i;

}//end overflow

//Input a string of length defineable by #defines or variables
int wordget(char *output, int length)
{
	length=length-1;	//auto account for the null character
	register int i=0;
	char buffer=0;

	while(i<length)
	{
		scanf("%c",&buffer);	//scan character into buffer
		if(buffer!='\n')	//if not at end of input
		*(output+i)=buffer;	//put buffer into next slot of output
		else
		break;	//end before i = length if a \n is detected

		i++;
	}

	*(output+i)='\0';	//null termiate

	i=0;
	if(buffer!='\n')
	i=overflow();	//move all overflow to the ether

	return i;	//return the number of characters over the limit I am

}//end wordget
