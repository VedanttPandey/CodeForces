#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> a(n);
        for(auto &i:a)cin>>i;
        sort(a.begin(),a.end());
        ll sum=1;
        int ok=1;
        if(a[0]!=1)ok=0;
        for(ll i=1;i<n;++i){
            if(a[i]<=sum)sum+=a[i];
            else {
                ok=0;break;
            }
        }
        
        cout << (ok ? "YES" : "NO")<<"\n";
    }
}
