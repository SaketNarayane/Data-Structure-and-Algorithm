#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream fout;
	fout.open("setofnum.txt");
	int n1,n2,num,i;
	cout<<"How many numbers you want to enter?";
	cin>>n1;
	cout<<"Enter the numbers";
	for(i=0;i<n1;i++)
	{
		cin>>num;
		fout<<num<<"\n";
	}
	fout.close();
	fout.open("reqfrqof.txt");
	cout<<"Of how many numbers you want to find the frequency?";
	cin>>n2;
	cout<<"Enter the numbers";
	for(i=0;i<n2;i++)
	{
		cin>>num;
		fout<<num<<"\n";
	}
	fout.close();
	int a[n1],b[n2]; i=0;
	ifstream fin;
	fin.open("setofnum.txt");
	while(fin)
	{
		fin>>a[i++];
	}
	fin.close();
	i=0; int j;
	fin.open("reqfrqof.txt");
	while(fin)
	{
		fin>>b[i++];
	}
	int fre[n2];
	for(i=0;i<n2;i++)
	fre[i]=0;
	for(i=0;i<n2;i++)
	{
		for(j=0;j<n1;j++)
		{
			if(a[j]==b[i])
			fre[i]+=1;
		}
	}
	int max=fre[0];
	for(i=1;i<n2;i++)
	if(fre[i]>max)
	max=fre[i];
	fout.open("freq.txt");
	fout<<"Frequency of numbers is:\n";
	for(i=1;i<=max;i++)
	{
		for(j=0;j<n2;j++)
		{
			if(i>(max-fre[j]))
			fout<<"*"<<"\t";
			else
			fout<<"  \t";
		}
		fout<<endl;
	}
	for(i=0;i<n2;i++)
	fout<<b[i]<<"\t";
	return 0;
}
