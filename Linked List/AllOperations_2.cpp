#include<iostream>
using namespace std;
struct lnode
{
	int data;
	lnode *next;
};

void addafter(lnode *L,int x,int k)
{
	lnode *T;
	while(L->data!=x)
	{
		L=L->next;
	}
	T=new lnode;
	T->data=k;
	T->next=L->next;
	L->next=T;
}

void addbefore(lnode *L,int x,int k)
{
	lnode *T;
	T=new lnode;
	while(L->data!=x)
	{
		if(L->next->data==x)
		{
			T->data=x;
			T->next=L->next;
			L->next=T;
			break;
		}
		else
		{
			L=L->next;
		}
	}
}

void addend(lnode *L,int k)
{
	lnode *T;
	T=new lnode;
	while(L->next!=NULL)
	{
		L=L->next;
	}
		T->data=k;
		T->next=NULL;
		L->next=T;
}

void addfront(lnode *L,int k)
{
	lnode *T;
	T=new lnode;
	T->data=k;
	T->next=L;
	L=T;
}

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

int main()
{
	lnode *L,*H;
	H=L;
	L=new lnode;
	int c,x,k;
//	cout<<"enter no of nodes u want to enter";
//	cin>>n;
	create(L);
	L=H;
	cout<<"enter choice\n1.addafter\n2.addbefore\n3.addfront\n4.addend\n";
	cin>>c;
	switch(c)
	{
		case 1: 
		{
			cout<<"you want to add which no after what?\n";
			cin>>k>>x;
			addafter(L,x,k);
			L=H;
			print(L);
			L=H;
			break;
		}
		case 2:
		{
			cout<<"you want to add which no before what?\n";
			cin>>k>>x;
			addbefore(L,x,k);
			print(L);
			break;
		}
		case 3:
		{
			cout<<"what u want to add in front?\n";
			cin>>k;
			addfront(L,k);
			print(L);
			break;	
		}
		case 4:
		{
			cout<<"what u want to add at last?\n";
			cin>>k;
			addend(L,k);
			print(L);
			break;
		}
	}
	return 0;
}
