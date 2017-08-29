#include<iostream>
using namespace std;
const int d=2;

struct bnode
{
	public:
	int count;
	int data[2*d];
	bnode *child[2*d+1];
};

bnode *X=NULL;
int pos,flag=0;

int returnpos(bnode*T,int k)
{
	for(int i=0;i<T->count;i++)
	{
		if(T->data[i]==k)
		{
			return i;
		}
	}
	return -3;
}

void add(bnode*&T,int k);

void insertnsort(bnode *&T,int k)
{
	int flag=0;
	cout<<"\nI'm in insertnsort\n";
	for(int i=0;i<T->count;i++)
	{
		if(k<T->data[i])
		{
			for(int j=T->count;j>i;j--)
			{
				T->data[j]=T->data[j-1];
				T->child[j+1]=T->child[j];
			}
			T->data[i]=k;
			T->child[i]=NULL;
			T->child[i+1]=NULL;
			flag=1;
			break;
		}
	}
	if(!flag)
	{
		T->data[T->count]=k;
	}
	T->count++;
	cout<<T->data[1]<<endl;
}


void splitnconnect(bnode *&T,int k)
{
	cout<<"\n I'm in splitnconnect\n";
	int parent,i,j,l;
	if(k<T->data[d-1])
	{
		parent=T->data[d-1];

		T->data[d-1]=k;
	}
	else
	{
		if(k>T->data[d])
		{
			parent=T->data[d];
			T->data[d]=k;
		}
		else
		{
			parent=k;
		}
	}
	cout<<"after splitting, parent is "<<parent<<endl;
		add(X,parent);
		i=returnpos(X,parent);
	cout<<" X is "<<X->data[0];
	X->child[i]=T;
	X->child[i+1]=new bnode;
	for( j=d, l=0;j<2*d;j++,l++)
	{
		X->child[i+1]->data[l]=T->data[j];
		T->count=d;
		X->child[i+1]->count=d;
	}
	cout<<T->data[0];
	T=X;
	cout<<"spncn "<<T->data[0]<<endl;
}

void keydistribution(bnode *&T,int dest,int source)
{
	if(dest>source)
	{
		insertnsort(X->child[dest],X->data[source]);
		X->data[source]=X->child[source]->data[2*d-1];
		X->child[source]->count--;
		
	}
	else
	{
		insertnsort(X->child[dest],X->data[dest]);
		X->data[source]=X->child[source]->data[0];
		for(int i=0;i<X->child[source]->count-1;i++)
		{
			X->child[source]->data[i]=X->child[source]->data[i+1];
			X->child[source]->count--;
		}
	}
}

void add(bnode *&T,int k)
{
	int i;
	if(T==NULL)
	{
		T=new bnode;
		T->data[0]=k;
		T->count=1;
		for(i=0;i<=2*d+1;i++)
		{
			T->child[i]=NULL;
		}
	}
	else
	{
		if(T->child[0]!=NULL)
		{
			if(k<T->data[0])
			{
				add(T->child[0],k);
				pos=0;
			}
			for(i=0;i<2*d-1;i++)
			{
				if(k>T->data[i]&&k<T->data[i+1])
				{
					add(T->child[i+1],k);
					pos=i+1;
					break;
				}
			}
			if(k>T->data[2*d-1])
			{
				add(T->child[(2*d)],k);
				pos=2*d+1;
			}
			X=T;
		}
		else
		{
			if(T->count!=2*d)
			{
				insertnsort(T,k);
			}
			else
			{
				if(pos==0)
				{
					if(X->child[1]->count!=2*d)
					{
						keydistribution(X,pos+1,pos);
						flag=1;
					}
				}
				else
				{
					if(pos==2*d+1)
					{
						if(X->child[2*d]->count!=2*d)
						{
							keydistribution(X,pos-1,pos);
							flag=1;
						}
					}
					else
					{
						if(X->child[pos-1]->count!=2*d)
						{
							keydistribution(X,pos-1,pos);
							flag=1;
						}
						else if(X->child[pos+1]->count!=2*d)
						{
							keydistribution(X,pos+1,pos);
							flag=1;
						}
					}
				}
			}
			if(T->count==2*d&&flag!=1)
			{
				splitnconnect(T,k);
			}
		}
	}
}

void create(bnode *&T)
{
	int k;
	while(k!=-99)
	{
		cout<<"enter the numbers\n(-99 to terminate)\n";
		cin>>k;
		if(k!=-99)
		{

			add(T,k);
		}
		
		
	}
}

void levelorder(bnode *T)
{
	int i;
	if(T!=NULL)
	{
		for(i=0;i<T->count;i++)
		{
			cout<<T->data[i]<<" ";
		}
		cout<<"    ";
		for(i=0;i<=T->count;i++)
		{
			levelorder(T->child[i]);
		}
	}
}

//void inorder(bnode *T)
//{
//	static int i=0;
//	if(T!=NULL)
//	{
//		while(i<T->count)
//		{
//			inorder(T->child[i]);
//			cout<<T->data[i]<<" ";
//			inorder(T->child[i+1]);
//			i++;
//		}
//	}
//}


int main()
{
	bnode *T=NULL;
	create(T);
	levelorder(T);
//	inorder(T);
	if(T->child[0]==NULL)
	cout<<"\nI screwed up here\n";
//	cout<<T->child[0]->data[0];
	return 0;
}
