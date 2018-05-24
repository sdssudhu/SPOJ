// Roads of NITT

	#include <bits/stdc++.h>
	#include <cstdio>
	#include <cstring>
	#include <cmath>
	#include <cstring>
	#include <chrono>
	#include <complex>
	#define ll int
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
 
	vector<pair<int,int> >v;
	vector<pair<int,int> >e;
	vector<int> v2[100001];
 
	int visited[100001];
 
	// Disjoint Set DataStructure
	int parent[100001]; 		// reserve space for map if n > 10000
	int urank[100001];
	ll sz[100001];
	ll ans;
	inline void create(ll x)
	{
		parent[x] = x ;
		urank[x] = 0 ; 		// rank = no. of nodes in its subtree
		sz[x]=1;
	}
 
	inline ll find(ll x)
	{
		if( parent[x] != x )	//path compression
		{
			parent[x] = find(parent[x]) ;
		}
		return parent[x];
	}
 
	inline void merge(ll x, ll y)
	{
		ll xroot = find(x);
		ll yroot = find(y);
 
		if( urank[xroot] <= urank[yroot] )	// Union by rank
		{
			parent[xroot] = yroot ;
			urank[yroot] = urank[yroot] + urank[xroot] ;
			ans=ans-2*sz[yroot]*sz[xroot];
			sz[yroot]+=sz[xroot];
		}
		else
		{
			parent[yroot] = xroot;
			urank[xroot] = urank[xroot] + urank[yroot] ;
			ans=ans-2*sz[yroot]*sz[xroot];
			sz[xroot]+=sz[yroot];
		}
	}
 
 
	void dfs(int i)
	{
		
		visited[i]=1;
		for(int j=0;j<v2[i].size();++j)
		{
			if(visited[v2[i][j]]==0)
			{
				dfs(v2[i][j]);
				merge(i,v2[i][j]);
			}
		}
	}
 
	int flag[100001];
 
	int main()
	{
		int T;
		scanf("%d",&T);
		// cin.ignore(); must be there when using getline(cin, s)
		while(T--)
		{
			int n,i,j,a,b,q;
			char ch;
			scanf("%d",&n);
			for(i=1;i<=n;++i)
				v2[i].clear(),visited[i]=0,create(i),flag[i]=0;
			e.clear(),v.clear();
			e.pb({0,0});
			ans=n*(n-1);
			for(i=1;i<=n-1;++i)
			{
				scanf("%d %d",&a,&b);
 
				e.pb({a,b});
			}
			scanf("%d",&q);
 
			while(q>0)
			{
				scanf("%c",&ch);
				scanf("%c",&ch);
				if(ch=='R')
				{
					scanf("%d",&a);
					flag[a]=1;
					v.pb({1,a});
					b=e[a].s;
					a=e[a].f;
				}
				else
				{
					v.pb({2,0});
				}
				--q;
			}
			for(i=1;i<=n-1;++i)
			{
				if(flag[i]==0)
				{
					a=e[i].f,b=e[i].s;
					v2[a].pb(b);
					v2[b].pb(a);
				}
			}
			for(i=1;i<=n;++i)
			{
				if(visited[i]==0)
					dfs(i);
			}
			reverse(v.begin(),v.end());
			vector<ll> v4;
			for(i=0;i<v.size();++i)
			{
				if(v[i].f==1)
				{
					a=e[v[i].s].f,b=e[v[i].s].s;
					merge(a,b);
				}
				else
				{
					v4.pb(ans);
				}
			}
			reverse(v4.begin(),v4.end());
			for(i=0;i<v4.size();++i)
			{
				printf("%d\n",v4[i]/2);
			}
			printf("\n");
		}
		return 0;
	}