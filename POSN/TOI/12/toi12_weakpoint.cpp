#include <bits/stdc++.h>

using namespace std;

const int N =5e5+5;

int n,center;
vector<int> adj[N];
bool vis[N];
int value[N];

int dfs(int node){
    vis[node]=true;
    bool check=false;
    int sum=1;
    int val;
    for(auto nx : adj[node]){
        if(nx==center){check=true;}
        if(vis[nx]){continue;}
        else{
            val=dfs(nx);
            if(val==0){check=true;}
            sum+=val;
        }
    }
    value[node]=sum;
    if(check)return 0;
    return value[node];
}

int main(){
    cin >> n >> center;
    center--;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    dfs(center);
    int ans=INT_MIN,pos;
    for(int i=0;i<n;i++){
        if(value[i]-1>ans){
            ans=value[i]-1;
            pos=i;
        }
    }
    cout << pos+1 << '\n' << ans;
}