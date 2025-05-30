#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
	int t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        string s;cin>>s;
        vector<ll> a(n);
        int idx=-1;
        for(auto &i:a)cin>>i;
        ll maxS = LLONG_MIN, curr = 0;
        for (int i = 0; i < n; ++i) {
            if(a[i]==0 && s[i]=='0'){a[i]=-1e7;idx=i;}
            curr += a[i];
            maxS = max(maxS, curr);
            curr = max(curr, 0LL);
        }
        //If maxS is less than k ,then just put the diff 
        if(maxS==k){
            cout<<"YES"<<"\n";
            for(int i=0;i<n;++i){
                cout<<a[i]<<" ";
            }
            cout<<"\n";
            continue;
        }
        if(maxS>k || (idx==-1 && maxS!=k)){
            cout<<"NO"<<"\n";
            continue;
        }
        
        //Now if the maxS<k ,then what..??
        //Now i just to have to set one place and balance left and right side such that my max subArray sum in on ith index
        //idx is that pos
        
        ll sumLeft = LLONG_MIN, sum = 0;
        // if(idx-1>=1){
            for (ll i = idx - 1; i >= 0; --i) {
                sum += a[i];
                sumLeft = max(sumLeft, sum);
            }
        // }
        if (sumLeft < 0) sumLeft = 0;
 
        ll sumRight =LLONG_MIN;
        sum = 0;
        // if(idx+1<=(n-1)){
            for (ll i = idx + 1; i < n; ++i) {
                sum += a[i];
                sumRight = max(sumRight, sum);
            }
        // }
        if (sumRight < 0) sumRight = 0;
        // cout<<idx<<" "<<sumRight<<" "<<sumLeft<<"\n";
        a[idx]=k-(sumRight+sumLeft);
        cout<<"YES"<<"\n";
        for(int i=0;i<n;++i){
            cout<< a[i] <<" ";
        }
        cout<<"\n";
    }
}
