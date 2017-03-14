void scramble(int *arrayname1, int size)
{
    //initialisation of variables
    int i, tmp;

    //if array size is odd, decrement size
    if(size % 2 == 1)
    {
        size --;
    } //end if

    //for loop for swapping elements
    for(i=0; i<size; i=i+2)
    {
        //putting *(arrayname1 + i) into the variable tmp
        tmp = *(arrayname1 + i);

        //putting *(arrayname1 + (i+1)) into *(arrayname1 + i)
        *(arrayname1 + i) = *(arrayname1 + (i+1));

        //putting tmp into *(arrayname1 + (i+1))
        *(arrayname1 + (i+1)) = tmp;
    } //end for
} //end void
