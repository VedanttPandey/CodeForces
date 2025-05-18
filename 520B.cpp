#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;cin>>n>>m;
	if(n>m){
	    cout<<n-m<<"\n";
	}
	else{
	    int steps=0;
	    while(n<m){
	        if(m&1){m++;steps++;}
	        else {steps++;m/=2;}
	    }
	    cout<<steps+(n-m)<<"\n";
	}
}
