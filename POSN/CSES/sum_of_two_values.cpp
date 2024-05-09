#include <bits/stdc++.h>

using namespace std;

int main(){
    set<pair<int,int>> s1;
    int n,t;
    cin >> n >> t;
    if(n<=1){
        cout << "IMPOSSIBLE";
        return 0;
    }
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        s1.insert({x,i});
    }
    for(auto i : s1){
        s1.erase(i);
        if(s1.lower_bound({t-i.first,-1})->first==t-i.first){
            cout << i.second + 1 << " " << s1.lower_bound({t-i.first,-1})->second + 1;
            return 0;
        }
        s1.insert(i);
    }
    cout << "IMPOSSIBLE";
}