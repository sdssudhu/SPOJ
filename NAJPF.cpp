// Pattern Find

#include <bits/stdc++.h>
using namespace std;
const long long M=1e9+7;
 
int val[3001000];
 
//Modification of KMP from geeks for geeks --- http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/
 
void computeLPSArray(char *pat, int M, int *lps);
 
// Prints occurrences of txt[] in pat[]
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
 
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
 
    int i = 0;  // index for txt[]
    int j  = 0;  // index for pat[]
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
 
        if (j == M)
        {
            val[i-j]=1;
            j = lps[j-1];
        }
 
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
}
 
void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;
 
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar 
            // to search step.
            if (len != 0)
            {
                len = lps[len-1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
 
 
long long ans[3001000];
 
 
int main() {
	int t,n,i,mini,k;
	char s[3001000],f[3000100];
	long long answ;
	cin>>t;
	while(t>0)
	{
	    cin>>s>>f;
	    n=strlen(s);
	    k=strlen(f);
	    for(i=0;i<=n;++i)
	    ans[i]=0,val[i]=0;
	    KMPSearch(f,s);
	    int flag=0;
	    for(i=0;i<n;++i)
	    if(val[i]!=0)
	    {
	        ++flag;
	    }
	    if(flag==0)
	    cout<<"Not Found"<<endl;
	    else
	    {
	        cout<<flag<<endl;
	        for(i=0;i<n;++i)
	        if(val[i]==1)
	        cout<<i+1<<" ";
	        cout<<endl;
	    }
	    --t;
	}
	return 0;
}
 