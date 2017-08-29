#include<iostream>
using namespace std;
struct lnode
{
	int data;
	lnode *next;
};

/*void addend(lnode *&L,int k)
{
	if(L==NULL)
	{
		L=new lnode;
		L->data=k;
		L->next=NULL;
	}
	else
	{
		lnode *temp=L,*temp1;
		while(L->next!=NULL)
			L=L->next;
		temp1 =new lnode;
		temp1 -> data=k;
		temp1 -> next=NULL;
		L->next=temp1;
		L=temp;
	}
}*/

void addend(lnode *&L, int k){
	if(L == NULL)
	{
		L = new lnode;
		L->data = k;
		L->next = NULL;
	}
	else
	addend(L->next,k);
}


void create(lnode *&L)
{
	int n,i,k;
	cout<<"enter the number of elements\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter the number\n";
		cin>>k;
		addend(L,k);
	}
}

void print(lnode *L)
{
	
	cout<<"elements in linked list are\n";
	while(L!=NULL)
	{
		cout<<L->data<<" ";
		L=L->next;
	}
}

struct twnode
{
	int flag;
	twnode *low;
	int datal;
	twnode *mid;
	int datah;
	twnode *high;
};

void insert(twnode *&T,int k)
{
	int t;
	if(T==NULL)
	{

		T=new twnode;
		T->low=NULL;
		T->mid=NULL;
		T->high=NULL;
		if(T->flag!=1)
		{
			T->datal=k;
			T->flag=1;
		}
		
	}	
	else
	{
		if(T->flag==1)
		{
			if(k>(T->datal))
			{
					T->datah=k;
				T->flag=2;
			}
			else
			{
				t=T->datal;
				T->datal=k;
				T->datah=t;
				T->flag=2;
			}
		}
		else
		{
			if(T->flag==2)
			{
				if(k<T->datal)
				{
					insert(T->low,k);
				}
				else	if(k>T->datah)
				{
					insert(T->high,k);
				}
				else	if((k>T->datal)&&(k<T->datah))
				{
					insert(T->mid,k);
				}
			}
		}
	}
}

void createtw(twnode *&T,lnode *&L)
{
	while(L!=NULL)
	{
		insert(T,L->data);
		L=L->next;
	}
}

void printtw(twnode *T)
{
	if(T!=NULL)
	{
		printtw(T->low);
		cout<<T->datal<<" ";
		printtw(T->mid);
		if(T->flag==2)
			cout<<T->datah<<" ";
		printtw(T->high);
	}
}

int main()
{
	lnode *L=NULL;
	twnode *T=NULL;
	create(L);
	print(L);
	createtw(T,L);
	cout<<"the tree is:\n";
	printtw(T);
	return 0;
}
