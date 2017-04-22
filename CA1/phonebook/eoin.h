void alphabet_sort(struct contact pbook[],int size)
{
    int i, j;
    int done=0;		//end loop when done=0
    struct contact temp;

	do
	{
            done=0;
	    for(i = 0; i <=  size-2; i++)
	    {
	        for(j = 0; pbook[i].name[j] != '\0' && j<NAMLEN; j++)
	        {
	            if((pbook[i].name[j] > pbook[i+1].name[j] ))
	            {
	                temp = pbook[i];
	                pbook[i] = pbook[i+1];
	                pbook[i+1] = temp;
                        done=1;
	                break;
	            } //end if
	            else if((pbook[i].name[j] < pbook[i+1].name[j]))
	            {
	                break;
	            } //end else if
	        } //end for
	    } //end for
	    
	}//end do
	while(done != 0);

} //end alphabet_sort
