#include<bits/stdc++.h>
using namespace std;

struct trie
{
	int f;
	trie* child[256];
	trie():f(1)
	{
		for(int i=0;i<256;i++)
		{
			child[i]=NULL;
		}
	};
};

void insert(trie*& T,string s, int i)
{
	if(i>=s.length())
	return ;
		
		if(T->child[s[i]]==NULL)
		{
			T->child[s[i]]=new trie();
		}
		else
		{
			(T->child[s[i]]->f)++;
		}
		insert(T->child[s[i]],s,i+1);
		
}

void ret(trie* T,string s, int i)
{
	if(i>=s.length())
	return;
	
	cout<<s[i]<<" : "<<T->child[s[i]]->f<<endl;
	ret(T->child[s[i]],s,i+1);
}
string uniqueprefix(trie* T,string s)
{
	string a;
	for(int i=0;i<s.length();i++)
	{
		if(T->child[s[i]]->f==1)
		{
			a.push_back(s[i]);
			return a;
		}
		a.push_back(s[i]);
		T=T->child[s[i]];
	}
	return a;
}

int main()
{
	trie* T=new trie();
	T->f=0;
	cout<<T->f;
	insert(T,"saket",0);
	cout<<T->child['s']->child['a']->f;
	insert(T,"sakshi",0);
	insert(T,"dog",0);
	insert(T,"sack",0);
	cout<<T->child['s']->child['a']->f;
	ret(T,"saket",0);
	ret(T,"sakshi",0);
	ret(T,"dog",0);
	cout<<uniqueprefix(T,"sack");
}
