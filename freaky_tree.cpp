// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/freaky-tree/description/
#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<long int,long int>>>v(100000);
int cont=0,ans=0;
int vis[100000]={0};

int dfs(long int i)
{
	long int j;
	int flag=0;
	vis[i]=1;
	for(j=0;j<v[i].size();j++)
	{
		if(vis[v[i][j].first]==0)
		{
			if((v[i][j].second)%2==1)
				cont++;
			dfs(v[i][j].first);
			flag=1;
		}
	}
	if(flag==0)
	{
		if(cont%2==1)
			ans++;
	}
	vis[i]=0;
	if((v[i][0].second)%2==1)
		cont--;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cont=0,ans=0;
		memset(vis,0,sizeof(vis));

		long int n,i,x,y,z;

		for(i=0;i<100000;i++)
			v[i].clear();
		cin>>n;
		for(i=0;i<n-1;i++)
		{
			cin>>x>>y>>z;
			v[x].push_back({y,z});
			v[y].push_back({x,z});
		}
		dfs(1);
		cout<<ans<<endl;
	}
}
