#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> a(n);for(auto &i:a)cin>>i;
        
        ll rel=0;
        for(int i=1;i<n;++i){
            rel+=(abs(a[i]-a[i-1]));
        }
        
        ll maxi=max(abs(a[1]-a[0]),abs(a[n-1]-a[n-2]));
        for(int i=1;i<n-1;++i){
            maxi=max(maxi,abs(a[i]-a[i-1]) + abs(a[i+1]-a[i]) - (abs(a[i-1]-a[i+1])));
        }
        cout << abs(maxi-rel)<<"\n";
    }
}
