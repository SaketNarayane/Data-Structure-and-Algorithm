#include<iostream>
#include<cmath>
#include<queue>
queue<btnode*>qp,q;
using namespace std;

struct hnode
{
	int *data;
	
};

int size=0,size1;

void heapify(hnode &H,int i)
{
	int t;
	while(i>1)
	{
		if(H.data[i/2]>H.data[i])
		{
			t=H.data[i];
			H.data[i]=H.data[i/2];
			H.data[i/2]=t;
		}
		i/=2;
	}
	
}

void create(hnode &H)
{
	int i,n;
	cout<<"how many elements you want to enter?\n";
	cin>>n;
	size=n;
	size1=size;
	H.data=new int[n];
	for(i=1;i<=n;i++)
	{
	cout<<"enter value\n";
	cin>>H.data[i];
	heapify(H,i);
	}
}

void createall(hnode H[],int h)
{
	int i;
	for(i=0;i<h;i++)
	{
		create(H[i]);
	}
}

void percolatedown(hnode &H)
{
	int i=1,t;
	while(i<=size/2)
	{
		if(H.data[2*i]<H.data[2*i+1])
		{
			t=H.data[2*i];
			H.data[2*i]=H.data[i];
			H.data[i]=t;
			i=2*i;
		}
		else
		{
			{
				t=H.data[(2*i)+1];
				H.data[(2*i)+1]=H.data[i];
				H.data[i]=t;
				i=(2*i)+1;
			}
		}
	}
}

int deheap(hnode &H)
{
	int t;
	t=H.data[1];
	H.data[1]=H.data[size];
	size--;
	percolatedown(H);
	return t;
}

void sort(hnode H)
{
	cout<<"the sorted order is:\n";
	while(size>0)
	{
		cout<<deheap(H)<<" ";
	}
}

void print(hnode H)
{
	int i;
	for(i=1;i<=size;i++)
	{
		cout<<H.data[i]<<" ";
	}
	
}

void printall(hnode H[],int h)
{
	int i;
	for(i=0;i<h;i++)
	{
		cout<<i+1<<" heap is: ";
		print(H[i]);
		cout<<endl;
	}
}


struct btnode;
//
//class stack
//{
//	public:
//	int data[20];
//	int topofstack;
//	private:
//		void isempty();
//		void isfull();
//		void push(btnode  )
//}


struct btnode
{
	btnode *lchild;
	int data;
	int h;
	btnode *rchild;
}b;
//
//btnode * tour(btnode* head, btnode h )
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
	for(i=1;i<n;i++)
	{
		h=pow(2,i);
//		cout<<"in func   "<<h;
		if(h>=n)
			break;
	}
	return i;
}

void create(btnode *&T,int ht)
{
	if(T==NULL&&height>=ht)
	{
		T=new btnode;
		T->h=ht;
		T->data='\0';
		T->lchild=NULL;
		T->rchild=NULL;
//		cout<<"  sfasse  ";
	
	
	
		create(T->lchild,ht+1);
		create(T->rchild,ht+1);
	}
//	cout<<"  jhf ";
}


void insert(btnode *&T)
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

void storeleafinq(tnode *&T)
{
	if(T->lchild==NULL&&T->rchild==NULL&&T->data!='\0')
	{
		q.push(T);
	}
}

void datainleaf(btnode *&T,hnode[])
{
	int sz,i;
	sz=q.size();
	for(i=0;i<sz;i++)
	{
			T=q.front();
			q.pop();
			T->data=heapsort(H[i]);
			q.push(T);
	}
}


//void remove(btnode *&T,int t)
//{
//	int f=0;
//	while(f!=1)
//	{
//	if(T->data==t)
//	{
//		T->data='\0';
//		f=1;
//	}
//	else
//	{
//			remove(T->lchild,t);
//			remove(T->rchild,t);
//	}
//	}
//}

//int min(btnode *T,int data)
//{
//	if(T->lchild==NULL&&T->rchild==NULL)
//	{
//		return T->data;
//	}
//	else
//	{
//	if((min(T->lchild,T->lchild->data))>(min(T->rchild,T->rchild->data)))
//	{
//		return T->rchild->data;
//	}
//	else
//	{
//		return T->lchild->data;
//	}
//	}
//}


void tsort(btnode *&T)
{
	int t=9999;
	cout<<"the sorted order is\n";
	while(t!='\0')
	{
	t=min(T,T->data);
	cout<<" data "<<t<<" ";
	if(t!='\0')
	{
		cout<<t<<" ";
		remove(T,t);
	}
	}
}

int main()
{
int h;
	cout<<"\nhow many heaps you want to create?\n";
	cin>>h;
	hnode H[h];
	createall(H,h);
	printall(H,h);	
	
	return 0;
}
