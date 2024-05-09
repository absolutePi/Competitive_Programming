#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+1;
vector<int> adj[N];
vector<int> value(N);
int n;
int sum0,sum1,node0,node1;

void dfs(int node,int parent,int color){
    if(color==0){
        node0++;
        sum0+=value[node];
    }
    else if(color==1){
        node1++;
        sum1+=value[node];
    }
    for(auto i : adj[node]){
        if(i==parent){continue;}
        dfs(i,node,1-color);
    }
    return;
}

int main(){
    freopen("clocktree.in","r",stdin);
    freopen("clocktree.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);   
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> value[i];
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    dfs(0,-1,0);
    if(sum0%12==sum1%12){
        cout << n;
    }
    else if((sum0+1)%12==sum1%12){
        cout << node1;
    }
    else if((sum1+1)%12==sum0%12){
        cout << node0;
    }
    else{
        cout << '0';
    }
}