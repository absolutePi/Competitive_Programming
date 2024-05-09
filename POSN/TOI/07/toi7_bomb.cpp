#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first==b.first)return a.second>b.second;
    return a.first<b.first;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(auto &i : v){
        cin >> i.first >> i.second;
    }
    sort(v.begin(),v.end(),cmp);
    int mx=INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(v[i].second>=mx){
            mx=v[i].second;
            cout << v[i].first << ' ' << v[i].second << '\n';
        }
    }
}