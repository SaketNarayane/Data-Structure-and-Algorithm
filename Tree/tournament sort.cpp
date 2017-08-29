#include<iostream>
#include<cmath>
using namespace std;

struct BTnode;
//
//class stack
//{
//	public:
//	int data[20];
//	int topofstack;
//	private:
//		void isempty();
//		void isfull();
//		void push(BTnode  )
//}


struct BTnode
{
	BTnode *lchild;
	int data;
	int h;
	BTnode *rchild;
}b;
//
//BTnode * tour(BTnode* head, BTnode h )
//{
//	if((head->lchild->lchild==NULL)&&(head->lchild->rchild==NULL)&&(head->rchild->lchild==NULL)&&(head->rchild->rchild==NULL))
//	{
//		if(head->lchild->data>head->rchild->data)
//		{
//			head->data=lchild->data;
//			delete head->lchild,head->rchild;
//			return head;
//		}
//		else
//			head->data=rchild->data;
//			delete head->lchild,head->rchild;
//		return head;
//	}
//	else
//	{
//		if(tour(head->lchild)->data>tour(head->rchild)->data)
//			return head->lchild;
//	}
//			
//	}
int height;
int n;

int hght(int n)
{
	int h,i;
	for(i=0;i<n;i++)
	{
		h=pow(2,i);
//		cout<<"in func   "<<h;
		if(h>=n)
			break;
	}
	return i;
}

void create(BTnode *&T,int ht)
{
	if(T==NULL&&height>=ht)
	{
		T=new BTnode;
		T->h=ht;
		T->data=9999;
		T->lchild=NULL;
		T->rchild=NULL;
//		cout<<"  sfasse  ";
		create(T->lchild,ht+1);
		create(T->rchild,ht+1);
	}
//	cout<<"  jhf ";
}


void insert(BTnode *&T)
{
	static int i=0;
	if(i<n)
	{
		if(T->h==height)
		{
			cout<<"enter the number to be sorted\n";
			cin>>T->data;
			i++;
		}
		else
		{
			insert(T->lchild);
			insert(T->rchild);
		}
	}
}


void remove(BTnode *&T,int t)
{
	if(T!=NULL){
	if(T->data==t)
	{
		T->data=9999;
		remove(T->lchild,t);
		remove(T->rchild,t);
	}
	}
}

void print(BTnode *T){
	if(T!=NULL){
	print(T->lchild);
	cout<<T->data<<" ";
	print(T->rchild);
}
}
int min(BTnode *T)
{
	if(T!=NULL){
		if(T->lchild==NULL && T->rchild == NULL)
		return T->data;
		else{
			int x = min(T->lchild);
			int y = min(T->rchild);
			if(x < y){
				T->data = x;
				return x;
			}
			else{
				T->data = y;
			return y;
		}
		}
	}
}


void tsort(BTnode *&T)
{
	int t=0;
	cout<<"the sorted order is\n";
	while(t!=9999)
	{
	t=min(T);
//	cout<<" data "<<t<<" ";
	if(t!=9999)
	{
		cout<<t<<" ";
		remove(T,t);
		//print(T);
		//return ;
	}
	}
}
int main()
{
	BTnode *T=NULL;
	cout<<"enter the number of elements you want to enter\n";
	cin>>n;
	height=hght(n);
//	cout<<height<<"   fsdjfs   ";
	create(T,0);
	print(T);
	insert(T);
	//print(T);
//	cout<< tour(T)->data;
	tsort(T);
	return 0;
}
