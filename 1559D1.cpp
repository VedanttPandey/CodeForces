#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int leader(int x) {
        if (parent[x] == x) return x;
        return parent[x] = leader(parent[x]);
    }
    bool areSame(int x, int y) {
        return leader(x) == leader(y);
    }
    bool merge(int x, int y) {
        int l1 = leader(x), l2 = leader(y);
        if (l1 == l2) return false;
        if (size[l1] < size[l2]) swap(l1, l2);
        parent[l2] = l1;
        size[l1] += size[l2];
        return true;
    }
};

int main() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    DSU mocha(n), diana(n);

    for (int i = 0; i < m1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        mocha.merge(u, v);
    }
    for (int i = 0; i < m2; i++) {
        int u, v; cin >> u >> v; u--; v--;
        diana.merge(u, v);
    }

    vector<pair<int,int>> answer;

   
    for (int u = 0; u < n; u++) {
        for (int v = u + 1; v < n; v++) {
            if (!mocha.areSame(u,v) && !diana.areSame(u,v)) {
                answer.emplace_back(u, v);
                mocha.merge(u, v);
                diana.merge(u, v);
            }
        }
    }

   
    cout << answer.size() << "\n";
    for (auto &e : answer) {
        cout << e.first + 1 << " " << e.second + 1 << "\n";
    }

    return 0;
}
