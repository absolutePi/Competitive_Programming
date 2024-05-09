#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i : v){
        cin >> i;
    }
    set<int> s;
    int l=0,r=0;
    int ans=0;
    while(r<n){
        if(s.count(v[r])){
            while(v[l]!=v[r]){
                s.erase(s.find(v[l]));
                l++;
            }
            l++;
            r++;
        }
        else{
            s.insert(v[r]);
            r++;
        }
        ans=max(ans,(int)(s.size()));
    }   
    cout << ans << '\n';
}