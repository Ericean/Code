#include<stdio.h>
#define MAX 1000
void merge(int a[], int lo, int mid, int hi)
{
	int aux[MAX];//auxiliary array
	//copy a to aux
	int k;
	for(k=lo;k<=hi;k++)
	{
	  aux[k]=a[k];
	}
	int i=lo,j=mid+1;//sublist pointers
	for(k=lo;k<=hi;k++)
	{	//endcases
		if(i>mid) 	  a[k]=aux[j++];
		else if(j>hi) a[k]=aux[i++];
		//main rountine
		else if(aux[i]>aux[j]) a[k]=aux[j++];
		else a[k]=aux[i++];
	}
	
}
void sort(int a[],int lo,int hi)
{
		if(lo>=hi) return;
		int mid=lo+(hi-lo)/2;
		sort(a,lo,mid);
		sort(a,mid+1,hi);
		merge(a,lo,mid,hi);
}
int main()
{

	int a[]={3,4,5,6,1,2,3};
	merge(a,0,3,6);
	int  k;
	for(k=0;k<7;k++)
		printf("%d ",a[k]);
	printf("\n");
return 0;
}