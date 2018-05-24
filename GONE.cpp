// G-One Numbers


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
 
	ll dp[10][100];
	int isprime[101];
 
	void init()
	{
		isprime[0]=isprime[1]=1;
		for(int i=2;i<=100;++i)
		{
			if(isprime[i]==0)
				for(int j=i*i;j<=100;j=j+i)
					isprime[j]=1;
		}
	}
 
	ll func(int i,ll s)
	{
		if(i==0)
		{
			return (1-isprime[s]);
		}
		if(dp[i][s]!=-1)
			return dp[i][s];
		dp[i][s]=0;
		for(int j=0;j<10;++j)
			dp[i][s]=dp[i][s]+func(i-1,s+j);
		return dp[i][s];
	}
 
	ll func2(string s)
	{
		int i,j,x,n=s.length(),z,sum=0;
		ll ans=0;
		z=n;
		for(i=0;i<n;++i)
		{
			--z;
			x=s[i]-'0';
			for(j=0;j<x;++j)
				ans=ans+func(z,sum+j);
			sum=sum+x;
		}
		return ans;
	}
 
	int main()
	{
		std::ios::sync_with_stdio(false);
		int T;
		cin>>T;
		init();
		// cin.ignore(); must be there when using getline(cin, s)
		while(T--)
		{
			int a,b;
			cin>>a>>b;
			++b;
			string a1=to_string(a);
			string b1=to_string(b);
				for(int i=0;i<10;++i)
					for(int j=0;j<=81;++j)
							dp[i][j]=-1;
			int ans=func2(b1)-func2(a1);
			cout<<ans<<endl;
		}
		return 0;
	}