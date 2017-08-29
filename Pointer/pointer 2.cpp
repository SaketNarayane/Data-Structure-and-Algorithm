#include<iostream>
using namespace std;
struct s2
{
	int a;
	int b;
	float c;
};
struct s1
{
	int d;
	char e;
	s2 *f;
};
struct s3
{
	int g;
	char h;
};
struct s4
{
	s1 i;
	s3 j;
};
int main()
{
	s4 *s;
	s=new(s4);

	s->i.f=new(s2);
	cin>>s->i.f->a;
	cout<<"a= "<<s->i.f->a;
	return 0;
}
