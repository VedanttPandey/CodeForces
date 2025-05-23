#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

       if(n==2){
           if(s[0]!='0' && s[1]=='0'){
               cout<<s<<"\n";
               continue;
           }
           if(s[0]=='0'){
               cout<<s[1]<<"\n";
               continue;
           }
       }
    if(s=="101"){
        cout<<1<<"\n";
        continue;
    }
    if(n==3 && s[1]=='0'){
        int n1=s[0]-'0',n2=s[2]-'0';
        cout<<min(n1+n2,n1*n2)<<"\n";
        continue;
    }
        bool hasZero = false, hasOne = false,allOne=true;
       

        for (int i = 0; i < n ; ++i) {
            
            if (s[i] == '0') hasZero = true;
            if (s[i] == '1') hasOne = true;
            if(s[i]!='1')allOne=false;
        }

        if (hasZero) {
            cout << "0\n";
            continue;
        }
        if(allOne){
            cout<<11<<"\n";
            continue;
        }
       int ans = INT_MAX;
    for (int i = 0; i < n - 1; ++i) {
        string a = s.substr(i, 2);
        int curr = stoi(a);

        if (i - 1 >= 0) {
            int backSum = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (s[j] != '1') {
                    backSum += (s[j] - '0');
                }
            }
            curr += backSum;
        }

        if (i + 2 < n) {
            int frontSum = 0;
            for (int j = i + 2; j < n; ++j) {
                if (s[j] != '1') {
                    frontSum += (s[j] - '0');
                }
            }
            curr += frontSum;
        }

        ans = min(ans, curr);
    }
    cout<<ans<<"\n";
    }
}