#include <bits/stdc++.h>

using namespace std;

vector<bool> visited;
vector<vector<bool>> connected;
int n,ans=INT_MIN;

int dfs(int node){
    visited[node]=true;
    int reached=1;
    for(int i=0;i<n;i++){
        if(!visited[i]&&connected[node][i]){
            visited[i]=true;
            reached+=dfs(i);
        }
    }
    return reached;
}

int main(){
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n;
    vector<int> x(n),y(n);
    vector<int> power(n);
    connected=vector<vector<bool>>(n,vector<bool>(n));
    visited=vector<bool>(n);
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i] >> power[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int dist=(x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
            connected[i][j]=dist<=power[i]*power[i];
        }
    }
    for(int i=0;i<n;i++){
        visited.assign(n,false);
        ans=max(ans,dfs(i));
    }
    cout << ans;
}