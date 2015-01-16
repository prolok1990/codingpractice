#include<iostream>
using namespace std;
int Sum(int m)
{
	if (m<10)
		return m;
	return m%10+Sum(m/10);
}
int main()
{
	cout<<Sum(1234);
	return 0;
}