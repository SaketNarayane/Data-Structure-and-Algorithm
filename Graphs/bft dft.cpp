#include<iostream>
#include<queue>
using namespace std;
struct vertex
{
	int visited;
}**V;

struct lnode
{
	int data;
	lnode *next;
}**L;

queue<int>q;
int n;

void insert(lnode *&L,int k)
{
	if(L==NULL)
	{
		L=new lnode;
		L->data=k;
		L->next=NULL;
	}
	else
	{
		while(L!=NULL)
		{
			L=L->next;
		}
		L=new lnode;
		L->data=k;
		L->next=NULL;
	}
}

void create(lnode *&L)
{
	int k=0,i;
	while(k!=-99)
	{
		cout<<"enter the numbers\n";
		if(k==-99)
		{
			break;
		}
		else
		{
			cin>>k;
			insert(L,k);
		}
	}
}

void DFT(int a)
{
	if(L[a]!=NULL)
	{
		if(V[L[a]->data]->visited==0)
		{
			cout<<L[a]->data;
			V[L[a]->data]->visited=1;
			DFT(L[a]->data);
		}
	}
}

void BFT(int a)
{
	int x;
	q.push(a);
	V[a]->visited=1;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		if(V[x]->visited==0)
		{
			cout<<x;
		}
		while(L[x]!=NULL)
		{
			if(V[L[x]->data]->visited==0)
			{
				q.push(L[x]->data);
				V[L[x]->data]->visited=1;
			}
			L[x]=L[x]->next;
		}
	}
}

int main()
{
	int i,n,k;
	cout<<"enter no of vertices\n";
	cin>>n;
	lnode **L;
	vertex **V;
	L=new lnode*[n+1];
	V=new vertex*[n+1];
	for(i=1;i<=n;i++)
	{
		cout<<"for "<<i<<" list";
		L[i]=NULL;
		create(L[i]);
		V[i]->visited=0;
	}
	cout<<"enter initial vertex for traversal\n";
	cin>>k;
	cout<<" DFT is\n";
	DFT(k);
	cout<<" BFT is\n";
	BFT(k);
}
