
	// Build the Fence

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
 
 
	//  Convex Hull - Returns vector of points belonging to hull in anti-clockwise order.
	typedef complex<double> point;
	#define x real()
	#define y imag()
 
	double dot(point a,point b){ return (conj(a)*b).x ; }
	double cross(point a,point b){ return (conj(a)*b).y ; }
 
	double dist(point a, point b){ return abs(a-b); }			//distance btw points a and b
 
	double dist(point a, point b, point c, bool issegment = false){		//distance btw line ab and point c
		double d = cross(b-a,c-a)/dist(a,b) ;
		if( issegment == true )						// if line is a segment, issegment is true
		{
			double dt1 = dot(b-a,c-b) ;
			if( dt1 > 0 )  return dist(b,c);
			double dt2 = dot(a-b,c-a) ;
			if( dt2 > 0 )  return dist(a,c);
		}
 
		return abs(d) ;
	}
 
	template<class T>
	istream& operator>>(istream& is, complex<T>& p){
	   T value;
	   is >> value;
	   p.real(value);
	   is >> value;
	   p.imag(value);
	   return is;
	}
 
	bool cmp(point& a, point& b)
	{
		if ( a.x == b.x )
		{
			return a.y < b.y ;
		}
		else
		{
			return a.x < b.x ;
		}
	}
 
 
	vector<point> hull(vector<point> P)
	{
	   int n = P.size() ;
	   int k = 0;
	   vector<point> H(2*n) ;
 
	   sort( all(P), cmp );
 
	   for (int  i = 0;  i < n;  i++) {			// lower monotone chain
			while( k>=2 && cross( H[k-1]-H[k-2], P[i]-H[k-2] ) <= 0)
					k--;
			H[k++] = P[i] ;
	   }
 
	   for (int  i = n-2, t=k+1;  i >= 0;  i--) {		// upper monotone chain
			while( k>=t && cross( H[k-1]-H[k-2], P[i]-H[k-2] ) <= 0)
					k--;
			H[k++] = P[i];
	   }
 
	   H.resize(k-1);
	   return H;
	}
 
	vector<point> v;
 
	map<pair<int,int> ,int> mp;
 
	int main()
	{
		std::ios::sync_with_stdio(false);
		int T;
		cin>>T;
		// cin.ignore(); must be there when using getline(cin, s)
		while(T--)
		{
			int n,i,j;
			cin>>n;
			point p;
			v.clear();
			for(i=0;i<n;++i)
			{
				cin>>p;
				v.pb(p);
			}
			for(i=n-1;i>=0;--i)
			{
				p=v[i];
				mp[{p.x,p.y}]=i+1;
			}
			vector<point> v2=hull(v);
 
			double ans=0.0;
			for(i=1;i<v2.size();++i)
			{
				ans=ans+dist(v2[i],v2[i-1]);
			}
			if(v2.size()>0)
			ans=ans+dist(v2[v2.size()-1],v2[0]);
			printf("%.9f\n",ans);
			fflush(stdout);
 
			int st=0;
			int mini=1e9,pos=0,z=1e9;
 
			for(i=0;i<v2.size();++i)
			{
				if(v2[i].y<mini)
				{
					mini=v2[i].y;
					z=v2[i].x;
					pos=i;
				}
				else if(v2[i].y==mini && z>v2[i].x)
				{
					mini=v2[i].y;
					z=v2[i].x;
					pos=i;
				}
			}
			st=pos;
 
			for(i=st;i<v2.size();++i)
				cout<<mp[{v2[i].x,v2[i].y}]<<" ";
			for(i=0;i<st;++i)
				cout<<mp[{v2[i].x,v2[i].y}]<<" ";
			if(n==1)
				cout<<1;
			cout<<endl<<endl;
		}
		return 0;
	}
 