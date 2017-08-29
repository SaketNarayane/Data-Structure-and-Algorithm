#include<iostream>
using namespace std;
struct lnode
{
	int coeff;
	int expo;
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

//void create(lnode *L)
//{
//	int i,c=0,n;
//	char ch='y';
////	cout<<"enter the no of nodes\n";
////	cin>>n;
//	cout<<"enter the nos\n";
////	do
////	{
////	for(i=0;i<n;i++)
////	{
//	while(ch!='n')
//	{
//		cin>>L->data;
//		L=L->next;
//		cout<<"want to enter more?(y/n)\n";
//		cin>>ch;
//	}
////	}
////	}while(c<n);
//}
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
	lnode *L1,*L2,*L3;
	L1=new lnode;
	char ch='y';
	cout<<"enter coefficient and exponential of terms of first polynomial in decreasing order of exponential\n";
	while(ch=='y')
	{
		cout<<"coefficient\n";
		cin>>L1->coeff;
		cout<<"expo\n";
		cin>>L1->expo;
		L1=L1->next;
		cout<<"want to add more?\n";
		cin>>ch;
	}
	L1->next=NULL;
	
	L2=new lnode;
	cout<<"enter coefficient and exponential of terms of second polynomial in decreasing order of exponential\n";
	while(ch=='y')
	{
		cout<<"coefficient\n";
		cin>>L2->coeff;
		cout<<"expo\n";
		cin>>L2->expo;
		L2=L2->next;
		cout<<"want to add more?\n";
		cin>>ch;
	}
	L2->next=NULL;
	
	L3=new lnode;
	while(L1->next!=NULL&&L2->next!=NULL)
	{
	if(L1->expo>L2->expo)
	{
		L3->coeff=L1->coeff;
		L3->expo=L1->expo;
		L1=L1->next;
		L3=L3->next;
	}
	else	if(L1->expo<L2->expo)
	{
		L3->coeff=L2->coeff;
		L3->expo=L2->expo;
		L2=L2->next;
		L3=L3->next;
	}
	else
	{
		L3->coeff=L2->coeff+L1->coeff;
		L3->expo=L2->expo;
		L1=L1->next;
		L2=L2->next;
		L3=L3->next;
	}
	}
	if(L1->next==NULL)
	{
		while(L2!=NULL)
		{
			L3->coeff=L2->coeff;
			L3->expo=L2->expo;
			L2=L2->next;
			L3=L3->next;
		}
	}
	else	if(L2->next==NULL)
	{
		while(L1!=NULL)
		{
			L3->coeff=L1->coeff;
			L3->expo=L1->expo;
			L1=L1->next;
			L3=L3->next;
		}
	}
	L3->next=NULL;
	return 0;
}
