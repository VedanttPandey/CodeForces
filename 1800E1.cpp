#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        string s,t;cin>>s>>t;
        //if n>=6 then i just have to count the nmber of char in both the strings and they should be equal
        
        map<ll,ll> mp1,mp2;
        for(auto &i:s)mp1[i]++;
        for(auto &i:t)mp2[i]++;
        int ok=1;
        if(mp1.size()!=mp2.size())ok=0;
        for(auto &[l,r] : mp1){
            if(mp2[l]!=r){ok=0;break;}
        }
        if(n>=6 && !ok){
            cout<<"NO"<<"\n";
            continue;
        }
        if(n==1){
            if(s[0]!=t[0]){
                cout<<"NO"<<"\n";
                continue;
            }
        }
        if(n==2){
            if(s[0]!=t[0] || s[1]!=t[1]){
                cout<<"NO"<<"\n";
                continue;
            }
        }
        if(n==3){
             if(s[0]!=t[0] || s[1]!=t[1] || s[2]!=t[2]){
                cout<<"NO"<<"\n";
                continue;
            }
        }
        if(n == 4){
            multiset<char> s1 = {s[0], s[3]};
            multiset<char> t1 = {t[0], t[3]};
            if(s1 != t1 || s[1] != t[1] || s[2] != t[2]){
                cout << "NO\n";
                continue;
            }
    }

        if(n == 5){
            vector<int> group1 = {0, 1, 3, 4};
            vector<int> group2 = {2};
        
            multiset<char> s1, t1, s2, t2;
            for(int i : group1){
                s1.insert(s[i]);
                t1.insert(t[i]);
            }
            for(int i : group2){
                s2.insert(s[i]);
                t2.insert(t[i]);
            }
        
            if(s1 != t1 || s2 != t2){
                cout << "NO\n";
                continue;
            }
}

        cout<<"YES"<<"\n";
    }
}
/*
    1->4,5
    2->5
*/