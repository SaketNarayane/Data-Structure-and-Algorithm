#include<iostream>
using namespace std;

struct avlnode
{
	avlnode *lchild;
	int data;
	int ht;
	avlnode *rchild;
};

avlnode *X;

void inorder(avlnode *T)
{
	if(T!=NULL)
	{
		inorder(T->lchild);
		cout<<T->data<<" ";
		inorder(T->rchild);
	}
}

int height(avlnode *&T)
{
	if(T==NULL)
	{
		return -1;
	}
	else
	{
		return (1+max(height(T->lchild),height(T->rchild)));
	}
}

void rotateleft(avlnode *&T)
{
	cout<<"\n*in rotateleft*\n";
	avlnode *temp;
//	temp=T->rchild;
//	if(temp->lchild==NULL)
//	{
//		temp->lchild=T;
//		T->rchild=NULL;
//	}
//	else
//	{
		T->rchild=temp->lchild;
		temp->lchild=T;
//	}
	T=temp;
}

void rotateright(avlnode *&T)
{
	avlnode *temp;
	temp=T->lchild;
//	if(temp->rchild==NULL)
//	{
//		temp->rchild=T;
//		T->lchild=NULL;
//	}
//	else
//	{
		T->lchild=temp->rchild;
		temp->rchild=T;
//	}
	T=temp;
}

void doublerotateleft(avlnode *&T)
{
	rotateleft(T);
	rotateright(T);
}

void doublerotateright(avlnode *&T)
{
	rotateright(T);
	rotateleft(T);
}


void bal(avlnode *&T)
{
	
	cout<<"\n*in bal*\n";
	avlnode *K2,*K3,*K1;
	K1=T;
	if(height(K1->lchild)>height(K1->rchild))
	{
		K3=K1->lchild;
	}
	else
	{
		K3=K1->rchild;
	}
	if(height(K3->lchild)>height(K3->rchild))
	{
		K2=K3->lchild;
	}
	else
	{
		K2=K3->rchild;
	}
//	cout<<"*\nk1->data k2->data k3->data values are*\n";
//	cout<<K1->data<<endl;
//	cout<<K3->data<<endl;
//	cout<<K2->data<<endl;
	if(K2->data<K3->data&&K2->data>K1->data)
	{
		rotateright(K3);
		rotateleft(K1);
	}
	else	if(K2->data>K3->data&&K2->data<K1->data)
	{
		rotateleft(K3);
		rotateright(K1);
	}
	else	if(K2->data>K3->data&&K2->data>K1->data)
	{
		rotateleft(K1);
	}
	else	if(K2->data<K3->data&&K2->data<K1->data)
	{
		rotateright(K1);
	}
}

void chkbal(avlnode *&T)
{
	cout<<"\n*in chkbal*\n";
	if(T!=NULL)
	{
		int d;
		chkbal(T->lchild);
		d=height(T->lchild)-height(T->rchild);
		cout<<"\ndifference of height of children "<<d<<endl;
		if(d>1||d<-1)
		{
			bal(T);
		}
		chkbal(T->rchild);
	}

	cout<<"\n*checked*\n";
}

void insert(avlnode *&T,int k)
{
//	T=head;
	if(T==NULL)
	{
		T=new avlnode;
		T->data=k;
//		T->ht=height(T);
//		chkbal(X);
		T->lchild=NULL;
		T->rchild=NULL;

	}
	else
	{
		if(k<T->data)
		{
//			X=T;
			insert(T->lchild,k);
		}
		else
		{
//			X=T;
			insert(T->rchild,k);
		}
	}
}



int min(avlnode *t)
{
	if(t->lchild==NULL)
		return t->data;
	else
		min(t->lchild);
}

void del(avlnode *&T,int k)
{
	int t;
	avlnode *temp;
	if(T!=NULL)
	{
	if(T->data==k)
	{
		if(T->lchild==NULL)
		{
			if(T->rchild==NULL)
			{
				T=NULL;
			}
			else
			{
				T=T->rchild; 
			}
		}
		else
		{
			if(T->rchild==NULL)
			{
				T=T->lchild;
			}
			else
			{
				t=min(T->rchild);
				T->data=t;
				temp=T;
				del(T->rchild,t);
//				chkbal(T);
//								temp=T;
//				T=T->rchild;
//				while(T->lchild!=NULL)
//				{
//					T=T->lchild;
//				}
//			T->lchild=temp->lchild;
//			temp2=
//			while(T->rchild!=NULL)
//			{
//				T=T->rchild;
//			}
//			T->rchild=temp->rchild;
			}
		}
	}
	else
	{
		if(k<T->data)
		{
//			X=T;
			del(T->lchild,k);
		}
		else
		{
//			X=T;
			del(T->rchild,k);
		}
	}
	}
	else
	{
		cout<<"\nthe number to b deleted aint in d tree\n";
	}
}


int main()
{
	avlnode *T=NULL;
	int n,i,k;
	char ch;
	cout<<"how many nodes you want to enter?\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter node\n";
		cin>>k;
		if(k>=0)
		{
			insert(T,k);
			cout<<"\n*inserted*\n";
			chkbal(T);
			cout<<"\n inorder \n";
			inorder(T);
		}
		else
			break;
	}
	cout<<"do you want to delete a node?\n";
	cin>>ch;
	if(ch=='y')
	{
		cin>>k;
		del(T,k);
		chkbal(T);
		cout<<"\n inorder \n";
		inorder(T);
	}
	return 0;
}
