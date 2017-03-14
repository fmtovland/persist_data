void scramble(char *arrayname1, int size)
{
    //initialisation of variables
    char tmp;
    int i;

    //if array size is odd, decrement size
    if(size % 2 == 1)
    {
        size--;

    } //end if

    //for loop for swapping elements
    for(i=0; i<size; i=i+2)
    {
	if(*(arrayname1 + i) != 0 || *(arrayname1 + (i+1)) !=0)
	{
 	       //putting *(arrayname1 + i) into the variable tmp
 	       tmp = *(arrayname1 + i);

 	       //putting *(arrayname1 + (i+1)) into *(arrayname1 + i)
 	       *(arrayname1 + i) = *(arrayname1 + (i+1));

 	       //putting tmp into *(arrayname1 + (i+1))
 	       *(arrayname1 + (i+1)) = tmp;

	}//end if
//	printf("%d,%d\n",*(arrayname1 + i),*(arrayname1 + (i+1)));
    } //end for
} //end void
