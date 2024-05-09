#include <bits/stdc++.h>

using namespace std;

int N,M;
vector<int> adj[100005];
int color[100005];
bool impossible=false;

void op(int node,int cc){
    if(color[node]!=0){return;}
    color[node]=cc;
    int nc = (cc==1) ? 2 : 1;
    for(auto i : adj[node]){
        if(color[i]==0){
            op(i,nc);
        }
        else if(color[i]==cc){
            impossible=true;
            return;
        }
    }
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=N;i++){
        op(i,1);
    }
    if(impossible){cout << "IMPOSSIBLE";}
    else{
        for(int i=1;i<=N;i++){
            cout << color[i] << ' ';
        }
    }
}