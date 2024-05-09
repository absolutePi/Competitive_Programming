#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> time(n);
    while(n--){
        int s,e;
        cin >> s >> e;
        time.emplace_back(s,1);
        time.emplace_back(e,-1);
    }
    sort(time.begin(),time.end());
    int curr = 0, mx = 0;
    for(auto i : time){
        curr+=i.second;
        mx = max(mx,curr);
    }
    cout << mx;
}