	//PR003004 --- SPOJ


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

	int ar[20],ar2[20],len1,len2;

	void preprocess(ll a)
	{
		int i=0;
		len1=0;
		while(a>0)
		{
			ar[i]=a%10;
			a=a/10;
			++len1;
			++i;
		}

		reverse(ar,ar+len1);
	}
	ll solve(ll i,ll sum)
	{
		if(i==len1)
			return sum;
		int j=0;
		ll ans=0;
		while(j<ar[i])
		{
			ans=ans+(sum+j)*pow(10,(len1-1-i))+1LL*pow(10,(len1-1-i-1))*45*(len1-1-i);
			++j;
		}
		ans=ans+solve(i+1,sum+ar[i]);
		return ans;
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		int T;
		cin>>T;
		ll a,b;
		while(T--)
		{
			cin>>a>>b;
			if(a==-1)
				break;
			preprocess(b);
			ll ans=solve(0,0);
			preprocess(a-1);
			ans=ans-solve(0,0);
			cout<<ans<<endl;
		}
		return 0;
	}
