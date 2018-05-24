// Query on a tree V

	#include <bits/stdc++.h>
	#include <cstdio>
	#include <cstring>
	#include <cmath>
	#include <cstring>
	#include <chrono>
	#include <complex>
	#define ll long long int
	#define ld long double
	#define vi vector<int>
	#define vll vector<ll>
	#define vvi vector < vi >
	#define pii pair<int,int>
	#define pll pair<long long, long long>
	#define mod 1000000007
	#define inf 1000000000000000001;
	#define all(c) c.begin(),c.end()
	#define mp(x,y) make_pair(x,y)
	#define mem(a,val) memset(a,val,sizeof(a))
	#define eb emplace_back
	#define pb push_back
	#define f first
	#define s second
	using namespace std;
 
	const int N=5e5;
	const int logn=20;
	vector<int> v[N];
 
	int dp[logn][N],par[N],sub[N],decomposed[N],level[N];
	int n;
	//Pre-processing
 
	void dfs0(int i)
	{
		for(int j=0;j<v[i].size();++j)
			if(v[i][j]!=dp[0][i])
			{
				level[v[i][j]]=level[i]+1;
				dp[0][v[i][j]]=i;
				dfs0(v[i][j]);
			}
	}
 
	void preprocess()
	{
		level[0]=0;
		dp[0][0]=0;
		dfs0(0);
		for(int i=1;i<logn;++i)
			for(int j=0;j<n;++j)
				dp[i][j]=dp[i-1][dp[i-1][j]];
	}
 
	int lca(int a,int b)
	{
		if(level[a]>level[b])
			swap(a,b);
		int d=level[b]-level[a];
		for(int i=0;i<logn;++i)
			if(d&(1<<i))
				b=dp[i][b];
			if(a==b)
				return a;
			for(int i=logn-1;i>=0;--i)
				if(dp[i][a]!=dp[i][b])
					a=dp[i][a],b=dp[i][b];
			return dp[0][a];
	}
 
	int dist(int a,int b)
	{
		return level[a]+level[b]-2*level[lca(a,b)];
	}
 
	//Centroid decomposition
 
	int nn;
	void dfs1(int i,int p)
	{
		++nn;
		sub[i]=1;
		for(int j=0;j<v[i].size();++j)
			if(v[i][j]!=p && decomposed[v[i][j]]==0)
			{
				dfs1(v[i][j],i);
				sub[i]=sub[i]+sub[v[i][j]];
			}
	}
 
	int dfs2(int i,int p)
	{
		for(int j=0;j<v[i].size();++j)
		{
			if(v[i][j]!=p && decomposed[v[i][j]]==0 && sub[v[i][j]]>nn/2)
				return dfs2(v[i][j],i);
		}
		return i;
	}
 
	void decompose(int i,int p)
	{
		nn=0;
		dfs1(i,i);
 
		int centroid=dfs2(i,-1);
		par[centroid]=p;
		decomposed[centroid]=1;
 
		for(int j=0;j<v[centroid].size();++j)
			if(decomposed[v[centroid][j]]==0)
			{
				decompose(v[centroid][j],centroid);
			}
 
	}
 
	set<pair<int,int> > s[100001];
	set<pair<int,int> >::iterator it;
	int main()
	{
		std::ios::sync_with_stdio(false);
		int T;
		T=1;
		while(T--)
		{
			int m,i,j,a,b,ch,x,z;
			cin>>n;
			int ans[n],answ,white[n];
			for(i=0;i<n-1;++i)
			{
				white[i]=0;
				ans[i]=1e9;
				cin>>a>>b;
				--a,--b;
				v[a].pb(b);
				v[b].pb(a);
			}
			preprocess();
			decompose(0,-1);
			ans[n-1]=1e9;
			cin>>m;
			while(m>0)
			{
				cin>>ch>>x;
				--x;
				if(ch==0)
				{
					z=x;
					white[x]=1-white[x];
					if(white[x]==1)
					{
					while(z!=-1)
					{
						s[z].insert({dist(x,z),x});
						z=par[z];
					}
					}
					else
					{
						while(z!=-1)
					{
						s[z].erase({dist(x,z),x});
						z=par[z];
					}
 
					}
				}
				else
				{
					answ=1e9;
					z=x;
					while(z!=-1)
					{
						if(s[z].size()>0)
						{
						it=s[z].begin();
						answ=min(answ,dist(z,x)+it->first);
						}
						z=par[z];
					}
					if(answ==1e9)
						cout<<-1<<endl;
					else
					cout<<answ<<endl;
				}
				--m;
			}
		}
		return 0;
	}
 