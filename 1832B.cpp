#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (auto &i : a) cin >> i;
        sort(a.begin(), a.end());

        vector<ll> psum(n);
        psum[0] = a[0];
        for (int i = 1; i < n; ++i) {
            psum[i] = psum[i - 1] + a[i];
        }

        ll ans = 0;

        for (ll ops = 0; ops <= k; ++ops) {
            ll l = 2 * ops;
            ll r = n - (k - ops) - 1;

            if (l > r) break

            ll sum = psum[r];
            if (l > 0) sum -= psum[l - 1];

            ans = max(ans, sum);
        }

        cout << ans << "\n";
    }
    return 0;
}
