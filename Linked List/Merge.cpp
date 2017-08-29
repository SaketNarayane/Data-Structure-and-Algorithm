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
	lnode *L1,*L2,*L3,*H;
	H=L1=L2=L3;
	L1=new lnode;
	L2=new lnode;
	int c,x,k;
//	cout<<"enter no of nodes u want to enter";
//	cin>>n;
	create(L1);
	L1=H;
	
	create(L2);
	L2=H;

	merge(L3,L1,L2);
	cout<<"the merged list is\n";
	print(L3);
	return 0;
}
