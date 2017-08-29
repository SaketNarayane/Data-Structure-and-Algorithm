#include<iostream>
using namespace std;
struct s1
{
	int a;
	char b;
	float c;
};
struct s2
{
	int d;
	char e;
	s1 *f;
};
int main()
{
	s2 s;
	s.f=new(s1);
	cin>>s.f->a;
	cout<<"a = "<<s.f->a;
	return 0;
}
