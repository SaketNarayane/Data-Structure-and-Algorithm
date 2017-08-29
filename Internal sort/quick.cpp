#include<iostream>
using namespace std;

int n;

void quicksort(int A[],int low,int high)
{
	int l,h,temp,p;
	l=low;
	h=high;
	p=A[l];
	while(l<=h)
	{
		if(A[l]>p)
		{
			l++;
		}
		else
		{
			if(A[h]<p)
			{
				h--;
			}
			else
			{
				temp=A[l];
				A[l]=A[h];
				A[h]=temp;
			}
		}
			A[low]=A[h];
	A[h]=p;
	}
	quicksort(A,low,h-1);
	quicksort(A,h+1,high);
}

void create(int A[])
{
	int i;
	for(i=0;i<n;i++)
	{
		cout<<"\nenter the numbers\n";
		cin>>A[i];
	}
}

void print(int A[])
{
	int i;
	for(i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
}

int main()
{
	cout<<"\nenter the number of elements\n";
	cin>>n;
	int A[n];
	create(A);
	quicksort(A,0,n-1);
	print(A);
	return 0;
}
