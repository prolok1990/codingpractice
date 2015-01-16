#include<iostream>
#include<string>
#include<map>
using namespace std;
bool unique(string str)
{
	map<char,bool> uni;
	for(int i=0;i<str.size();i++)
	{
		if (uni[str[i]])
			return false;
		else
			uni[str[i]]=true;
	}
	return true;

}


int main()
{
	cout<<unique("abcdef")<<endl;
	cout<<unique("abcasf")<<endl;
	return 0;
}