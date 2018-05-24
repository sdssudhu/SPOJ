//Ada and Easy Game -- SPOJ

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
	
	int main()
	{
		std::ios::sync_with_stdio(false);
		int T;
		cin>>T;
		// cin.ignore(); must be there when using getline(cin, s)
		while(T--)
		{
			int n,m,i,j,x;
			cin>>n>>m;
			int ar[m];
			for(i=0;i<m;++i)
				cin>>ar[i];
			sort(ar,ar+m);
			int grundy[100001],mex[100001];
			grundy[0]=0;
			for(i=1;i<=100000;++i)
			{
				set<int> s;
				set<int>::iterator it;
				s.insert(i);
				for(j=0;j<m;++j)
				{
					if(i-ar[j]<0)
						break;
					mex[grundy[i-ar[j]]]=i;
				}
				int x=0;
				while(true)
				{
				if(mex[x]!=i)
					break;
				++x;
				}
				grundy[i]=x;
			}
 
			int ans=0;
			for(i=0;i<n;++i)
			{
				cin>>x;
				ans=ans^grundy[x];
			}
			if(ans>0)
				cout<<"Ada"<<endl;
			else
				cout<<"Vinit"<<endl;
		}
		return 0;
	}