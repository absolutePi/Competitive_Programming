#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("lasers.in","r",stdin);
    freopen("lasers.out","w",stdout);
    int n;
    cin >> n;
    vector<pair<int,int>> points(n+2);
    unordered_map<int,vector<int>> m[2];
    for(int i=0;i<n+2;i++){
        cin >> points[i].first >> points[i].second;
        m[0][points[i].first].push_back(i);
        m[1][points[i].second].push_back(i);
    }
    queue<pair<int,int>> q;
    vector<int> dist(n+2,INT_MAX);
    q.push({0,0});
    q.push({0,1});//index,dir  dir=0 vir //dir=1 hor
    dist[0]=0;
    while(!q.empty()){
        int curr=q.front().first;
        int from=q.front().second;
        q.pop();
        int dir=(from==1) ? 0 : 1;
        int coord = (dir==1) ? points[curr].second : points[curr].first;
        for(auto next : m[dir][coord]){
            if(dist[next]==INT_MAX){
                dist[next]=dist[curr]+1;
                q.push({next,dir});
            }
        }
    }
    if(dist[1]==INT_MAX){
        cout << "-1" << '\n';
    }
    else{
        cout << dist[1]-1 << '\n';
    }
}   