#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vector<int> a(n);
        for (auto &i : a) cin >> i;

        map<int, int> mp;
        for (auto &i : a) mp[i]++;

        
        if (mp.size() == 1) {
            cout << n << "\n";
            continue;
        }

       
        priority_queue<int> pq;
        for (auto &[val, freq] : mp) {
            pq.push(freq);
        }

        
        while (pq.size() >= 2) {
            int top1 = pq.top(); pq.pop();
            int top2 = pq.top(); pq.pop();
            top1--; top2--;
            if (top1 > 0) pq.push(top1);
            if (top2 > 0) pq.push(top2);
        }

       
        cout << (pq.empty() ? 0 : pq.top()) << "\n";
    }
}
