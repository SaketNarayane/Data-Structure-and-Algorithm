#include<iostream>
using namespace std;

struct tnode
{
	tnode *lchild;
	char dat;
	int data;
	tnode *rchild;
};

tnode *X,*Z;

void inorder(tnode *T)
{
	if(T!=NULL)
	{
		inorder(T->lchild);
		cout<<T->dat<<" "<<T->data<<" ";
		inorder(T->rchild);
	}
}

void preorder(tnode *T)
{
	if(T!=NULL)
	{	
		cout<<T->dat<<" "<<T->data<<" ";
		preorder(T->lchild);
		preorder(T->rchild);
	}
}
//
//int height(tnode *&T)
//{
//	if(T==NULL)
//	{
//		return -1;
//	}
//	else
//	{
//		return (1+max(height(T->lchild),height(T->rchild)));
//	}
//}

void rotateleft(tnode *&T)
{
	cout<<"\n*in rotateleft*\n";
	tnode *temp;
	temp=T->rchild;
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
	cout<<" before "<<T->data<<endl;
	T=temp;
	cout<<" after "<<T->data<<endl;
}

void rotateright(tnode *&T)
{
	cout<<"\n*in rotateright*\n";
	tnode *temp;
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
	cout<<" before "<<T->data<<endl;
	T=temp;
	cout<<" after "<<T->data<<endl;
}

void doublerotateleft(tnode *&T)
{
	rotateleft(T);
	rotateright(T);
}

void doublerotateright(tnode *&T)
{
	rotateright(T);
	rotateleft(T);
}


//void bal(tnode *&T)
//{
//	
//	cout<<"\n*in bal*\n";
//	tnode *K2,*K3,*K1;
//	K1=T;
//	if(height(K1->lchild)>height(K1->rchild))
//	{
//		K3=K1->lchild;
//	}
//	else
//	{
//		K3=K1->rchild;
//	}
//	if(height(K3->lchild)>height(K3->rchild))
//	{
//		K2=K3->lchild;
//	}
//	else
//	{
//		K2=K3->rchild;
//	}
////	cout<<"*\nk1->data k2->data k3->data values are*\n";
////	cout<<K1->data<<endl;
////	cout<<K3->data<<endl;
////	cout<<K2->data<<endl;
//	if(K2->data<K3->data&&K2->data>K1->data)
//	{
//		rotateright(K3);
//		K1=K3;
//		rotateleft(K1);
//		T=K1;
//	}
//	else	if(K2->data>K3->data&&K2->data<K1->data)
//	{
//		rotateleft(K3);
//		K1=K3;
//		rotateright(K1);
//		T=K1;
//	}
//	else	if(K2->data>K3->data&&K2->data>K1->data)
//	{
//		cout<<" in bal K1->data was "<<K1->data<<endl;
//		rotateleft(K1);
//		cout<<" in bal K1->data is "<<K1->data<<endl;
//		T=K1;
//	}
//	else	if(K2->data<K3->data&&K2->data<K1->data)
//	{
//		rotateright(K1);
//		T=K1;
//	}
//}

void heap(tnode *&T)
{
	cout<<"\n*in heap*\n";
	tnode *K;
	K=T;
	if(K->lchild==NULL)
	{
		if(K->rchild->data<K->data)
		{
			rotateleft(K);
			T=K;
		}
	}
	else	if(K->rchild==NULL)
	{
		if(K->lchild->data<K->data)
		{
			rotateright(K);
			T=K;
		}
	}
	else	if(!(K->lchild==NULL&&K->rchild==NULL))
	{
		if(K->rchild->data<K->data)
		{
			rotateleft(K);
			T=K;
		}
		if(K->lchild->data<K->data)
		{
			rotateright(K);
			T=K;
		}
	}
}

void chkheap(tnode *&T)
{
	cout<<"\n*in chkheap*\n";
	if(T!=NULL)
	{
//		int d;
		chkheap(T->lchild);
//		d=height(T->lchild)-height(T->rchild);
//		cout<<"\ndifference of height of children "<<d<<endl;
//		if(d>1||d<-1)
		if(!(T->lchild==NULL&&T->rchild==NULL))
		{
//			if(T->lchild->data<T->data||T->rchild->data<T->data)
//			{
				cout<<" in chkheap T->data was "<<T->data<<endl;
				heap(T);
				cout<<" in chkheap T->data is "<<T->data<<endl;
//			}
		}
		chkheap(T->rchild);
	}

	cout<<"\n*checked*\n";
}

//void insert(tnode *&T,int k)
//{
////	T=head;
//	if(T==NULL)
//	{
//		T=new tnode;
//		T->data=k;
////		T->ht=height(T);
////		chkbal(X);
//		T->lchild=NULL;
//		T->rchild=NULL;
//
//	}
//	else
//	{
//		if(k<T->data)
//		{
////			X=T;
//			insert(T->lchild,k);
//		}
//		else
//		{
////			X=T;
//			insert(T->rchild,k);
//		}
//	}
//}

void insert(tnode *&T,char k,int k2)
{
//	T=head;
	if(T==NULL)
	{
		T=new tnode;
		T->dat=k;
		T->data=k2;
		T->lchild=NULL;
		T->rchild=NULL;
	}
	else
	{
		if(k<T->dat)
		{
			insert(T->lchild,k,k2);
		}
		else
		{
			insert(T->rchild,k,k2);
		}
	}
}


int min(tnode *t)
{
	if(t->lchild==NULL)
		return t->data;
	else
		min(t->lchild);
}

void del(tnode *&T,int k)
{
	int t;
	tnode *temp;
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
	tnode *T=NULL;
	int k2;
	char ch,k;
//	cout<<"how many nodes you want to enter?\n";
//	cin>>n;
	while(k>=0)
	{
		cout<<"enter node char and int\n";
		cin>>k>>k2;
		if(k2>=0)
		{
			insert(T,k,k2);
			cout<<"\n*inserted*\n";
			chkheap(T);
			cout<<"\n inorder \n";
			inorder(T);
			cout<<"\n pre order \n";
			preorder(T);
		}
		else
			break;
	}
	ch='y';
	while(ch=='y')
	{
	cout<<"\ndo you want to delete a node?\n";
	cin>>ch;
	if(ch=='y')
	{
		cout<<"enter the node int\n";
		cin>>k;
		del(T,k);
		chkheap(T);
		cout<<"\n inorder \n";
		inorder(T);
		cout<<"\n preorder \n";
		preorder(T);
		}
		else
		{
			break;
		}
	}
	
	return 0;
}
