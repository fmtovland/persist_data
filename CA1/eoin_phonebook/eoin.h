void alphabet_sort
{
    int i, j;

    for(i = 0; i <=  9; ++i)
    {
        for(j = 0; contact[i].name[k] != '\0'; j++)
        {
            if((contact[i].name[j] > contact[i+1].name[j] ))
            {
                temp[i] = contact[i];
                contact[i] = contact[i+1];
                contact[i+1] = temp[i];
                break;
            } //end if
            else if((contact[i].name[j] < contact[i+1].name[j]))
            {
                break;
            } //end else if
        } //end for
    } //end for
} //end alphabet_sort
