#include<iostream>
using namespace std;
class list
{
struct lnode
{
	int data;
	lnode *next;
}*L;
public:
	void addafter(lnode*,int,int);
	void addbefore(lnode*,int,int);
	void addend(lnode*,int);
	void addfront(lnode*,int);
	void print(lnode*);
	void create(lnode*);
};
void list::addafter(lnode *L,int x,int k)
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

void list::addbefore(lnode *L,int x,int k)
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

lnode *L,*H;
void list::addend(lnode *L,int k)
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

void list::addfront(lnode *L,int k)
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

void list::create(lnode *L)
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
void list::print(lnode *L)
{
	while(L->next!=NULL)
	{
		cout<<L->next;
		L=L->next;
	}
}

int main()
{
	list s;
//	lnode *L,*H;
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
			s.addafter(L,x,k);
			L=H;
			s.print(L);
			L=H;
			break;
		}
		case 2:
		{
			cout<<"you want to add which no before what?\n";
			cin>>k>>x;
			s.addbefore(L,x,k);
			print(L);
			break;
		}
		case 3:
		{
			cout<<"what u want to add in front?\n";
			cin>>k;
			s.addfront(L,k);
			s.print(L);
			break;	
		}
		case 4:
		{
			cout<<"what u want to add at last?\n";
			cin>>k;
			s.addend(L,k);
			s.print(L);
			break;
		}
	}
	return 0;
}
