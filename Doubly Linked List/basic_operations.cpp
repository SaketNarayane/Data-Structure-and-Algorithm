#include<iostream>
using namespace std;

struct dnode
{
	int data;
	dnode *right;
	dnode *left;
};

dnode *H;

void addend(dnode *D,int k)
{
	
	D=H;
	if(H==NULL)
	{
		cout<<"u";
		D=new dnode;
		D->left=NULL;
		D->right=NULL;
		D->data=k;
		H=D;
	}
	else
	{
		cout<<"y";
		while(D->right!=NULL)
		{
			D=D->right;
		}
		dnode *T;
		T=new dnode;
		T->data=k;
		D->right=T;
		T->right=NULL;
		T->left=D;
//		cout<<"D->data is"<<D->data;
	}
}

void addafter(dnode *D,int x,int k)
{
	D=H;
	while(D->data!=x)
	{
		D=D->right;
	}
		dnode *T;
		T=new dnode;
		T->data=k;
		T->right=D->right;
		T->left=D;
		D->right->left=T;
		D->right=T;

}

void dlete(dnode *D,int k)
{
	D=H;
	while(D->data!=k)
	{
		D=D->right;
	}
	if(D->right!=NULL)
	{
		D->left->right=D->right;
		D->right->left=D->left;
	}
	else
	{
		D->left->right=NULL;
		D->left=NULL;
	}
}

void addbefore(dnode *D,int x,int k)
{
	D=H;
//	if(D->data==x)
	while(D->data!=x)
	{
		D=D->right;
	}
	dnode *T;
	T=new dnode;
	T->data=k;
	T->right=D;
	T->left=D->left;
	D->left->right=T;
	D->left=T;
}

void print(dnode *D)
{
	D=H;
	cout<<"the nos are :"<<endl;
	while(D!=NULL)
	{
		cout<<D->data<<" ";
		
		D=D->right;
	}
}

void create(dnode *D)
{
	D=H;
	int n,i,k;
	cout<<"enter number of nodes\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter no\n";
		cin>>k;
		addend(D,k);
	}
}

void choose(dnode *D)
{
	int ch,k,x;
	cout<<"what operation you want to perform?\n";
	cout<<"1.addend\n2.addafter\n3.addbefore\n4.delete\n5.print\n";
	cin>>ch;
	switch(ch)
	{
		case 1:{
			cout<<"enter the no to b added ";
			cin>>k;
			addend(D,k);
			print(D);
			break;
		}
		case 2:{
			cout<<"enter the no to b added ";
			cin>>k;
			cout<<"after what? ";
			cin>>x;
			addafter(D,x,k);
			print(D);
			break;
		}
		case 3:{
			cout<<"enter the no to b added ";
			cin>>k;
			cout<<"before what? ";
			cin>>x;
			addbefore(D,x,k);
			print(D);
			break;
		}
		case 4:{
			cout<<"which no you want to delete? ";
			cin>>k;
			dlete(D,k);
			print(D);
			break;
		}
		case 5:{
			print(D);
			break;
		}
	}
}

int main()
{
	dnode *D;
	create(D);
	choose(D);
	return 0;
}
