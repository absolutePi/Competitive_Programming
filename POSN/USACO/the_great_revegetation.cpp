#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,bool>>> adj;
vector<int> color;
bool impossible;

void dfs(int node,bool curr_color){
    color[node]=curr_color;
    for(auto i : adj[node]){
        bool type = i.second ? curr_color : !curr_color;
        //if the next node is not already visited
        if(color[i.first]==-1){
            dfs(i.first,type);
        }
        //else if the next node is already visited
        else{
            //if the type is not right
            if(color[i.first]==!type){
                impossible=true;
                return;
            }
        }
    }
    return;
}

int main(){
    freopen("revegetate.in","r",stdin);
    freopen("revegetate.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,m;
    cin >> n >> m;
    adj=vector<vector<pair<int,bool>>>(n);
    color=vector<int>(n,-1);
    for(int i=0;i<m;i++){
        char c;
        int a,b;
        cin >> c >> a >> b;
        adj[--a].push_back({--b,c=='S'});
        adj[b].push_back({a,c=='S'});
    }
    int components=0;
    for(int i=0;i<n;i++){
        //proceed if not visited
        if(color[i]==-1){
            components++;
            dfs(i,true);
            if(impossible)break;
        }
    }
    if(impossible){
        cout << "0" << endl;
    }
    else{
        cout << "1";
        for(int i=0;i<components;i++){
            cout << "0";
        }
        cout << endl;
    }
}