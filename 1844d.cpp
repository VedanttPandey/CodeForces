#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int idx = -1;
        for (int i = 1; i <= n; ++i) {
            if (n % i != 0) {
                idx = i;
                break;
            }
        }

        vector<char> ans(n, '.');
        char c = 'a';
        for (int i = 0; i < n; ++i) {
            int start = i;
            while (start < n && ans[start] == '.') {
                ans[start] = c;
                start += idx;
            }
            c++;
        }

        for (auto &i : ans) {
            cout << i;
        }
        cout << "\n";
    }
}
