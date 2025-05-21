#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;cin>>t;   
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        map<int,int> mp;
        for(auto &i:a){cin>>i;mp[i]++;}
        // if(mp.size()==1){
        //     cout<<1<<"\n";
        //     continue;
        // }
        int ans1=0,ans2=0;
        int chnc=1;
        for(auto &[l,r] : mp){
            if(r==1){
                if(chnc&1){
                    ans1++;
                    chnc++;
                }
                else if(chnc%2==0){
                    ans2++;
                    chnc++;
                }
            }
            else{
                if(ans1>ans2){
                    ans1++;
                    ans2++;
                }
                else if(ans1<ans2){
                   ans1++;
                    ans2++;
                }
                else{
                    ans1++;
                    ans2++;
                }
            }
        }
        cout << max(ans1,ans2)<<"\n";
    }
}
