#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> v;
    while(n--){
        int x;
        cin >> x;
        int l=0,r=v.size(),mid;
        while(l!=r){
            mid = l+(r-l)/2;
            if(v[mid].back()<x)r=mid;
            else l=mid+1;
        }
        if(l==v.size())v.push_back({x});
        else v[l].push_back(x);
    }
    for(auto i : v){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << endl;
    }
}