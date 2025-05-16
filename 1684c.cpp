#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];

        vector<int> indexes;
        for (int i = 0; i < n; ++i) {
            vector<int> sorted_row = a[i];
            sort(sorted_row.begin(), sorted_row.end());
            for (int j = 0; j < m; ++j) {
                if (a[i][j] != sorted_row[j]) {
                    indexes.push_back(j);
                }
            }
            if (!indexes.empty()) break;
        }

        sort(indexes.begin(), indexes.end());
        indexes.erase(unique(indexes.begin(), indexes.end()), indexes.end());

        if (indexes.size() == 0) {
            cout << "1 1\n";
        } else if (indexes.size() == 2) {
            int x = indexes[0], y = indexes[1];
            for (int i = 0; i < n; ++i) {
                swap(a[i][x], a[i][y]);
            }
            bool good = true;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m - 1; ++j) {
                    if (a[i][j] > a[i][j + 1]) {
                        good = false;
                        break;
                    }
                }
                if (!good) break;
            }
            if (good) {
                cout << x + 1 << " " << y + 1 << "\n";
            } else {
                cout << "-1\n";
            }
        } else {
            cout << "-1\n";
        }
    }
}
