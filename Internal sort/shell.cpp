#include<iostream>
using namespace std;

int n;

void shellsort(int A[])
{
	int i,j,temp;
	for(i=5;i>=1;i-=2)
	{
		for(j=0;j<n;j++)
		{
			if((i+j)<n)
			{
				if(A[i+j]<A[j])
				{
					temp=A[j];
					A[j]=A[i+j];
					A[i+j]=temp;
				}
			}
			else
			{
				break;
			}
		}
	}
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
	shellsort(A);
	print(A);
	return 0;
}
