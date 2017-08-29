#include<iostream>
#include<queue>
using namespace std;
struct vertex
{
	int visited;
};
//vertex *V;

struct lnode
{
	int data;
	lnode *next;
};
//lnode **L;

queue<int>q;
int n;
lnode X[15];
void printV(vertex V[]);



void insert(lnode L[],int k)
{
	static int i=1;
	lnode *temp;
	if(L==NULL)
	{
		L=new lnode;
		X[i]=L;
		i++;
		L->data=k;
		L->next=NULL;
	}
	else
	{
		while(L!=NULL)
		{
			L=L->next;
		}
		temp=new lnode;
		temp->data=k;
		temp->next=NULL;
		L=temp;
	}
}

void create(lnode L[])
{
	int k=0,i;
	while(k!=-99)
	{
		cout<<"enter the numbers\n";
		cin>>k;
		
		if(k!=-99)
		{
			insert(L,k);
		}
		else
		{

			break;
		}
	}
}

void DFT(lnode L[],vertex V[],int a)
{
	if(V[a].visited==0)
	{
		cout<<a;
		V[a].visited=1;
	}
	while(L!=NULL)
	{
		if(V[L[a]->data].visited==0)
		{

			DFT(L,V,L[a]->data);
		}
	}
}

void BFT(lnode L[],vertex V[],int a)
{
	int x;
	q.push(a);
	V[a].visited=1;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		if(V[x].visited==0)
		{
			cout<<x;
		}
		while(L[x]!=NULL)
		{
			printV(V);
			if(V[L[x]->data].visited==0)
			{
				q.push(L[x]->data);
				V[L[x]->data].visited=1;
			}
			L[x]=L[x]->next;
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

void printL(lnode L[])
{
	int i;
	lnode *temp;
	cout<<"\n in printL\n";
	for(i=1;i<=n;i++)
	{
		L[i]=X[i];
		temp=L[i];
		cout<<i<<" ";
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
}

void printV(vertex V[])
{
	int i;
	cout<<"\n in visited\n";
	for(i=1;i<=n;i++)
	{
		cout<<"\nvalue of ";
		cout<<i<<" -> "<<V[i].visited;
	}
}

int main()
{
	int i,k;
	cout<<"enter no of vertices\n";
	cin>>n;
	lnode *L;
	vertex *V;
	L=new lnode[n+1];
	V=new vertex[n+1];
	for(i=1;i<=n;i++)
	{
		cout<<"for "<<i<<" list";
		L[i]=NULL;
		create(L);
//		V[i].visited=0;
	}
	printL(L);
	return 0;
	initiateV(V);
	printV(V);
	cout<<"enter initial vertex for traversal\n";
	cin>>k;
	cout<<" BFT is\n";
	BFT(L,V,k);
	initiateV(V);
	cout<<" DFT is\n";
	DFT(L,V,k);

	return 0;
}
