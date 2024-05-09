#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+1;
vector<int> adj[N];
int firstmax[N];
int secondmax[N];
int c[N];

void dfs(int v,int p){
    firstmax[v]=0;
    secondmax[v]=0;
    for(auto x : adj[v]){
        if(x==p){continue;}
        dfs(x,v);
        if(firstmax[x]+1>firstmax[v]){
            secondmax[v]=firstmax[v];
            firstmax[v]=firstmax[x]+1;
            c[v]=x;
        }
        else if(secondmax[v]<firstmax[x]+1){
            secondmax[v]=firstmax[x]+1;
        }
    }
    return;
}

void dfs2(int v,int p){
    for(auto x : adj[v]){
        if(x==p){continue;}
        if(x==c[v]){
            if(firstmax[x]<secondmax[v]+1){
                secondmax[x]=firstmax[x];
                firstmax[x]=secondmax[v]+1;
                c[x]=v;
            }
            else{
                secondmax[x]=max(secondmax[x],secondmax[v]+1);
            }
        }
        else{
            secondmax[x]=firstmax[x];
            firstmax[x]=firstmax[v]+1;
            c[x]=v;
        }
        dfs2(x,v);
    }
    return;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,a,b;
    cin >> n;
    for(int i=0;i<n-1;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    dfs2(1,-1);
    for(int i=1;i<=n;i++){
        cout << firstmax[i] << ' ';
    }
}