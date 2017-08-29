#include<iostream>
using namespace std;
struct vertex
{
	int visited=0;
	int dist=0;
	int pv=0;
};

int n;

int distance(vertex V[],int pv)
{
	if(V[pv].dist!=0)
	{
		return (V[pv].dist)+distance(V,V[pv].pv);
	}
	else
	{
		return 0;
	}
}

void path(vertex V[],int sv,int dv)
{
	int a[10],count=1,i,j;
	a[0]=dv;
	j=V[dv].pv;
	while(j!=sv)
	{
		a[count]=V[j].pv;
		count++;
		j=V[V[j].pv].pv;
	}
	cout<<"\nthe path is ";
	for(i=count-1;i>0;i--)
	{
		cout<<a[i]<<" -> ";
	}
	
}

int main()
{
	int **M,i,j,w,sv,dv;
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
		V[i].pv=i;
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
				cin>>w;
				M[i][j]=w;
			}
		}
//		cout<<i<<endl;
	}
	j=0;
	for(i=1;i<n+1;i++)
	{
		M[i][j]=i;
		M[j][i]=i;
	}
	M[0][0]=0;
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<n+1;j++)
		{
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"\nenter the source vertex\n";
	cin>>sv;
	cout<<"\nenter destination vertex\n";
	cin>>dv;
	
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			if(M[i][j]>0)
			{
				if(V[j].dist>(M[i][j]+distance(V,j)))
				{
					V[j].dist=(M[i][j]+distance(V,j));
					V[j].pv=j;
				}
			}
		}
		V[i].visited=1;
	}
	

	path(V,sv,dv);
	
	return 0;
}
