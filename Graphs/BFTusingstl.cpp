#include<iostream>
#include<list>
#include<queue>
const int t=10;
using namespace std;
struct vertex
{
	int visited=0;
};

int n;
queue<int>q;
list<int>L[t];
list<int>::iterator it;

void insert(int i)
{
	int k=0;
	while(k!=-99)
		{
			cout<<"\nenter the numbers for"<<i<<endl;
			cin>>k;
			if(k!=-99)
			{
				L[i].push_back(k);
			}
		}
}

void display(vertex V[])
{
	int i;
	for(i=1;i<=n;i++)
	{
		cout<<" for "<<i<<" "<<V[i].visited;
	}
}
void create()
{
	int i;
	for(i=1;i<=n;i++)
	{
		insert(i);
	}
}

void displayL()
{
	int i;
	for(i=1;i<=n;i++)
	{
		cout<<i<<" -> ";
		for(it=L[i].begin();it!=L[i].end();++it)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}	
}

int z;

void DFT(vertex V[],int a)
{
	if(V[a].visited==0)
	{
		cout<<a;
		z++;
		
		V[a].visited=1;
		if(z==n)
		{
			return;
		}
//		cout<<endl;
//		display(V);
	}
	for(it=L[a].begin();it!=L[a].end();++it)
	{
		if(z==n)
		{
			return;
		}
		if(V[*it].visited==0)
		{
			DFT(V,*it);
		}
//		display(V);
	}
}

void BFT(vertex V[],int a)
{
	int x;
	q.push(a);
	V[a].visited=-1;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		if(V[x].visited==-1)
		{
			cout<<x;
			V[a].visited=1;
		}
		for(it=L[x].begin(); it != L[x].end(); ++it) 
		{
//			printV(V);
			if(V[*it].visited==0)
			{
				q.push(*it);
				V[*it].visited=-1;
			}
		}
	}
}

void initiateV(vertex V[])
{
	int i;
	for(i=1;i<=n;i++)
	{
		V[i].visited=0;
	}
}


int main()
{
	int k,f=1;
	vertex *V;
	V=new vertex[n+1];
	cout<<"\n how many vertices?\n";
	cin>>n;
	create();
	displayL();
//	while(f)
//	{
//		
//	cout<<"enter initial vertex for traversal\n";
//	cin>>k;
//	initiateV(V);
//
//	z=0;
//	cout<<" DFT is\n";
//	DFT(V,k);
//	cout<<"do you want to traverse from different point?\n(1/0)";
//	cin>>f;
//	}
	initiateV(V);
	cout<<"enter initial vertex for traversal\n";
	cin>>k;
	cout<<" BFT is\n";
	BFT(V,k);

	return 0;
}

