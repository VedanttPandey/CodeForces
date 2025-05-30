#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int t;cin>>t;
    while(t--){
        ll n;cin>>n;
      //For vertical line x should be 0 , and for horizontal line y should be zero (N,S,E,W)...??
       
      //For (NE,SE,SW,NW) the distances should be equal of pairs to make a straight line..??
       
      //If i got X points that satisfy my condition then for morining star and for compass i can have (X-1)points for each so ans+=(2*(X-1))..??
       
        // map<int, vector<int>> direc;
        // map<int,map<int,int>> direc;
        map<ll,ll> direc1,direc2,direc3,direc4;
      //1->pos(hori),-1->neg(horizontal)
      //2->pos(vert),-2->neg(vert)
        ll ans=0;
      for(ll i=0;i<n;++i){
          ll x,y;cin>>x>>y;
        //   if(x==0)direc[1].push_back(y);
        //   if(y==0)direc[1].push_back(x);
        //   else{
        //     direc[2].push_back((x-y));
        //     direc[2].push_back((x+y));
        // direc[1][x]++;
        // direc[2][y]++;
        // direc[1][x+y]++;
        // direc[2][x-y]++;
        direc1[x]++;
        direc2[y]++;
        direc3[x+y]++;
        direc4[x-y]++;
      }
      for(auto &[l,r] : direc1){
        //   cout<<l<<" "<<r<<"\n";
          if(r>1)ans+=(r*(r-1));
      }
    //   cout<<"new"<<"\n";
      for(auto &[l,r] : direc2){
        //   cout<<l<<" "<<r<<"\n";
          if(r>1)ans+=(r*(r-1));
      }
    //   cout<<"new"<<"\n";
      for(auto &[l,r] : direc3){
        //   cout<<l<<" "<<r<<"\n";
          if(r>1)ans+=(r*(r-1));
      }
    //   cout<<"new"<<"\n";
      for(auto &[l,r] : direc4){
        //   cout<<l<<" "<<r<<"\n";
          if(r>1)ans+=(r*(r-1));
      }
        //  for(auto &p : direc){
        // vector<int> a = p.second;
        // cout << "Direction " << p.first << ": ";
        // for(int val : a){
        //     cout << val << " ";
        // }
        // cout << "\n";

    // for(auto &p : direc){
    //     vector<int> a = p.second;
    //     // cout << "Direction " << p.first << ": ";
    //     // for(int val : a){
    //     //     cout << val << " ";
    //     // }
    //     // cout << "\n";
    //     // ans+=((a.size()-1)*2);
    //     if(a.size()>1){
    //         ans+=(a.size());
    //     }
    // }
    // for (const auto& outer_pair : direc) {
    //     int outer_key = outer_pair.first;
    //     const map<int, int>& inner_map = outer_pair.second;

    //     cout << "Key " << outer_key << " -> ";
    //     for (const auto& inner_pair : inner_map) {
    //         cout << "(" << inner_pair.first << ", " << inner_pair.second << ") ";
    //     }
    //     cout << endl;
    // }
    cout<<ans<<"\n";
    }
}
