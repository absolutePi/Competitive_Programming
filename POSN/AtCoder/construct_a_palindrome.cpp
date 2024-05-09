#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,char>>> adj(n);
    for(int i=0;i<m;i++){
        int a,b;
        char c;
        cin >> a >> b >> c;
        adj[--a].push_back({--b,c});
        adj[b].push_back({a,c});
    }
    queue<pair<int,int>> q;
    vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
    for(int i=0;i<n;i++){
        dist[i][i]=0;
        q.push({i,i});
        for(const auto &[n,_] : adj[i]){
            if(dist[i][n]==INT_MAX){
                dist[i][n]=dist[n][i]=1;
                q.push({i,n});
            }
        }
    }
    bool pos=false;
    while(!q.empty()){
        int curr1,curr2;
        tie(curr1,curr2)=q.front();
        q.pop();
        if((curr1==0&&curr2==n-1)||(curr2==0&&curr1==n-1)){
            pos = true;
            break;
        }
        int new_dist=dist[curr1][curr2]+2;
        for(const auto &[n1,c1] : adj[curr1]){
            for(const auto &[n2,c2] : adj[curr2]){
                if(c1==c2 && new_dist<dist[n1][n2]){
                    dist[n1][n2]=dist[n2][n1]=new_dist;
                    q.push({n1,n2});
                }
            }
        }
    }
    cout << (pos ? dist[0][n-1] : -1) << '\n';
}   