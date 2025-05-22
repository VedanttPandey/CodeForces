#include <bits/stdc++.h>
using namespace std;


bool isP(vector<int> &a,int mid){
    int i = 0;
    int n=a.size();
    while (i + 1 < a.size() && a[i + 1] - a[0] <= 2 * mid) {
        ++i;
    }
    int j = n - 1;
    while (j - 1 >= 0 && a.back() - a[j - 1] <= 2 * mid) {
        --j;
    }
    ++i; --j;
    return (i > j || a[j] - a[i] <= 2 * mid);
}
int bs(vector<int> &a){
    int l=-1,r=1000000009;
    int ans=-1;
    while(l<=r){
        int m=l+(r-l)/2;
        if(isP(a,m)){
            ans=m;
            r=m-1;
        }
        else l=m+1;
    }
    return ans;
}
void solve(){
    int n;cin>>n;
    vector<int> a(n);
    for(auto &i:a)cin>>i;
    if(n<=3){
        cout<<0<<"\n";
        return;
    }
    sort(a.begin(),a.end());
    cout<<bs(a)<<"\n";
}
int main() {
	int t;cin>>t;
    while(t--){
        solve();
    }
}
