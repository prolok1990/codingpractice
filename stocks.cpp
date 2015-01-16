#include<iostream>
using namespace std;
int max(int a[],int limit)
{
	if(limit == 1)
		return 0;
	int max=0;
	int min=a[0];
	int i1=0,i2=0,itemp=0;
	for(int i=1;i<limit;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
			itemp=i;
		}
		if((a[i]-min)>max)
		{
			max=a[i]-min;
			i1=itemp;
			i2=i;
		}

	}
	cout<<endl<<i1<<","<<i2<<endl;
	return max;
}


int main()
{
int a[10];
cout<<"Enter the array:";
for(int i=0;i<10;i++)
{
	cin>>a[i];
}
int min,mx=0,limit=10;
min=a[0];
mx=max(a,limit);
cout<<endl<<mx<<endl;


	
}