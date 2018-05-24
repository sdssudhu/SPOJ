// Substring Problem

#include <bits/stdc++.h>
 
using namespace std;
 
int *generatePsArray(string &pattern) {
	int *psa = new int[pattern.length()];
	for(int i = 1, j = 0; i < pattern.length(); ++i) {
		if(pattern[i] == pattern[j]) {
			psa[i] = j + 1;
			++i; ++j;
		}
		else if(j != 0)
			j = psa[j - 1];
		else {
			psa[i] = 0;
			++i;
		}
	}
 
	return psa;
}
 
bool search(string &text,string &pattern) {
	int *psa = generatePsArray(pattern);
	int i, j;
	for(i = 0, j = 0; i < text.length() && j < pattern.length();) {
		if(text[i] == pattern[j]) {
			++i; ++j;
		}
		else if(j != 0)
			j = psa[j - 1];
		else ++i;
	}
 
	delete[] psa;
 
	return j == pattern.length();
}
 
int main() {
	int n;
	string text;
	cin>>text>>n;
	for(int i = 0; i < n; ++i) {
		string pattern;
		cin>>pattern;
		if(search(text, pattern))
		cout<<"Y"<<endl;
		else
		cout<<"N"<<endl;
	}
 
	return 0;
} 