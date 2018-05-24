// Police Query

#include <bits/stdc++.h>
using namespace std;
 

//FAST IO by mukel ---- http://ideone.com/fOK6CW 
static struct IO {
	char tmp[1 << 10];
 
	// fast input routines
	char cur;
 
//#define nextChar() (cur = getc_unlocked(stdin))
//#define peekChar() (cur)
	inline char nextChar() { return cur = getc_unlocked(stdin); }
	inline char peekChar() { return cur; }
 
	inline operator bool() { return peekChar(); }
	inline static bool isBlank(char c) { return (c < '-' && c); }
	inline bool skipBlanks() { while (isBlank(nextChar())); return peekChar() != 0; }
 
	inline IO& operator >> (char & c) { c = nextChar(); return *this; }
 
	inline IO& operator >> (char * buf) {
		if (skipBlanks()) {
			if (peekChar()) {
				*(buf++) = peekChar();
				while (!isBlank(nextChar())) *(buf++) = peekChar();
			} *(buf++) = 0; } return *this; }
 
	inline IO& operator >> (string & s) {
		if (skipBlanks()) {	s.clear(); s += peekChar();
			while (!isBlank(nextChar())) s += peekChar(); }
		return *this; }
 
	inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;	}
 
#define defineInFor(intType) \
	inline IO& operator >>(intType & n) { \
		if (skipBlanks()) { \
			int sign = +1; \
			if (peekChar() == '-') { \
				sign = -1; \
				n = nextChar() - '0'; \
			} else \
				n = peekChar() - '0'; \
			while (!isBlank(nextChar())) { \
				n += n + (n << 3) + peekChar() - 48; \
			} \
			n *= sign; \
		} \
		return *this; \
	}
 
defineInFor(int)
defineInFor(unsigned int)
defineInFor(long long)
 
	// fast output routines
 
//#define putChar(c) putc_unlocked((c), stdout)
	inline void putChar(char c) { putc_unlocked(c, stdout); }
	inline IO& operator << (char c) { putChar(c); return *this; }
	inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }
 
	inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }
 
	char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
	inline IO& operator << (double d) { return (*this) << toString(d); }
 
 
#define defineOutFor(intType) \
	inline char * toString(intType n) { \
		char * p = (tmp + 30); \
		if (n) { \
			bool isNeg = 0; \
			if (n < 0) isNeg = 1, n = -n; \
			while (n) \
				*--p = (n % 10) + '0', n /= 10; \
			if (isNeg) *--p = '-'; \
		} else *--p = '0'; \
		return p; \
	} \
	inline IO& operator << (intType n) { return (*this) << toString(n); }
 
defineOutFor(int)
defineOutFor(long long)
 
#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;
 
 
 
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 112345;
 
int d[N], low[N], f[N], cut[N], seen[N], tempo;
vector<int> adj[N], so[N];
set<pii> bs;
 
void dfs(int u, int p) {
	int nf = 0; bool any = false;
	seen[u] = true;
	d[u] = low[u] = tempo++;
	for(int v : adj[u])
		if(!seen[v]) {
			dfs(v, u); nf++;
			so[u].pb(v);
			any |= (low[v] >= d[u]);
			if(low[v] > d[u]) bs.insert(pii(u, v));
			low[u] = min(low[u], low[v]);
		} else if(v != p) low[u] = min(low[u], d[v]);
	cut[u] = (u? any : nf > 1);
	f[u] = tempo++;
}
 
inline bool comp(int a, int u) 
{ return d[a] >= d[u] && f[a] <= f[u]; }
 
int id(int a, int u) {
	if(comp(a, u)) {
		int b = *prev(upper_bound(so[u].begin(), so[u].end(), a, [](int i, int j) { return d[i] < d[j]; }));
		if(low[b] >= d[u]) return b;
		else return -1;
	}
	else return -1;
}
 
int main() 
{
	int i, n, m, a, b, u, v, op;
	cin>>n>>m;
	for(i = 0; i < m; i++) 
	{
		cin>>a>>b; 
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0, 0);
	for_tests(q, qq) {
		cin>>op>>a>>b>>u; 
		--a,--b,--u;
		if(op == 1) 
		{
			cin>>v;
			--v;
			if(d[v] < d[u]) 
			swap(u, v);
			if(!bs.count(pii(u, v))) 
			{
			    cout<<"da"<<endl; 
			    continue; 
			}
			if(comp(a, v) == comp(b, v)) 
			cout<<"da"<<endl;
			else 
			cout<<"ne"<<endl;
		} 
		else 
		{
			if(!cut[u]) 
			{ 
			    cout<<"da"<<endl; 
			    continue; 
			}
			if(id(a, u) == id(b, u)) 
			cout<<"da"<<endl;
			else 
			cout<<"ne"<<endl;
		}
	}
	return 0;
} 