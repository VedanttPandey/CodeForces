#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<ll, ll>> pairs(n);
        for(int i = 0; i < n; ++i) cin >> pairs[i].first;  
        for(int i = 0; i < n; ++i) cin >> pairs[i].second; 

        int chnc = 1;

        for(int i = 0; i < n; ++i) {
            
            sort(pairs.begin(), pairs.end(), [](const pair<ll, ll>& x, const pair<ll, ll>& y) {
                return (x.first + x.second) > (y.first + y.second);
            });

            if(chnc & 1) { // Alice's turn
                for(int k = 0; k < n; ++k) {
                    if(pairs[k].first != 0 && pairs[k].second != 0) {
                        pairs[k].first--;   
                        pairs[k].second = 0; 
                        break;
                    }
                }
            } else { // Bob's turn
                for(int k = 0; k < n; ++k) {
                    if(pairs[k].first != 0 && pairs[k].second != 0) {
                        pairs[k].second--;   
                        pairs[k].first = 0;  
                        break;
                    }
                }
            }
            chnc++;
        }

        ll alice = 0, bob = 0;
        for(auto &[a, b] : pairs) {
            alice += a;
            bob += b;
        }
        cout << alice - bob << "\n";
    }
    return 0;
}