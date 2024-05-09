#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string str;
    cin >> str;
    int ans=0;
    for(int l=0;l<n;l++){
        int mx=0;
        int curr=0;
        for(int r=l;r<n;r++){
            if(str[r]=='F'){
                curr=0;
                ans+=mx;
            }
            else{
                curr++;
                mx=max(mx,curr);
                ans+=mx;
            }
        }
    }
    cout << ans << '\n';
}