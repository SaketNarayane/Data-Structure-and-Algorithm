#include<iostream>
#include<stack>
using namespace std;
stack<int>s;
int main()
{
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	while(!s.empty())
	s.pop();
	if(s.empty())
	{
		cout<<"empty";
	}
	return 0;
}
