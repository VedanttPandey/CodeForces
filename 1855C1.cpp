#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;cin>>t;
    while(t--){
        int n;cin>>n;
        bool allP=true,allN=true,allZ=true;
        vector<int> a(n);
        for(auto &i:a){
            cin>>i;
            if(i>0){allZ=false;allN=false;}
            if(i<0){allP=false;allZ=false;}
        }
        vector<pair<int,int>> op;
        if(allZ){
            cout<<0<<"\n";
            continue;
        }
        if(n==1){
            cout<<0<<"\n";
            continue;
        }
        if(allP){
            cout<<n-1<<"\n";
            cout<<2<<" "<<1<<"\n";
            int csum=a[0];
            for(int i=3;i<=n;++i){
                cout<<i<<" "<<i-1<<"\n";
            }
            cout<<"\n";
        }
        else if(allN){
            cout<<n-1<<"\n";
            // cout<<n<<" "<<n-1<<"\n";
            int csum=a[n-1];
            for(int i=n;i>=2;--i){
                cout<<i-1<<" "<<i<<"\n";
            }
            cout<<"\n";
        }
        else if(!allN && !allP){
            int maxi=INT_MIN,idx=-1;
            for(int i=0;i<n;++i){
                if(a[i]>maxi){
                    maxi=a[i];
                    idx=i;
                }
            }
            int cnt=0;
            while(maxi<20){
                maxi+=maxi;
                cnt++;
                // cout<<idx+1<<" "<<idx+1<<" ";
                op.push_back({idx+1,idx+1});
            }
            for(int i=0;i<n;++i){
                if(a[i]<0){
                    cnt++;
                    // cout<<i+1<<" "<<idx+1<<" ";
                    op.push_back({i+1,idx+1});
                }
            }
            // cout<<2<<" "<<1<<" ";
            op.push_back({2,1});
            int csum=a[0];
            for(int i=3;i<=n;++i){
                // cout<<i<<" "<<i-1<<" ";
                op.push_back({i,i-1});
            }
            // cout<<"\n";
            cout<<op.size()<<"\n";
            for(auto &[l,r] : op){
                cout<<l<<" "<<r<<"\n";
            }
        }
    }
}