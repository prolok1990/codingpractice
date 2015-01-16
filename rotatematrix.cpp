#include<iostream>
using namespace std;
bool swap(int &a, int &b)
{
	a=a^b;
	b=a^b;
	a=a^b;
	return true;
}
bool rotatelayer(int l,int **matrix,int n)
{
	int x;
	if((n-2*l ==1) || (n-2*l ==0))
		return true;

	

	for(x=l+1;x<n-l-1;x++)
	{
		swap(matrix[x][l],matrix[l][n-x-1]);
	}
	for(x=l+1;x<n-l-1;x++)
	{
		swap(matrix[x][l],matrix[n-l-1][x]);
	}
	for(x=l+1;x<n-l-1;x++)
	{
		swap(matrix[n-l-1][x],matrix[n-x-1][n-l-1]);
	}
	swap(matrix[l][l],matrix[l][n-l-1]);
	swap(matrix[l][l],matrix[n-l-1][l]);
	swap(matrix[n-l-1][l],matrix[n-l-1][n-l-1]);
	return true;


}
bool rotatematrix(int **matrix,int n)
{
	int l,limit;
	if(n<0)
		return false;
	limit=n/2;
	for(l=0;l<limit;l++)
		rotatelayer(l,matrix,n);
	return true;


}
void printmatrix(int **matrix,int n)
{
	cout<<endl;
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<matrix[i][j]<<" ";
			cout<<endl;
		}
	cout<<endl;
}
int main()
{
	int n;
	cout<<"Enter n:";
	cin>>n;
	int **matrix=new int*[n];
	for (int i=0;i<n;i++)
		matrix[i]=new int[n];
	cout<<endl<<"Enter the matrix:"<<endl;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>matrix[i][j];
	printmatrix(matrix,n);
	rotatematrix(matrix,n);
	printmatrix(matrix,n);

	return 0;
}
