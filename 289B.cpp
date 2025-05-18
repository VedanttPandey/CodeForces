#include <bits/stdc++.h>
using namespace std;

int main() {
    int t=1;
    while(t--){
    int n,m,x;cin>>n>>m>>x;
    vector<vector<int>> a(n,vector<int> (m));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>a[i][j];
        }
    }
    vector<int> store;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            store.push_back(a[i][j]);
        }
    }
    int ok=1;
    sort(store.begin(),store.end());
    for(int i=1;i<store.size();++i){
        if((store[i]-store[i-1])%x!=0){
            ok=0;
            // continue;
            break;
        }
    }
    if(!ok){
        cout<<-1<<"\n";
        continue;
    }
    int target=store[store.size()/2];
    int ans=0;
    for(int i=0;i<store.size();++i){
        int need=abs(target-store[i]);
        ans+=(need/x);
    }
    cout<<ans<<"\n";
    }
}
