#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ll mini = 0;
        ll maxi = LLONG_MAX;
        for (int i = 0; i < n - 1; ++i) {
            ll f = a[i], s = a[i + 1];
            ll mid1 = (f + s) / 2;
            ll mid2 = (f + s + 1) / 2;

            if (f < s) {
                maxi = min(maxi, mid1); 
            } else if (f > s) {
                mini = max(mini, mid2); 
            }
        }
        cout << (mini <= maxi ? mini : -1) << "\n";
    }
}
