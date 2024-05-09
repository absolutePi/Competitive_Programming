#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("planting.in","r",stdin);
    freopen("planting.out","w",stdout);
    int n,mx=INT_MIN;
    cin >> n;
    vector<vector<int>> neighbor(n+1);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin >> x >> y;
        neighbor[x].push_back(y);
        neighbor[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        mx = max(mx,(int)neighbor[i].size());
    }
    cout << mx+1;
}