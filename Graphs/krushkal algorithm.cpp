#include<iostream>
using namespace std;
struct vertex
{
	int visited=0;
};

struct sort
{
	int weight;
	int v1;
	int v2;
};


int *S,n;

int find(int i)
{
	if(S[i]<=0)
	{
		return i;
	}
	else
	{
		return (find(S[i]));
	}
}

void uniun(int x,int y)
{
	if(S[y]<=0&&S[x]<=0)
	{
//		if(S[y]==S[x])
//		{
			S[y]=x;
//		}
//		else
//		{
//			if(S[x]<S[y])
//			{
//				S[y]=x;
//			}
//			else
//			{
//				S[x]=y;
//			}

//		}
	}
	else
	{
		if(!(S[x]<=0))
		{
			if(!(S[y]<=0))
			{
				if(find(x)!=find(y))
				{
					uniun(x,S[y]);
				}
				else
				{
					return;
				}
			}
			S[y]=x;
		}
		else
		{
			if(!(S[y]<=0))
			{
				S[x]=y;
			}
			
		}
	}
	S[(find(x))]=-1;
}

void display(int a[])
{
	int i;
	cout<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<i<<" -> "<<a[i]<<endl;
	}
}


int main()
{
	sort T[20];
	vertex *V;
	int **M,i,j,w,f=1,count=0,k,l;
	cout<<"\n enter the number of vertices\n";
	cin>>n;
	M=new int*[n+1];
	V=new vertex[n+1];
	for(i=0;i<=n+1;i++)
	{
		M[i]=new int[n+1];
	}
	for(i=0;i<=n+1;i++)
	{
		for(j=0;j<=n+1;j++)
		{
			M[i][j]=0;
		}
	}
	S=new int[n+1];
	for(i=1;i<=n;i++)
	{
		S[i]=0;
	}

//	for(i=1;i<n+1;i++)
//	{
//		j=0;
		while(f)
		{
			cout<<"\nenter vertices and weight of edge\n";
			cin>>i;
			cin>>j;
			cin>>w;
//			if(j!=-99)
//			{
				cin>>w;
				M[i][j]=M[i][j]=w;
				for(k=0;k<count;k++)
				{
					if(w<T[k].weight)
					{
						for(l=count;l>=k;l--)
						{
							T[l+1]=T[l];
						}
						break;
					}
				}
				T[k].weight=w;
				T[k].v1=i;
				T[k].v2=j;
				count++;
//			}
			cout<<"\ndo you want to enter more?(1/0)\n";
			cin>>f;
		}
//		cout<<i<<endl;
//	}
	
	for(i=0;i<count;i++)
	{
		if(V[T[i].v1].visited!=1&&V[T[i].v2].visited!=1)
		{
			uniun(T[i].v1,T[i].v1);
			V[T[i].v1].visited=V[T[i].v2].visited=1;
		}
	}
	
	for(i=1,j=0;i<n+1;i++)
	{
		M[i][j]=i;
		M[j][i]=i;
	}
	M[0][0]=0;
	cout<<"\n the matrix is\n";
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<n+1;j++)
		{
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"\n the set is\n";
	display(S);
	return 0;
}
