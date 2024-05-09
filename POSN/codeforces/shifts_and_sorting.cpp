#include <bits/stdc++.h>

using namespace std;

void solve(){
    string str;
    cin >> str;
    int ones=0,n=str.length(),ans=0;
    for(int i=0;i<n;i++){
        if(ones&&str[i]=='0'){
            ans+=ones+1;
        }
        else if(str[i]=='1')ones++;
    }
    cout << ans << '\n';
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
}