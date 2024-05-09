#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> pos(n+1);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        pos[x]=i;
    }
    int l=(n+1)/2,r=(n+2)/2;
    while(l>0 && ((pos[l]<pos[l+1]&&pos[r]>pos[r-1])||l==r)){
        l--;
        r++;
    }
    cout << (n-(r-l-1))/2 << '\n';
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        solve();
    }
}