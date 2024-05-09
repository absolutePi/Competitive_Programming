#include <bits/stdc++.h>

using namespace std;

int n,m;
const int N = 2e5+5;
vector<int> adj[N];
bool opened[N];
int par[N];

int find(int x){
    if(par[x]!=x){return par[x]=find(par[x]);}
    else return x;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("closing.in","r",stdin);
    freopen("closing.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        par[i]=i;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    vector<int> order(n);
    for(int i=0;i<n;i++){
        cin >> order[i];
        order[i]--;
    }
    reverse(order.begin(),order.end());
    int comp=0;
    vector<bool> ans;
    for(int i=0;i<n;i++){
        int curr=order[i];
        comp++;
        opened[curr]=true;
        for(auto j : adj[curr]){
            if(opened[j]&&find(curr)!=find(j)){
                comp--;
                par[find(curr)]=find(j);
            }
        }
        ans.push_back((comp==1));
    }
    reverse(ans.begin(),ans.end());
    for(auto i : ans){
        cout << (i ? "YES" : "NO") << '\n';
    }
}