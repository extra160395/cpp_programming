#include<bits/stdc++.h>
using namespace std;

int a[1000][1000]={0};
int n;

int safe(int r,int c)
{
	int i,j;

	for(i=0;i<c;i++)
		if(a[r][i]==1)
			return 0;

	for(i=0,j=0;i<r && j<c;i++,j++)
		if(a[i][j]==1)
			return 0;

	for(i=n-1,j=0;i>r && j<c;i--,j++)
		if(a[i][j]==1)
			return 0;

	return 1;
}

void print()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

int foo(int c)
{
	int i;
	if(c>=n)
		return 1;
	for(i=0;i<n;i++)
	{
		if(a[i][c]==0 && safe(i,c))
		{
			a[i][c]=1;
			if(foo(c+1))
				return 1;
			a[i][c]=0;
		}
	}
	return 0;
}

int main()
{
	int i,j;
	cin>>n;
	if(foo(0))
		print();
	else
		cout<<"No solution exist";
}
