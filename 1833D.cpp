#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &e : p) cin >> e;

    int r = 0;
    for (int i = 0; i < n; ++i) {
        if (p[min(n - 1, r + 1)] <= p[min(n - 1, i + 1)]) {
            r = i;
        }
    }

    vector<int> ans;
    for (int i = r + 1; i < n; ++i) ans.push_back(p[i]);
    ans.push_back(p[r]);

    bool done = false;
    for (int i = r - 1; i >= 0; --i) {
        if (p[i] > p[0]) {
            ans.push_back(p[i]);
        } else {
            for (int j = 0; j <= i; ++j) {
                ans.push_back(p[j]);
            }
            done = true;
            break;
        }
    }

    if (!done) {
        for (int i = r - 1; i >= 0; --i) {
            ans.push_back(p[i]);
        }
    }

    for (auto e : ans) cout << e << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
