#include<iostream>
using namespace std;
int main()
{
	int i,m,count=2,d;
	for(m=0;m<12;m++)
	{
		cout<<"\n";
		for(i=0;i<20;i++)
		{
			cout<<"_";
		}
		cout<<"\n\n";
		switch(m)
		{
			case 0:cout<<"January 2014"; break;
			case 1:cout<<"February 2014"; break;
			case 2:cout<<"March 2014"; break;
			case 3:cout<<"April 2014"; break;
			case 4:cout<<"May 2014"; break;
			case 5:cout<<"June 2014"; break;
			case 6:cout<<"July 2014"; break;
			case 7:cout<<"August 2014"; break;
			case 8:cout<<"September 2014"; break;
			case 9:cout<<"October 2014"; break;
			case 10:cout<<"November 2014"; break;
			case 11:cout<<"December 2014"; break;
			default: break;
		}
		cout<<"\n";
		for(i=0;i<20;i++)
		{
			cout<<"_";
		}
		cout<<endl;
		cout<<"m  t  w  t  f  s  s"<<endl;
		for(i=1;i<=count;i++)
		{
			cout<<"   ";
		}
		switch(m)
		{
			case 0:d=31; break;
			case 1:d=28; break;
			case 2:d=31; break;
			case 3:d=30; break;
			case 4:d=31; break;
			case 5:d=30; break;
			case 6:d=31; break;
			case 7:d=31; break;
			case 8:d=30; break;
			case 9:d=31; break;
			case 10:d=30; break;
			case 11:d=31; break;				
			default: break;
		}
		for(i=1;i<=d;i++)
		{
			if(i<10)
			{
				cout<<i<<"  ";
				count++;
			}
			else
			{
				cout<<i<<" ";
				count++;
			}
			if(count==7)
			{
				count=0;
				cout<<endl;
			}
		}
	}
	return 0;
}
