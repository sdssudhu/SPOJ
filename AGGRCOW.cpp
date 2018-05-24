//Aggressive Cows -- SPOJ

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main() {
    long long t,n,c,i,j,maxi,l,r,mid;
    vector <long long >::iterator pos1,pos;
    cin>>t;
    while(t>0)
    {
        cin>>n>>c;
        vector <long long>x;
        for(i=0;i<n;++i)
        {
            cin>>l;
            x.push_back(l);
        }
        sort(x.begin(),x.end());
        maxi=0;
        l=1;r=x[n-1];
        while(l<=r)
        {
        mid=(l+r)/2;
        i=1;
        pos=x.begin();
        while(i<c)
        {
            if(*pos+mid<=x[n-1])
            {
            pos1=lower_bound(x.begin(),x.end(),*pos+mid);
            if(pos1!=x.end() && *pos1<=x[n-1])
            {
                pos=pos1;
                i=i+1;
            }
            else
            break;
            }
            else
            break;
        }
        if(i>=c)
        {
        maxi=max(maxi,mid);
        l=mid+1;
        }
        else
        r=mid-1;
        }
        cout<<maxi<<endl;
        --t;
    }
	return 0;
}