#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<char> farms(n);
    vector<vector<int>> adj(n);
    for(auto &i : farms){cin >> i;}
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int component_num=0;
    vector<int> component(n,-1);
    for(int i=0;i<n;i++){
        if(component[i]!=-1){continue;}
        queue<int> q;
        q.push(i);
        char type=farms[i];
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            component[curr]=component_num;
            for(auto j : adj[curr]){
                if(component[j]==-1&&farms[j]==type){
                    q.push(j);
                }
            }
        }
        component_num++;
    }
    for(int i=0;i<m;i++){
        int a,b;
        char c;
        cin >> a >> b >> c;
        a--;b--;
        if(component[a]==component[b]){
            cout << (farms[a]==c);
        }
        else{
            cout << '1';
        }
    }
}