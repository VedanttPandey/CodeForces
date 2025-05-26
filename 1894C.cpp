#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;cin>>t; 
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> a(n);
        for(auto &i:a)cin>>i;
        if(a.back()>n){
            cout<<"NO"<<"\n";
            continue;
        }
        k=min(k,n);
        int curr=n-1,ok=1;
        while(k--){
            if(a[curr]>n){
                ok=0;
                break;
            }
            curr+=(n-(a[curr]));
            if(curr>=n)curr-=n;
        }
        cout << (ok ? "YES" : "NO")<<"\n";
    }
}
