#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+5;
int freq[N];

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &i : v){cin >> i;}
    int r=-1;
    int sz=0;
    int ans=-1,ansl,ansr;
    for(int l=0;l<n;l++){
        while(r+1<n&&sz+(freq[v[r+1]]==0)<=k){
            sz+=(freq[v[r+1]]==0);
            freq[v[r+1]]++;
            r++;
        }
        if(r-l+1>ans){
            ans=r-l+1;
            ansl=l;
            ansr=r;
        }
        freq[v[l]]--;
        sz-=(freq[v[l]]==0);
    }
    cout << ansl+1 << ' ' << ansr+1;
}