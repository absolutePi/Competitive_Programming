#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int l,n;
    cin >> l >> n;
    string ans,str,prevstr;
    bool found=false;
    for(int i=0;i<n;i++){
        cin >> str;
        if(i!=0&&!found){
            int cnt=0;
            for(int i=0;i<l;i++){
                if(str[i]!=prevstr[i])cnt++;
                if(cnt>2){
                    found=true;
                    ans=prevstr;
                    break;
                }
            }
        }
        prevstr=str;
    }
    if(!found)ans=str;
    cout << ans << '\n';
}   