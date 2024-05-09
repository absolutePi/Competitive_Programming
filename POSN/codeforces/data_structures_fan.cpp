#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &i : arr){cin >> i;}
    string bits;
    cin >> bits;
    int X0=0,X1=0;
    for(int i=0;i<n;i++){
        if(bits[i]=='1'){
            X1^=arr[i];
        }
        else{
            X0^=arr[i];
        }
    }
    vector<int> prefix(n+1,0);
    for(int i=1;i<=n;i++){
        prefix[i] = prefix[i-1]^arr[i-1];//1-indexed
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int type;
        cin >> type;
        if(type==1){
            int l,r;
            cin >> l >> r;
            int mid = prefix[r]^prefix[l-1];
            X0^=mid;
            X1^=mid;
        }
        else if(type==2){
            int num;
            cin >> num;
            cout << ((num == 1) ? X1 : X0) << ' ';
        }
    }
    return;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
}