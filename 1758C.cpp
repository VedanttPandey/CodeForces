#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;cin>>t;
    while(t--){
        int n,x;cin>>n>>x;
        if(n%x!=0){
            cout<<-1<<"\n";
            continue;
        }
        vector<int> a(n+1,-1);
        a[1]=x;a[n]=1;
        if(n==x){
            for(int i=1;i<=n;++i){
            cout << (a[i] == -1 ? i : a[i])<<" ";
        }
        continue;
        }
        int curr=x*2;
        for(int i=x*2;i<=n;i+=x){
            if(n%i==0){
                a[x]=i;
                x=i;
            }
            //  x=i;
        }
        for(int i=1;i<=n;++i){
            cout << (a[i] == -1 ? i : a[i])<<" ";
        }
        cout<<"\n";
    }
}
