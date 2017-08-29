#include<iostream>
using namespace std;
struct hnode
{
	int *data;
};

int size=0,size1;

void heapify(hnode &H,int i,int d)
{
	int t;
	while(i>1)
	{
		if(H.data[(i+1)/d]>H.data[i])
		{
			t=H.data[i];
			H.data[i]=H.data[(i+1)/d];
			H.data[(i+1)/d]=t;
		}
		i/=d;
	}
	
}

void sort(hnode H,int l,int h)
{
	int i,j,t;
	for(i=l;i<h;i++)
	{
		for(j=i+1;j<=h;j++)
		{
			if(H.data[i]>H.data[j])
			{
				t=H.data[i];
				H.data[i]=H.data[j];
				H.data[j]=t;
			}
		}
	}
}

int create(hnode &H)
{
	int i,n,d;
	cout<<"how many elements you want to enter?\n";
	cin>>n;
	size=n;
	size1=size;
	cout<<"how many children of node?\n";
	cin>>d;
	H.data=new int[n];
	for(i=1;i<=n;i++)
	{
	cout<<"enter value\n";
	cin>>H.data[i];

	heapify(H,i,d);
//	if(i%d)
//	{
//		sort(H,i-(d-1),i);
//	}
	}
	return d;
}

void percolatedown(hnode &H,int d)
{
	int i=1,t;
	while(i<=size/d)
	{
		if(H.data[d*i]<H.data[d*i+1]&&H.data[d*i]<H.data[d*i-1])
		{
			t=H.data[d*i];
			H.data[d*i]=H.data[i];
			H.data[i]=t;
			i=d*i;
		}
		else	if(H.data[d*i+1]<H.data[d*i]&&H.data[d*i+1]<H.data[d*i-1])
		{
			{
				t=H.data[(d*i)+1];
				H.data[(d*i)+1]=H.data[i];
				H.data[i]=t;
				i=d*i;
			}
		}
		else
		{
				t=H.data[(d*i)-1];
				H.data[(d*i)-1]=H.data[i];
				H.data[i]=t;
				i=d*i;
		}
	}
}

int deheap(hnode &H,int i,int d)
{
	int t;
	t=H.data[i];
	H.data[i]=H.data[size];
	size--;
	percolatedown(H,d);
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

void del(hnode H,int k,int d)
{
	int i=search(H,k);
	if(i==-1)
	{
		cout<<"no not found\n";
		return;
	}
	else
	{
		deheap(H,1,d);
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

void heapsort(hnode H,int d)
{
	cout<<"the sorted order is:\n";
	while(size>=0)
	{
		cout<<deheap(H,1,d)<<" ";
	}
	
}

int main()
{
	int d;
	hnode H;
	d=create(H);
	print(H);
//	del(H,5);
	heapsort(H,d);
//	print(H);
	return 0;
}
