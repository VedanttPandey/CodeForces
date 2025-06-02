#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
         int n,k;
         cin>>n>>k;
         
         int score = 0;
         int tot = 0;
         int c = 0;
         for(int i=0;i<n;++i){
            //what will be score if we make this value +Ve
            int cur_score  = score + c + 1;
            
            //If I have already generated k good subarray so I dont need any
            //more so I fill with -1000
            if(score == k){
                cout<<"-1000 ";
                continue;
            }
            
            //if making current value +ve add more than required no of 
            //good subarray
            if(cur_score>k){
                
                int req = k - score;
                int have = req-c;
                have*=2;
                have -= 1;
                
                //here we need make req no of subarrays good
                //of we need to make (c-req) subarray not good/bad or with -ve sum
                //so we need to add [-(2*(c-req)) - 1] 
                
                cout<<(have)<<" ";
                score = k;
                
            }
            else{
                //here there is no issue making current value +ve
                cout<<2<<" ";
                c++;
                score += c;
            }
         }
         cout<<"\n";
    }
}