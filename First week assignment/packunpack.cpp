#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
char buff[1000];
void pack(char *x)
{
	strcat(buff,x);
	strcat(buff,"|");
}
void unpack(char *x)
{
}
struct student
{
  char rno[5];
  char name[20];
  char rank[5];	
};
int main()
{
		
	student s;
	int x,y='#';
	char ch='y',str[20];
	ofstream fout;
	fout.open("pnu.txt");
	while(ch=='y')
	{
		cout<<"enter roll number\n";
		cin.getline(str,20);
		pack(str);
		cout<<"enter name\n";
		cin.getline(str,20);
		pack(str);
		cout<<"Rank\n";
		cin.getline(str,20);
		pack(str);
		strcat(buff,"#");		
		cout<<"do you want more entries?\n";
		cin>>ch;
		
	}
	fout<<buff;
	//fout<<"saketsdn";
	fout.close();
}
