#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("maxcross.in","r",stdin);
    freopen("maxcross.out","w",stdout);
    int n,k,b;
    cin >> n >> k >> b;
    vector<int> v(n+1);
    for(int i=0;i<b;i++){
        int x;
        cin >> x;
        v[x]++;
    }
    for(int i=1;i<=n;i++){
        v[i]+=v[i-1];
    }
    int mn = INT_MAX;
    for(int i=1;i+k-1<=n;i++){
        mn = min(mn,v[i+k-1]-v[i-1]);
    }
    cout << mn;
}