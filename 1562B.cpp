#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        bool ok = false;
        for (int b = 0; b * 111 <= x; b++) {
            if ((x - b * 111) % 11 == 0) {
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
