#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define endl '\n'

void solve(){

    int n;
    cin >> n;

    vector<int>a(n);
    for( auto & e : a )
        cin >> e;

    sort( a.begin(), a.end() );
    int ans=0;
    for(int i=0;i<n-1;++i){
        ans=max(ans,a[n-1]-a[i]+a[i+1]-a[i]);
    }
    for(int i=n-1;i>=1;--i){
        ans=max(ans,a[i]-a[0] + a[i]-a[i-1]);
    }
    cout<<ans<<"\n";
}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;

}