// Petya and Repairment of Roads

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
 
	int ar[200001];
 
	// Disjoint Set DataStructure
	int parent[200001]; 		// reserve space for map if n > 10000
	int urank[200001];
	bool ps[200001];
 
	void create(ll x)
	{
		parent[x] = x ;
		urank[x] = 0 ; 		// rank = no. of nodes in its subtree
		ps[x]=false;
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
			ps[yroot]=ps[yroot]|ps[xroot];
		}
		else
		{
			parent[yroot] = xroot;
			urank[xroot] = urank[xroot] + urank[yroot] ;
			ps[xroot]=ps[yroot]|ps[xroot];
		}
	}
 
	class triple
	{
	public:
		int a,b,c;
	};
 
	vector<triple> v;
 
	bool comp(triple i,triple j)
	{
		return i.c<j.c;
	}
 
	int main()
	{
		std::ios::sync_with_stdio(false);
		int T;
		cin>>T;
		// cin.ignore(); must be there when using getline(cin, s)
		while(T--)
		{
			int n,m,i,j,a,b,c;
			cin>>n>>m;
			int flag=0;
			v.clear();
			for(i=1;i<=n;++i)
			{
				create(i);
				cin>>ar[i];
				if(ar[i]==1)
				{
					flag=1;
					ps[i]=1;
				}
			}
			for(i=0;i<m;++i)
			{
				cin>>a>>b>>c;
				v.pb({a,b,c});
			}
			sort(v.begin(),v.end(),comp);
 
			ll ans=0;
			for(i=0;i<m;++i)
			{
				a=v[i].a,b=v[i].b,c=v[i].c;
				a=find(a),b=find(b);
				if(a==b || (ps[a] && ps[b]))
					;
				else
				{
					ans=ans+c;
					merge(a,b);
				}
			}
 
			for(i=1;i<=n;++i)
			{
				a=find(i);
				if(ps[a]==false)
				{
					ans=-1;
				}
			}
 
			if(ans>=0)
				cout<<ans<<endl;
			else
				cout<<"impossible"<<endl;
		}
		return 0;
	}