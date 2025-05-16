#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
        cin >> s;
        int m;
        cin >> m;
        string l, r;
        cin >> l >> r;

        map<char, set<int>> pos;
        for (int i = 0; i < s.size(); ++i) {
            pos[s[i]].insert(i);
        }

        int maxi = -1;
        for (int i = 0; i < m; ++i) {
            int curr = -1;
            for (char j = l[i]; j <= r[i]; ++j) {
                // Now i have found the character of my range
                // Now i just have to get the upper bound (here upper bound represents the next greater index of the current char)
                // if it doesnt exist than we can just break from the loop else what..?
                auto it = pos[j].upper_bound(maxi);
                if (it == pos[j].end()) {
                    cout<<"YES"<<"\n";
                    return;
                }
                if (*it > curr) curr = *it;
            }
            maxi = curr;
        }
       cout<<"NO"<<"\n";
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

   