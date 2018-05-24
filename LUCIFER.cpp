// LUCIFER Number

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
 
	int dp[10][100][100];
 
 
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
 
	int func(int i,int s,int s2,int f)
	{
		if(i==0)
			{
				if(s>s2)
					return 0;
				return (1-isprime[s2-s]);
			}
 
		if(dp[i][s][s2]!=-1)
			return dp[i][s][s2];
		dp[i][s][s2]=0;
		for(int j=0;j<10;++j)
		{
			if(f==0)
			dp[i][s][s2]+=func(i-1,s+j,s2,1);
			else
			dp[i][s][s2]+=func(i-1,s,s2+j,0);
		}
		return dp[i][s][s2];
 
	}
 
 
 
 
	int func2(string s)
	{
		int n=s.length(),i,j,x,s1=0,s2=0,ans=0,z=0;
		z=n;
		for(i=0;i<n;++i)
		{
			x=s[i]-'0';
			--z;
			for(j=0;j<x;++j)
			{
				if((n-i)%2==0)
				{
					ans=ans+func(z,s1,s2+j,0);
				}
				else
					ans=ans+func(z,s1+j,s2,1);
			}
			if((n-i)%2==0)
				s2=s2+x;
			else
				s1=s1+x;
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
						for(int k=0;k<=81;++k)
							dp[i][j][k]=-1;
			int ans=func2(b1)-func2(a1);
			cout<<ans<<endl;
		}
		return 0;
	}
 