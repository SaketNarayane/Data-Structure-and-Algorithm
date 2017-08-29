#include<iostream>
using namespace std;
#include<cstring>
int main()
{
	char name[40],newname[10];
	int i,j,l=0,sppos[5],lofsubstr[5],mark,max=0,lim;
	cout<<"enter the name"<<endl;
	cin.getline(name,40);
	l=strlen(name);
	sppos[0]=0;
	for(i=0,j=1;i<l;i++)
	{
		if(name[i]==' ')
		{
			sppos[j]=i+1;
			j++;
		}
		sppos[j]=l+1;
		lim=j;
	}
	for(i=0;i<5;i++)
	{
		lofsubstr[i]=sppos[i+1]-(sppos[i]+1);
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(lofsubstr[i]>lofsubstr[j]&&lofsubstr[i]<9&&lofsubstr[i]>max)
			{
				mark=i;
				max=lofsubstr[i];
			}
		}
	}
	for(i=0;i<l;i++)
	{
		for(j=0;j<lim+1;j++)
		{
			if(i==sppos[j])
			{
				if(i==mark)
				{
					for(int k=sppos[j];k<sppos[j+1];k++)
					{
						cout<<name[k];
					}
				}
				if(i!=mark)
				{
					cout<<name[i]<<" ";
				}
			}
		}
	}
	//cout<<max<<mark;
	//cout<<lofsubstr[0]<<lofsubstr[1]<<lofsubstr[2]<<lofsubstr[3];
	return 0;
}
