//Bytelandian gold coins


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
 
	map<int,ll> mp;
 
	ll func(int n)
	{
		if(n==0)
			return 0;
		if(mp.find(n)!=mp.end())
			return mp[n];
		ll ans=n;
		ans=max(ans,func(n/2)+func(n/3)+func(n/4));
		return (mp[n]=ans);
	}
 
	int main()
	{
		std::ios::sync_with_stdio(false);
		int T;
		T=1;
		int n;
		// cin.ignore(); must be there when using getline(cin, s)
		while(cin>>n)
		{
			ll ans=func(n);
			cout<<ans<<endl;
		}
		return 0;
	}