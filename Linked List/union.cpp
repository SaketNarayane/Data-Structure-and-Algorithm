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


void merge(lnode *L1,lnode *L2,lnode*L3)
{
	L3=new lnode;
	int a,b;
	while(L1->next!=NULL&&L2->next!=NULL)
	{

		if((L1->data)>(L2->data))
		{
			L3->data=L1->data;
			L1=L1->next;
			L3=L3->next;
		}
		else
		{
			L3->data=L2->data;
			L2=L2->next;
			L3=L3->next;
		}
	}
	if(L1->next==NULL)
	{
		while(L2->next!=NULL)
		{
			L3->data=L2->data;
			L3=L3->next;
			L2=L2->next;
		}
	}
	
	if(L2->next==NULL)
	{
		while(L1->next!=NULL)
		{
			L3->data=L1->data;
			L3=L3->next;
			L1=L1->next;
		}
	}
	L3->next=NULL;
}

int main()
{
	lnode *L1,*L2,*L3,*H1,*H2,*H3;
	create(L1);
	remdup(L1);
	create(L2);
	remdup(L2);

	H3=L3;

	merge(L1,L2,L3);
	L3=H3;
	remdup(L3);
	print(L3);
	return 0;
}
