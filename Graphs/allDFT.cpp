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
list<int>::iterator it[t];

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
		for(it[i]=L[i].begin();it[i]!=L[i].end();++it[i])
		{
			cout<<*it[i]<<" ";
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
	for(it[a]=L[a].begin();it[a]!=L[a].end();++it[a])
	{
		if(z==n)
		{
			return;
		}
		if(V[*it[a]].visited==0)
		{
			DFT(V,*it[a]);
		}
//		display(V);
		else
		{
			if(L[a].back()==*it[a])
			{
				return;
			}
		}
	}
	return;
}
//
//void BFT(vertex V[],int a)
//{
//	int x;
//	q.push(a);
//	V[a].visited=1;
//	while(!q.empty())
//	{
//		x=q.front();
//		q.pop();
//		if(V[x].visited==0)
//		{
//			cout<<x;
//		}
//		while(L[x]!=NULL)
//		{
//			printV(V);
//			if(V[L[x]->data].visited==0)
//			{
//				q.push(L[x]->data);
//				V[L[x]->data].visited=1;
//			}
//			L[x]=L[x]->next;
//		}
//	}
//}

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
	f=1;
	while(f<=n)
	{
		
//	cout<<"enter initial vertex for traversal\n";
//	cin>>k;
	initiateV(V);
//	display(V);
	z=0;
	cout<<" DFT is\n";
	DFT(V,f);
	cout<<endl;
	f++;
	}
//	initiateV(V);

//	cout<<" BFT is\n";
//	BFT(V,k);

	return 0;
}

