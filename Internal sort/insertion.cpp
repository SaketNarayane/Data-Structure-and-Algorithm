#include<iostream>
using namespace std;

int n;

void insertionsort(int A[],int k,int l)
{
	int i,j;
	for(i=0;i<l;i++)
	{
		if(A[i]>k)
		{
			for(j=l;j>i;j--)
			{
				A[j]=A[j-1];
			}
			A[j]=k;
		}
	}
}

void create(int A[])
{
	int i,k;
	for(i=0;i<n;i++)
	{
		cout<<"\nenter number\n";
		if(i==0)
		{
			cin>>A[0];
		}
		else
		{
			cin>>k;
			insertionsort(A,k,i);
		}
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
	print(A);
	return 0;
}
