// Polynomial Multiplication

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
	#define PI acos(-1.0)
	#define inf 1000000000000000001;
	#define all(c) c.begin(),c.end()
	#define mp(x,y) make_pair(x,y)
	#define mem(a,val) memset(a,val,sizeof(a))
	#define eb emplace_back
	#define pb push_back
	#define f first
	#define s second
	using namespace std;
 
	#define base complex<double>
	
	void fft(vector<base> &a,bool invert)
	{
 
		int n=a.size(),i,j;
 
		for(i=1,j=0;i<n;++i)	//Bit reverse
		{
			int bit=n>>1;
			for(;j>=bit;bit>>=1)
				j=j-bit;
			j=j+bit;
			if(i<j)
				swap(a[i],a[j]);
		}
 
 
		for(int len=2;len<=n;len<<=1)
		{
			ld ang=2*PI/len*(invert?-1:1);
			base wlen(cos(ang),sin(ang));
			for(i=0;i<n;i+=len)
			{
				base w(1);
				for(int j=0;j<len/2;++j)
				{
					base u=a[i+j],v=a[i+j+len/2]*w;
					a[i+j]=u+v;
					a[i+j+len/2]=u-v;
					w=w*wlen;
				}
			}
		}
 
		if(invert)
		{
			for(i=0;i<n;++i)
				a[i]/=n;
		}
	}
	vector<ll> res,a,b;
 
	void mul(const vector<ll> &a,const vector<ll> &b)
	{
		vector<base> fa(a.begin(),a.end()),fb(b.begin(),b.end());
		size_t n=1;
		int i;
		while(n<max(a.size(),b.size())) n<<=1;
		n<<=1;
		fa.resize(n),fb.resize(n);
		fft(fa,false);fft(fb,false);
		for(i=0;i<n;++i)
		{
			fa[i]=fa[i]*fb[i];
		}
		fft(fa,true);
		res.resize(n);
		for(i=0;i<n;++i)
			res[i]=(ll)(fa[i].real()+0.5);
	}
 
	int main()
	{
		std::ios::sync_with_stdio(false);
		int T;
		cin>>T;
		// cin.ignore(); must be there when using getline(cin, s)
		while(T--)
		{
			int n1,n2,i,x;
			cin>>n1;
			n2=n1;
			res.clear();
			a.clear();
			b.clear();
			for(i=0;i<n1+1;++i)
			{
				cin>>x;
				a.pb(x);
			}
			for(i=0;i<n2+1;++i)
			{
				cin>>x;
				b.pb(x);
			}
			mul(a,b);
			for(i=0;i<=n1+n2;++i)
				cout<<res[i]<<" ";
			cout<<endl;
		}
		return 0;
	} 