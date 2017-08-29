#include<iostream>
#include<fstream>
#include<string>
using namespace std;
char buff[1000];
void pack(char *x)
{
	strcat(*buff,x);
	strcat(*buff,'|');
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
   ofstream fout;
   fout.open("f1.txt");
   cout<<"how many student:";
   int n,i;
   cout<<"enter details(rollno,name,rank)\n";
   for(i=0;i<n;i++)
   {
   	fout<<'#';
   	cin.getline(s.rno,5);
   	pack(s.rno);
   	cin.getline(s.name,20);
   	pack(s.name);
   	cin.getline(s.rank,5);
   	pack(s.rank);
   	
   }
   fout.close();
   ifstream fin;
   fin.open("f1");
   while(fin)
   {
   	fin>>buff;
   }
}
