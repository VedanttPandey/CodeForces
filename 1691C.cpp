#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        string s;cin>>s;
        vector<int> ones;
        for(int i=0;i<n;++i){
            if(s[i]=='1')ones.push_back(i);
        }
        //the best min string will always be the string where 0th and n-1th pos are occupied with 1 ,rest all doest matter
        
        if(ones.size()==0){
            cout<<0<<"\n";
            continue;
        }
        if (s[n - 1] != '1') {
            int idx = -1;
            for (int i = ones.size() - 1; i >= 0; --i) {
                int cost = n - 1 - ones[i];
                if (cost <= k) {
                    idx = ones[i];
                    k -= cost;
                    swap(s[idx], s[n - 1]);
                    break;
                }
            }
        }

        
        if (s[0] != '1') {
            for (int i = 0; i < ones.size(); ++i) {
                if (s[ones[i]] == '1' && ones[i] != n - 1) {   
                    int cost = ones[i];
                    if (cost <= k) {
                        swap(s[0], s[ones[i]]);
                        break;
                    }
                }
            }
        }

        ll ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            int val = (s[i] - '0') * 10 + (s[i + 1] - '0');
            ans += val;
        }

        cout << ans << "\n";
    }
}
