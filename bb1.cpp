#include<iostream>
using namespace std;
string func(int a)
{
	string output="";
	char x='a',z;
	if (a==0)
		return "";
	int b=a,y;
	while(b>0)
	{
		y=b%26;
		
		if(y!=0)
		z= x+y-1;
		else
		{
			z='z';
			b--;
		}
		b=b/26;
		output=z+output;

	}
	return output;
}
int main()
{
	int n;
	cin>>n;
	cout<<endl<<func(n)<<endl;
	return 0;
}