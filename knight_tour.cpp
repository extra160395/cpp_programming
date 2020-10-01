#include<bits/stdc++.h>
using namespace std;

int q[8]={  2, 1, -1, -2, -2, -1,  1,  2 };
int w[8]={  1, 2,  2,  1, -1, -2, -2, -1 };
int a[8][8];

int safe(int i,int j)
{
	return i>=0 && j>=0 && i<8 && j<8 && a[i][j]==-1;
}

int foo(int i,int j,int val)
{
	if(val==64)
		return 1;
	int k;
	for(k=0;k<8;k++)
	{
		if(safe(q[k]+i,w[k]+j))
			{
				a[q[k]+i][w[k]+j]=val;
				if(foo(q[k]+i,w[k]+j,val+1))
					return 1;
				else
					a[q[k]+i][w[k]+j]=-1;
			}
	}
	return 0;
}

int print_sol()
{
	int i,j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int i,j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			a[i][j]=-1;
		}
	}
	a[0][0]=0;
	if(foo(0,0,1))
		print_sol();
	else
		cout<<"sol dont exist"<<endl;
}
