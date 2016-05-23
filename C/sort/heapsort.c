#include<stdio.h>
#include<stdlib.h>
static inline void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//maintain a big-heap
static inline void sift_down(int numbers[], int root, int bottom)
{
	int  maxChild;
	//@root :adjust entrance
	//@bottom: adjust exit
	while ((root * 2+1 <= bottom))
	{
		//find the maxChild
		//if only one child
		if (root * 2 +1== bottom) maxChild = root * 2+1;
		//two children
		else if (numbers[root * 2+1] > numbers[root * 2 + 2])maxChild = root * 2+1;
		else  maxChild = root * 2 + 2;
		//check
		printf("......%d\n", numbers[maxChild]);
		if (numbers[root] >= numbers[maxChild])break;
		swap(&numbers[root], &numbers[maxChild]);
		root = maxChild;

	}
}
static inline void build_heap(int a[], int len)
{
	int i;
	for (i = len / 2-1; i >= 0; i--)
		sift_down(a, i, len);

}
static inline void  heap_sort(int a[], int len)
{
	int k;
	for(k=len-1;k>=0;k--)
	{
		swap(&a[0],&a[k]);
		sift_down(a,0,k-1);
	}
}
int main()
{
	int a[] = {2,989, 384847, 93483, 324, 2344, 232423,-23, 423};
	build_heap(a,9);
	heap_sort(a,9);
	int k;
	for (k = 0; k < 9; k++)printf("%d ", a[k]);
	return 0;
}