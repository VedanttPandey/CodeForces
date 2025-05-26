#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> d(n), ans(n);
        for(int i = 0; i < n; i++) cin >> d[i];
        vector<pair<int,int>> pairs(n);
        for(int i = 0; i < n; i++){
            cin >> pairs[i].first >> pairs[i].second;
        }
        vector<int> mini(n), maxi(n);
        bool ok = true;
        int low, high;
        if(d[0] == 0){
            low = 0; high = 0;
        } else if(d[0] == 1){
            low = 1; high = 1;
        } else {
            low = 0; high = 1;
        }
        mini[0] = max(low, pairs[0].first);
        maxi[0] = min(high, pairs[0].second);
        if(mini[0] > maxi[0]) ok = false;
        for(int i = 1; i < n && ok; i++){
            if(d[i] == 0){
                low = mini[i-1];
                high = maxi[i-1];
            } else if(d[i] == 1){
                low = mini[i-1] + 1;
                high = maxi[i-1] + 1;
            } else {
                low = mini[i-1];
                high = maxi[i-1] + 1;
            }
            mini[i] = max(low, pairs[i].first);
            maxi[i] = min(high, pairs[i].second);
            if(mini[i] > maxi[i]) ok = false;
        }
        if(!ok){
            cout << -1 << "\n";
            continue;
        }
        int h = mini[n-1];
        for(int i = n-1; i >= 0; i--){
            if(d[i] == 0){
                ans[i] = 0;
            } else if(d[i] == 1){
                ans[i] = 1;
                h--;
            } else {
                if(i > 0 && h >= mini[i-1] && h <= maxi[i-1]){
                    ans[i] = 0;
                } else if(i == 0 && h == 0){
                    ans[i] = 0;
                } else {
                    ans[i] = 1;
                    h--;
                }
            }
        }
        for(int i = 0; i < n; i++){
            cout << ans[i] << (i+1==n?'\n':' ');
        }
    }
    return 0;
}
  