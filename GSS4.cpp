// Can you answer these queries IV

#include<bits/stdc++.h>
 
using namespace std;
 
long long ar[100001];
long long tree[1000000],tree2[1000000];
 
 
void build(int node,int l,int r)
{
	if(l>r) return;
 
	if(l==r)
	{
		tree[node]=ar[l];
		return;
	}
	build(node*2,l,(l+r)/2);
	build(node*2+1,(l+r)/2+1,r);
	tree[node]=tree[node*2]+tree[node*2+1];
}
 
 
void update(int node,int l,int r,int i,int j)
{
	if(j<l || i>r || l>r) return;
 
	if(tree[node]==r-l+1)
		return;
	
	if(l==r)
	{
		tree[node]=sqrt(tree[node]);
		return;
	}
 
	update(node*2,l,(l+r)/2,i,j);
	update(node*2+1,(l+r)/2+1,r,i,j);
 
	tree[node]=tree[node*2]+tree[node*2+1];
}
 
 
long long query(int node,int l,int r,int i,int j)
{
	if(j<l || i>r || l>r) return 0;
 
	if(i<=l && j>=r)
		return tree[node];
 
	long long q1=query(node*2,l,(l+r)/2,i,j);
	long long q2=query(node*2+1,(l+r)/2+1,r,i,j);
	return q1+q2;
}
 
 
int main()
{
	int n,m,i,j,ch,l,r,k=1;
	while(scanf("%d",&n)!=EOF)
	{
		printf("Case #%d:\n",k);
		++k;
		for(i=1;i<=n;++i)
			scanf("%lld",&ar[i]);
 
		build(1,1,n);
 
		scanf("%d",&m);
 
		while(m>0)
		{
			scanf("%d %d %d",&ch,&l,&r);
 
			if(l>r)
			{
				swap(l,r);
			}
 
			if(ch==0)
			{
				update(1,1,n,l,r);
			}
			else
			{
				printf("%lld\n",query(1,1,n,l,r));
			}
			--m;
		}
	}
	return 0;
} 