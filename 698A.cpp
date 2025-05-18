#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    vector<vector<int>> dp(n, vector<int>(2, 0));
    int restD = 0; // rest ka counter
    // just have to see previous day contest ya gym
    if(a[0] == 1){
        dp[0][0] = 1; // contest de dia bhai n
    }
    if(a[0] == 2){
        dp[0][1] = 1; // bhai gym chla gya
    }
    if(a[0] == 3){
        dp[0][0] = 1;
        dp[0][1] = 1; // bhai all rounder h meri trh
    }
    if(a[0] == 0){
        // restD++; // pehla din rest h bhai
        dp[0][0] = 0; dp[0][1] = 0;
    }
    for(int i=1; i<n; ++i){
        dp[i][0] = 0;
        dp[i][1] = 0;

        if(a[i] == 1){ // contest
            if(dp[i-1][1] == 1){ // previous day gym
                dp[i][0] = 1;   // contest today
            }
            else if(dp[i-1][0] == 0 && dp[i-1][1] == 0){
                dp[i][0] = 1;   // can do contest if rested previous day
            }
        }
        if(a[i] == 2){ // gym
            if(dp[i-1][0] == 1){ // previous day contest
                dp[i][1] = 1;  // gym today
            }
            else if(dp[i-1][0] == 0 && dp[i-1][1] == 0){
                dp[i][1] = 1;  
            }
        }
        if(a[i] == 3){
            if(!dp[i-1][0] && !dp[i-1][1]){ 
                dp[i][0] = 1;
                dp[i][1] = 1;
            }
            else if(dp[i-1][0] == 1 && dp[i-1][1] == 0){
                dp[i][1] = 1;
            }
            else if(dp[i-1][0] == 0 && dp[i-1][1] == 1){
                dp[i][0] = 1;
            }
            else{
                dp[i][0] = 1;
                dp[i][1] = 1;
            }
        }
        if(a[i] == 0){
            dp[i][0] = 0;
            dp[i][1] = 0;
        }
    }
    for(int i=0; i<n; ++i){
        restD += (!dp[i][0] && !dp[i][1]); // count rest days where no contest or gym
    }
    cout << restD << "\n"; 
}
