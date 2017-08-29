#include<iostream>
using namespace std;

struct btnode
{
	btnode *lchild;
	int data;
	btnode *rchild;
};

void insert(btnode *&T)
{
	int o,k;
	if(T!=NULL)
	{
	if(T->lchild==NULL&&T->rchild==NULL)
	{
		cout<<"do you want to enter lchild of "<<T->data<<" ?  (1/0)";
		cin>>o;
		if(o)
		{

			insert(T->lchild);
		}
		cout<<"do you want to enter rchild of "<<T->data<<" ?  (1/0)";
		cin>>o;
		if(o)
		{
			insert(T->rchild);
		}
	}	
	}
	
	else
	{
		T=new btnode;
		cout<<"enter the value\n";
		cin>>k;
		T->data=k;
		T->lchild=NULL;
		T->rchild=NULL;
	}

}

void create(btnode *&T)
{
	int n,k;
	cout<<"enter the no of nodes you want\n";
	cin>>n;
	cout<<"enter the root value\n";
	cin>>k;
	T=new btnode;
	T->data=k;
	T->lchild=NULL;
	T->rchild=NULL;
	for(int i=1;i<n;i++)
	{
		insert(T);
	}	
}

void inorder(btnode *T)
{
	inorder(T->lchild);
	cout<<T->data;
	inorder(T->rchild);
}

int main()
{
	btnode *T=NULL;
	create(T);
	insert(T);
	inorder(T);
	return 0;
}
