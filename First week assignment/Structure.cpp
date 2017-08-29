#include<iostream>
#include<conio.h>
using namespace std;
struct student
{
       int roll;
       float cgpa;
       char name[20];
};
int main()
{
          student s[20];
          int i,n;
          float sum=0;
          cout<<"Enter the number of students\n";
          cin>>n;
          for(i=0;i<n;i++)
          {
                cout<<"Enter student "<<i+1<<" details\n";
                cout<<"Enter Roll Number : ";
                cin>>s[i].roll;
                cout<<"Enter name of student : ";
                cin>>s[i].name;
                cout<<"Enter CGPA : ";
                cin>>s[i].cgpa;
          }
          for(i=0;i<n;i++)
          {
                cout<<"Details of student "<<i+1<<endl;
                cout<<"Roll number : "<<s[i].roll<<endl;
                cout<<"Name : "<<s[i].name<<endl;
				cout<<"CGPA : "<<s[i].cgpa<<endl;
          }
          for(i=0;i<n;i++)
                sum+=s[i].cgpa;
          cout<<"The average CGPA of all students is : "<<sum/n;
          getch();
          return 0;
}
