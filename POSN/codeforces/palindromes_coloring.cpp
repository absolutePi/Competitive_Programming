#include <bits/stdc++.h>
using namespace std;
void solve(){
    int ans;
    int n, k;
    cin>>n>>k;
    string s;cin>>s;
    map<char,int> letterCnt;
    for(auto i : s){
        letterCnt[i]++;
    }
    int numPairs=0;
    int numLeftOver=0;
    for(auto [k,v] : letterCnt){
       numLeftOver+=(v%2);
       numPairs+=(v/2);
    }
    ans=(numPairs/k)*2;
    numLeftOver+=2*(numPairs%k);
    cout<< ((numLeftOver>=k) ? ans+1 : ans) << endl;
}

int main(){
    int t; cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
}