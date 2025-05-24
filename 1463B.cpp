#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<ll> a(n+1);
        for(ll i=1;i<=n;++i){
            cin>>a[i];
        }
        vector<ll> ans(n+1),ans1(n+1);
        ll sum1=accumulate(a.begin(),a.end(),0ll);
        ll diff1=0,diff2=0;
        for(int i=1;i<=n;++i){
            if(i&1){
                 ans[i]=a[i];
            }
            else ans[i]=1;
            diff1+=(a[i]-ans[i]);
        }
        for(int i=1;i<=n;++i){
            if(i%2==0){
                ans1[i]=a[i];
            }
            else ans1[i]=1;
            diff2+=(a[i]-ans1[i]);
        }
        if(diff1*<=sum1){
        for(int i=1;i<=n;++i){
            cout<<ans[i]<<" ";
        }
        }
        else{
            for(int i=1;i<=n;++i){
            cout<<ans1[i]<<" ";
        }
        }
        cout<<"\n";
    }
}
