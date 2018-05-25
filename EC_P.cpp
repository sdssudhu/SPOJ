// EC_P - Critical Edges


	#include <bits/stdc++.h>
	#include <cstdio>
	#include <cstring>
	#include <cmath>
	#include <cstring>
	#include <chrono>
	#include <complex>
	#define ll long long
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
	
	vector<int> v[100001];
	vector<pair<int,int> >v2;
	int intime[100001],ti,visited[100001],ar[100001];

	void dfs(int i,int p)
	{
		visited[i]=1;
		intime[i]=ti;
		ar[i]=intime[i];
		++ti;
		for(int j=0;j<v[i].size();++j)
		{
			if(v[i][j]==p)
				continue;
			if(visited[v[i][j]]==0)
			{
				dfs(v[i][j],i);

				if(intime[i]<ar[v[i][j]])
				{
					v2.pb({min(i,v[i][j]),max(i,v[i][j])});
				}
				ar[i]=min(ar[i],ar[v[i][j]]);
			}
			else
			{
				ar[i]=min(ar[i],intime[v[i][j]]);
			}
		}
		++ti;
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		int T;
		cin>>T;
		int X=1;
		// cin.ignore(); must be there when using getline(cin, s)
		while(T--)
		{
			v2.clear();
			cout<<"Caso #"<<X<<endl;
			++X;
			int n,i,j,m,a,b;
			cin>>n>>m;
			for(i=0;i<=n;++i)
				v[i].clear(),visited[i]=0,ar[i]=0;
			for(i=0;i<m;++i)
			{
				cin>>a>>b;
				v[a].pb(b);
				v[b].pb(a);
			}
			ti=1;
			dfs(1,-1);
			if(v2.size()==0)
			{
				cout<<"Sin bloqueos"<<endl;
				continue;
			}
			sort(v2.begin(),v2.end());
			cout<<v2.size()<<endl;
			for(i=0;i<v2.size();++i)
				cout<<v2[i].f<<" "<<v2[i].s<<endl;

		}
		return 0;
	}
