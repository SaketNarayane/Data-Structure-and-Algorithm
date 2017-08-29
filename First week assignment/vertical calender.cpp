#include<iostream>
using namespace std;
int main()
{
	int i,day,sp,space=2,mnt,mnth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	for(mnt=0;mnt<12;mnt++)
	{
		cout<<"\n";
		for(i=0;i<20;i++)
		{
			cout<<"_";
		}
		cout<<"\n\n";
		switch(mnt)
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
		for(day=1;day<=7;day++)
		{
			switch(day)
			{
				case 1:cout<<"Mon  "; break;
				case 2:cout<<"Tue  "; break;
				case 3:cout<<"Wed  "; break;
				case 4:cout<<"Thu  "; break;
				case 5:cout<<"Fri  "; break;
				case 6:cout<<"Sat  "; break;
				case 7:cout<<"Sun  "; break;
				default: break;
			}
			for(i=1-space;i<=mnth[mnt];i+=7)
			{
				if(i<=0)
				{
					cout<<"   ";
				}
				else	if(i<10)
						{
							cout<<i<<"  ";
						}
						else
						{
							cout<<i<<" ";
						}
				if(i==mnth[mnt])
				{
					sp=(day%7);
				}
			}
			space--;
			cout<<endl;
		}
		space=sp;
	}
	return 0;
}
