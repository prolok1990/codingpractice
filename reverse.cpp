#include<iostream>
#include<string>
#include<map>
using namespace std;
void swap(char &a, char &b)
{
	a=a^b;
	b=a^b;
	a=a^b;
}
void reverse(char *str)
{
	int len;
	for(len=0;str[len]!='\0';len++)
	;


	for(int i=0;i<len/2;i++)
	{
		swap(str[i],str[len-i-1]);

	}
}
bool permutation(string a,string b)
{
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	if ( a== b)
		return true;
	else
		return false;
}
bool permutation2(string a,string b)
{
	map<char,int> count;
	if(a.length()!=b.length())
		return false;
	for(int i=0;i<a.length();i++)
	{
		if (count[a[i]])
			count[a[i]]++;
		else
			count[a[i]]=1;
	}
	for(int i=0;i<b.length();i++)
	{
		count[b[i]]--;

	}
	for(map<char,int>::iterator i=count.begin();i!=count.end();i++)
	{
		if(i->second != 0)
			return false;

	}
	return true;

}
int main()
{
	string a;
	string b;
	cout<<"Enter two strings:"<<endl;
	getline(cin,a);
	getline(cin,b);
	cout<<(permutation2(a,b)?"It is a permutation":"Not permutation")<<endl;
	return 0;

}