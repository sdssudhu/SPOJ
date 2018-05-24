// Cost

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
	#define mod 1000000000
	#define inf 1000000000000000001;
	#define all(c) c.begin(),c.end()
	#define mp(x,y) make_pair(x,y)
	#define mem(a,val) memset(a,val,sizeof(a))
	#define eb emplace_back
	#define pb push_back
	#define f first
	#define s second
	
	using namespace std;
 
	// Disjoint Set DataStructure
	map< int,int > parent; 		// reserve space for map if n > 10000
	map< int,int > urank;
	ll sz[100001];
	void create(ll x)
	{
		sz[x]=1;
		parent[x] = x ;
		urank[x] = 0 ; 		// rank = no. of nodes in its subtree
	}
 
	ll find(ll x)
	{
		if( parent[x] != x )	//path compression
		{
			parent[x] = find(parent[x]) ;
		}
		return parent[x];
	}
 
	void merge(ll x, ll y)
	{
		ll xroot = find(x);
		ll yroot = find(y);
 
		if( urank[xroot] <= urank[yroot] )	// Union by rank
		{
			parent[xroot] = yroot ;
			urank[yroot] = urank[yroot] + urank[xroot] ;
			sz[yroot]+=sz[xroot];
		}
		else
		{
			parent[yroot] = xroot;
			urank[xroot] = urank[xroot] + urank[yroot] ;
			sz[xroot]+=sz[yroot];
		}
	}
 
	class triple
	{
	public:
		ll a,b,c;
	};
 
	vector<triple> v;
 
	bool comp(triple i,triple j)
	{
		return i.c>j.c;
	}
 
 
	int main()
	{
		std::ios::sync_with_stdio(false);
		int T;
		T=1;
		// cin.ignore(); must be there when using getline(cin, s)
		while(T--)
		{
			int n,i,j,m,a,b,c;
			cin>>n>>m;
			for(i=1;i<=n;++i)
				create(i);
			ll sum=0;
			for(i=0;i<m;++i)
			{
				cin>>a>>b>>c;
				v.pb({a,b,c});
				sum=sum+c;
			}
			sum=sum%mod;
			sort(v.begin(),v.end(),comp);
 
			ll ans=0;
			int x,y;
			for(i=0;i<m;++i)
			{
				a=v[i].a,b=v[i].b,c=v[i].c;
				x=find(a);
				y=find(b);
				if(x!=y)
				{
					ans=(ans+(sz[x]*sz[y])%mod*sum)%mod;
					merge(x,y);
				}
				sum=(sum-c+mod)%mod;
			}
			cout<<ans<<endl;
		}
		return 0;
	}