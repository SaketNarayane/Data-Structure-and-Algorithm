#include<iostream>
using namespace std;
struct hnode
{
	int *data;
};

int size=0,size1;

void heapify(hnode &H,int i)
{
	int t;
	while(i>1)
	{
		if(H.data[i/2]<H.data[i])
		{
			t=H.data[i];
			H.data[i]=H.data[i/2];
			H.data[i/2]=t;
		}
		i/=2;
	}
	
}

void create(hnode &H)
{
	int i,n;
	cout<<"how many elements you want to enter?\n";
	cin>>n;
	size=n;
	size1=size;
	H.data=new int[n];
	for(i=1;i<=n;i++)
	{
	cout<<"enter value\n";
	cin>>H.data[i];
	heapify(H,i);
	}
}

void percolatedown(hnode &H)
{
	int i=1,t;
	while(i<=size/2)
	{
		if(H.data[2*i]>H.data[2*i+1])
		{
			t=H.data[2*i];
			H.data[2*i]=H.data[i];
			H.data[i]=t;
			i=2*i;
		}
		else
		{
			{
				t=H.data[(2*i)+1];
				H.data[(2*i)+1]=H.data[i];
				H.data[i]=t;
				i=(2*i)+1;
			}
		}
	}
}

int deheap(hnode &H,int i)
{
	int t;
	t=H.data[i];
	H.data[i]=H.data[size];
	size--;
	percolatedown(H);
	return t;
}
int search(hnode H,int k)
{
	for(int i=1;i<size1;i++)
	{
		if(H.data[i]==k)
			return i;
	}
	return -1;
}

void del(hnode H,int k)
{
	int i=search(H,k);
	if(i==-1)
	{
		cout<<"no not found\n";
		return;
	}
	else
	{
		deheap(H,i);
	}
}
void print(hnode H)
{
	int i;
	cout<<"\nthe heap is: \n";
	for(i=1;i<=size;i++)
	{
		cout<<H.data[i]<<" ";
	}
	
}

int main()
{
	hnode H;
	create(H);
	print(H);
	del(H,5);
	print(H);
	return 0;
}
