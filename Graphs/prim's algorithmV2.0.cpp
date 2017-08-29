#include<iostream>
#include<queue>
using namespace std;
struct vertex
{
	int visited=0;
	int dist=0;
	int pv=0;
};

queue<int>q;
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

//void path(vertex V[],int sv,int dv)
//{
//	int a[10],count=1,i,j;
//	a[0]=dv;
//	j=V[dv].pv;
//	while(j!=sv)
//	{
//		a[count]=V[j].pv;
//		count++;
//		j=V[V[j].pv].pv;
//	}
//	cout<<"\nthe path is ";
//	for(i=count-1;i>0;i--)
//	{
//		cout<<a[i]<<" -> ";
//	}
//	
//}

int main()
{
	int **M,i,j,w,sv,dv,f;
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

	f=1;
	while(f)
	{
		cout<<"\n enter the vertices and then the weight of edge\n";
		cin>>i;
		cin>>j;
		cin>>w;
		M[i][j]=M[j][i]=w;
		cout<<"\nwant to enter more? (1/0)\n";
		cin>>f;
	}

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
	
//	cout<<"\nenter the source vertex\n";
//	cin>>sv;
//	cout<<"\nenter destination vertex\n";
//	cin>>dv;

//	q.push(sv);
//	while(!q.empty())
//	{
//		i=q.front();
//		q.pop();
//		V[i].visited=1;
//		for(j=1;j<n+1;j++)
//		{
//			if(M[i][j]>0)
//			{
//				if(!V[j].visited)
//				{
//					q.push(j);
//					
//				}
//				if(V[j].dist==0||(V[j].dist>(M[i][j]+V[V[j].pv].dist)))
//				{
//					V[j].dist=(M[i][j]+V[V[j].pv].dist);
//					V[j].pv=i;
//				}
//			}
//		}
//	}
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
//			if(j>i)
//			{
				if(M[i][j]>0)
				{
					if(V[j].visited==0)
					{
						V[j].visited=1;
						V[j].dist=M[i][j];
						V[j].pv=i;
					}
					else
					{
						if(V[j].dist>M[i][j]&&((V[j].pv==V[i].pv)||(V[V[j].pv].pv==V[i].pv)))
						{
							V[j].dist=M[i][j];
							V[j].pv=i;
						}
					}
				}
//			}
		}
	}
	
	int R[n+1][n+1];
	for(i=1,j=0;i<n+1;i++)
	{
		R[i][j]=R[j][i]=i;
	}
	R[0][0]=0;
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			R[i][j]=0;
		}
	}
	for(i=1;i<n+1;i++)
	{
		R[i][V[i].pv]=R[V[i].pv][i]=V[i].dist;
	}
	
//	path(V,sv,dv);
	
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<n+1;j++)
		{
			cout<<R[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
