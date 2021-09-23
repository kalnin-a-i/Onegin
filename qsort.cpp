//---------------------------------------------------------------------------
/** @file */
//! Sorts an array of pointers
//! @param[in] v an array of pointers
//! @param[in] left left bound of sorting site
//! @param[in] rigtht rigth bound of sorting site
//! @param[in] comp function pointer comparator
//----------------------------------------------------------------------------

void qSort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int i, int j);
    if (left >= right) /* ничего не делать, если в массиве */
        return; /* меньше двух элементов */
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i<= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qSort(v, left, last-1, comp);
    qSort(v, last+1, right, comp);
}

//--------------------------------------------------------------
//! Swaps 2 elemts if pointers array
//! @param[in] v array of pointers
//! @param[in] i index of 1 element to swap
//! @paramp[in] j index of 2 element to swap
//-------------------------------------------------------------

void swap (void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j] ;
    v[j] = temp;
}