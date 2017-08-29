#include<iostream>
using namespace std;
struct lnode
{
	int data;
	lnode *next;
};


//void create(lnode *L,int n)
//{
//	int i,k;
//	for(i=0;i<n;i++)
//	{
//		cout<<"enter the numbers\n";
//		cin>>k;
//		if(i==0)
//		{
//			addfront(L,k);
//		}
//		else
//		{
//			addend(L,k);
//		}
//		L->next=new lnode;
//	}
//}

void create(lnode *L)
{
	L=new lnode;
	int i,c=0,n;
	char ch='y';
//	cout<<"enter the no of nodes\n";
//	cin>>n;
	cout<<"enter the nos\n";
//	do
//	{
//	for(i=0;i<n;i++)
//	{
	while(ch!='n')
	{
		cin>>L->data;
		L=L->next;
		cout<<"want to enter more?(y/n)\n";
		cin>>ch;
	}
//	}
//	}while(c<n);
}
void print(lnode *L)
{
	while(L->next!=NULL)
	{
		cout<<L->next;
		L=L->next;
	}
}
void remdup(lnode *L)
{
	lnode *T,*H;
	int c=0;
	T=H=L;
	T=new lnode;
	while(L->next!=NULL)
	{
		T->data=L->data;
		T=T->next;
		L=L->next;
	}
	T->next=NULL;
	T=H;
	L=H;
	while(T->next!=NULL)
	{
		while(L->next!=NULL)
		{
			if(T->data==L->data)
			{
				c++;
			}
			if(c>1)
			{
				L->next=L->next->next;
				c--;	
			}
			L=L->next;
		}
		T=T->next;
	}
}
int main()
{
	lnode *L;
	create(L);
	remdup(L);
	return 0;
}
