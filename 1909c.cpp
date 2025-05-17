#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<ll> L(n), R(n), C(n);
        for (ll &x : L) cin >> x;
        for (ll &x : R) cin >> x;
        for (ll &x : C) cin >> x;

       
        sort(R.begin(), R.end());
        multiset<ll> msL(L.begin(), L.end());

        
        vector<ll> lengths;
        lengths.reserve(n);
        for (ll r : R) {
            
            auto it = msL.lower_bound(r);
            --it;  
            ll l = *it;
            lengths.push_back(r - l);
            msL.erase(it);
        }

        
        sort(lengths.begin(), lengths.end());
        sort(C.begin(), C.end(), greater<ll>());

        
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += lengths[i] * C[i];
        }

        cout << ans << "\n";
    }
    return 0;
}
