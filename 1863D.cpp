#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<char>> a(n, vector<char>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];

        bool ok = true;

        for (int i = 0; i < n; ++i) {
            int cntL = count(a[i].begin(), a[i].end(), 'L');
            int cntR = count(a[i].begin(), a[i].end(), 'R');
            int cntU = count(a[i].begin(), a[i].end(), 'U');
            int cntD = count(a[i].begin(), a[i].end(), 'D');

            if ((cntL % 2) != (cntR % 2) || (cntU % 2) != (cntD % 2)) {
                ok = false;
                break;
            }
        }

        if (ok) {
            for (int j = 0; j < m; ++j) {
                int cntL = 0, cntR = 0, cntU = 0, cntD = 0;
                for (int i = 0; i < n; ++i) {
                    if (a[i][j] == 'L') cntL++;
                    if (a[i][j] == 'R') cntR++;
                    if (a[i][j] == 'U') cntU++;
                    if (a[i][j] == 'D') cntD++;
                }

                if ((cntL % 2) != (cntR % 2) || (cntU % 2) != (cntD % 2)) {
                    ok = false;
                    break;
                }
            }
        }
        
        if(!ok){
            cout<<-1<<"\n";
            continue;
        }
        
          for(int i=0;i<n;i++){
        char prev = '#';
        for(int j=0;j<m;j++){
            if(a[i][j] == 'U'){
                if(prev == '#'){
                    a[i][j] = 'W';
                    a[i+1][j] = 'B';
                    prev = 'W';
                }else{
                    if(prev == 'W'){
                        a[i][j] = 'B';
                        a[i+1][j] = 'W';
                        prev = 'B';
                    }else{
                       a[i][j] = 'W';
                       a[i+1][j] = 'B';
                       prev = 'W';
                    }
                }
            }
        }
     }
 
    
    
    for(int i=0;i<m;i++){
        char prev = '#';
        for(int j=0;j<n;j++){
            if(a[j][i] == 'L'){
                if(prev == '#'){
                    a[j][i] = 'W';
                    a[j][i+1] = 'B';
                    prev = 'W';
                }else{
                    if(prev == 'W'){
                        a[j][i] = 'B';
                        a[j][i+1] = 'W';
                        prev = 'B';
                    }else{
                       a[j][i] = 'W';
                       a[j][i+1] = 'B';
                       prev = 'W';
                    }
                }
            }
        }
     }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cout<<a[i][j];
            }
            cout<<"\n";
        }
    }
}