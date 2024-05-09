#include <bits/stdc++.h>

using namespace std;

const int N = 4e4+5;
int U[N],D[N],R[N],L[N];
vector<tuple<int,int,int>> ans;
queue<tuple<int,int,int>> q;
bool vis[N];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<N;i++){
        U[i]=-1;
        D[i]=-1;
        R[i]=-1;
        L[i]=-1;
    }
    for(int i=1;i<n*m;i++){
        int u,v;
        char op;
        cin >> u >> op >> v;
        if(op=='U'){
            U[v]=u;
            D[u]=v;
        }
        else{
            L[v]=u;
            R[u]=v;
        }
    }
    q.push({0,0,0});//x y node
    while(!q.empty()){
        int x,y,node;
        tie(x,y,node)=q.front();
        q.pop();
        if(vis[node])continue;
        vis[node]=true;
        ans.push_back({x,y,node});
        if(U[node]!=-1)q.push({x-1,y,U[node]});
        if(D[node]!=-1)q.push({x+1,y,D[node]});
        if(R[node]!=-1)q.push({x,y+1,R[node]});
        if(L[node]!=-1)q.push({x,y-1,L[node]});
    }
    sort(ans.begin(),ans.end());
    int cnt=1;
    for(auto i : ans){
        int x,y,node;
        tie(x,y,node)=i;
        cout << node << ' ';
        if(cnt==m){
            cnt=0;
            cout << '\n';
        }
        cnt++;
    }
}   