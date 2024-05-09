#include <bits/stdc++.h>

using namespace std;

const int N = 10;
bool forbid[N];
bool vis[N];
int n,m;
vector<vector<int>> ans;

void recur(vector<int> v){
    if(v.size()==n){
        ans.push_back(v);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=true;
            v.push_back(i);
            recur(v);
            vis[i]=false;
            v.pop_back();
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        forbid[x]=true;
    }
    for(int i=1;i<=n;i++){
        if(!forbid[i]){
            vis[i]=true;
            recur({i});
            vis[i]=false;
        }
    }
    for(auto i : ans){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << '\n';
    }
}   