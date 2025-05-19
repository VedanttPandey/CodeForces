#include <bits/stdc++.h>
using namespace std;

int main() {
   

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;

        vector<int> mini(n), maxi(n);

        
        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(b.begin(), b.end(), a[i]);
            mini[i] = (*it) - a[i];
        }

       
        int k = n - 1;
        for (int p = n - 1; p >= 0; p--) {
            int idx = lower_bound(b.begin(), b.begin() + k + 1, a[p]) - b.begin();
            maxi[p] = b[k] - a[p];
            if ((k - p) == (k - idx)) {
                k = idx - 1;
            }
        }

        for (auto &x : mini) cout << x << " ";
        cout << "\n";
        for (auto &x : maxi) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
