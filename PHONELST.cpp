// Phone List

#include <bits/stdc++.h>
using namespace std;
vector< string >v;
int main() {
	int t;
	cin>>t;
	while(t>0)
	{
	    v.clear();
	    string s;
	    int n,i;
	    cin>>n;
	    for(i=0;i<n;++i)
	    {
	        cin>>s;
	        v.push_back(s);
	    }
	    sort(v.begin(),v.end());
	    int flag=1;
	    for(i=1;i<n;++i)
	    {
	        flag=1;
	        for(int j=0;j<v[i-1].length();++j)
	        {
	            if(v[i-1][j]!=v[i][j])
	            {
	                flag=0;
	                break;
	            }
	        }
	        if(flag==1)
	        {
	            cout<<"NO"<<endl;
	            break;
	        }
	    }
	    if(flag==0)
	    cout<<"YES"<<endl;
	    --t;
	}
	return 0;
}