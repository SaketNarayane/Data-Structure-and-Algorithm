#include<iostream>
#include<queue>
using namespace std;

struct vertex
{
	int visited=0;
	int backedge=99;
	int num;
	int low;
};
int n;

queue<int>q;


void unvisitize(vertex V[])
{
	int i;
	for(i=1;i<n+1;i++)
	{
		V[i].visited=0;
	}
}

void DFT(int **M,vertex V[],int i)
{
	int j;
	V[i].visited=1;
	for(j=1;j<n+1;j++)
	{
		if(M[i][j]>0)
		{
			if(V[j].visited==0)
			{
				q.push(j);
				DFT(M,V,j);
			}
			else
			{
				if((V[j].num-V[i].num)>1)
				{
					V[j].backedge=i;
				}
			}
		}
	}
}

int low(int **M,vertex V[],int i);

int min(int **M,vertex V[],int i)
{
	int j,l;
	for(j=1;j<n+1;j++)
	{
		if(M[i][j]!=0)
		{
			if(j!=V[i].backedge)
			{
				l=low(M,V,j);
				return l;
			}	
		}	
	}
	return 99;
}

int min(int i,int j,int k)
{
	if(i<j&&i<k)
	{
		return i;
	}
	else
	{
		if(j<i&&j<k)
		{
			return j;
		}
		else
		{
			return j;
		}
	}
}

int low(int **M,vertex V[],int i)
{
	int l;
	l=min(V[i].num,V[i].backedge,min(M,V,i));
	return l;
}

int articulationpoint(int **M,vertex V[])
{
	int i,j,k,c=0;
	cout<<"\n Articulation points: ";
	for(i=2;i<n+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			if(V[j].num==i)
			{
				break;
			}
		}
	for(k=1;k<n+1;k++)
	{
		if(M[j][k]>0)
		{
			if((V[k].num-V[j].num)==1)
			{
				if(V[k].low>=V[j].num)
				{
					cout<<" "<<j<<" ";
					c++;
				}
			}
		}
	}
	}
	return c-1;
}

void backedges(vertex V[])
{
	int i;
	cout<<"\nback-edges :";
	for(i=1;i<n+1;i++)
	{
		if(V[i].backedge!=99)
		{
			cout<<"\n"<<i<<" -> "<<V[i].backedge<<endl;
		}
	}
}

void treeedges(int **M,vertex V[],int i)
{
	int j;
	unvisitize(V);
	V[i].visited=1;
	for(j=1;j<n+1;j++)
	{
		if(M[i][j]>0)
		{
			if(V[j].visited==0)
			{
				if(V[i].backedge!=j||V[j].backedge!=i)
				{
					cout<<"\n"<<i<<" -> "<<j<<endl;
				}
				treeedges(M,V,j);
			}
		}
	}
}


int main()
{
	int **M,i,j,s,k;
	vertex *V;
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

	for(i=1;i<n+1;i++)
	{
		j=0;
		while(j!=-99)
		{
			cout<<"\nenter connections of "<<i<<" with a vertex with weight of edge(-99 to terminate)\n";
			cin>>j;
			if(j!=-99)
			{
				M[i][j]=1;
			}
		}
//		cout<<i<<endl;
	}
	
	cout<<"\nenter source vertex\n";
	cin>>s;
	DFT(M,V,s);
	
	i=1;
	while(!q.empty())
	{
		V[q.front()].num=i;
		q.pop();
		i++;
	}
	
	for(i=n;i>0;i--)
	{
		for(j=1;j<n+1;j++)
		{
			if(V[j].num==i)
			{
				break;
			}
		}
		V[j].low=low(M,V,j);
	}
	
	k=articulationpoint(M,V);
	
	cout<<"\n minimum no of edges required to make it biconected : ";
	if(k==0)
	{
		cout<<1;
	}
	else
	{
		cout<<k;	
	}
	
	backedges(V);
	treeedges(M,V,s);
}
