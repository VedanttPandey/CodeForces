#include <bits/stdc++.h>
using namespace std;

bool isP(vector<int> &a){
    int l=0,r=a.size()-1;
    while(l<=r){
        if(a[l]!=a[r]){
            return false;
        }
        l++;r--;
    }
    return true;
}
int main() {
	int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(auto &i:a)cin>>i;
        if(n<=2 || isP(a)){
            cout<<"YES"<<"\n";
            continue;
        }
        int l=0,r=n-1,f=0,s=0;
        while(l<=r){
            if(a[l]!=a[r]){
                f=a[l],s=a[r];
                break;
            }
            l++;r--;
        }
        vector<int> a1,a2;
        for(int i=0;i<n;++i){
            if(a[i]!=f)a1.push_back(a[i]);
            if(a[i]!=s)a2.push_back(a[i]);
        }
        
        if(isP(a1) || isP(a2)){
            cout<<"YES"<<"\n";
        }
        else cout<<"NO"<<"\n";
    }
}
