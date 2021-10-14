#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


int partition(int arr[],int p,int r )
{
	int piv,i,j,a,b;
	piv=arr[r];
	i=p-1;
	for(j=p;j<=r-1;j++)
	{
		if(arr[j]<=piv)
		{
			i++;
			swap(arr[i],arr[j]);

		}
	}
	swap(arr[i+1],arr[r]);
return(i+1);
}

void merge(int arr[],int p,int q,int r)
{
	int n1,n2,i,j,k,R[10],L[10];
	n1=q-p+1;
	n2=r-q;
	for(i=1;i<=n1;i++)
	{
		L[i]=arr[p+i-1];
	}
	for(j=1;j<=n2;j++)
	{
		R[j]=arr[j+q];
	}
	L[n1+1]=1000000;
	R[n2+1]=1000000;
	i=1;j=1;
	for(k=p;k<=r;k++)
{
	if(L[i]<=R[j])
	{
		arr[k]=L[i];
		i++;
	}
	else{
		arr[k]=R[j];
		j++;
	}
}
}


void merge_sort(int arr[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		merge_sort(arr,p,q);
		merge_sort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}


void quick_sort(int arr[],int p,int r)
{
	int q;
	if(p<r)
	{
	   q=partition(arr,p,r);
	   quick_sort(arr,p,q-1);
		quick_sort(arr,q+1,r);
	}
}



int main()
{
	int n,i,j,r,arr[20],p;
	printf("enter no of numbers u want in array:");
	scanf("%d",&r);
	for(i=1;i<=r;i++)
	{
		scanf("%d",&arr[i]);
	}
	p=1;
	printf("sorting by mergesort");
	merge_sort(arr,p,r);
	for(i=1;i<=r;i++)
	printf("%d ",arr[i]);
	printf("\n");
	printf("sorting by quicksort");
		quick_sort(arr,p,r);
	for(i=1;i<=r;i++)
	printf("%d ",arr[i]);
return 0;
}
