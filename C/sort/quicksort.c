#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void swap(int *a , int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int parti(int array[], int lo, int hi)
{
    int pivot = array[hi];
    int i = lo;
    int j;
    for (j = lo; j < hi; j++)
        if (array[j] < pivot)
        {
            swap(&array[j], &array[i]);
            i++;
        }
    swap(&array[hi], &array[i]);
    return i;
}

int partition(int array[], int l, int r)
{
    int pivot = array[r];
    int curpos = l;
    int j ;

    for ( j = l; j < r; j++)
    {
        if (array[j] < pivot)
        {
            swap(&array[j], &array[curpos]);
            curpos++;
        }
    }

    swap(&array[r], &array[curpos]);
    return curpos;


}

void quicksort(int array[], int l, int r)
{
    int interval;
    if (l >= r) return;
    // interval = partition(array,l,r);
    interval = parti(array, l, r);
    //printf("%d\n",interval);
    quicksort(array, l, interval - 1);
    quicksort(array, interval + 1, r);


}


void test_quicksort()
{
    int number = 12;
    int *array = malloc(number * sizeof(int));
    if (array == NULL)
    {
        printf("malloc failed\n");

    }
    int i;

    printf("----------------------------------------before quick sort--------------\n");
    srand(time(NULL));
    for (i = 0; i < number; i++)
    {
        array[i] = rand() % 1000;
        printf("\tarray[%d] = %d\n", i, array[i]);
    }

    printf("----------------------------------------after quick sort-----------------\n");

    quicksort(array, 0, number - 1);
    for (i = 0; i < number; i++)
    {
        printf("\tarray[%d] = %d\n", i, array[i]);
    }

}
int main()
{
    test_quicksort();
    return 0;
}