#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
int n,q;
vector<pair<int,pair<int,int>>> edges;
vector<pair<pair<int,int>,int>> queries;
int par[N];
vector<int> sz(N,1);

int find(int x){
    if(par[x]!=x){
        return par[x]=find(par[x]);
    }
    else return x;
}

void unite(int x,int y){
    int a=find(x);
    int b=find(y);
    if(a==b){return;}
    if(sz[a]<sz[b])swap(a,b);
    sz[a]+=sz[b];
    par[b]=a;
    return;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("mootube.in","r",stdin);
    freopen("mootube.out","w",stdout);
    cin >> n >> q;
    for(int i=0;i<n;i++){
        par[i]=i;
    }
    for(int i=0;i<n-1;i++){
        int a,b,w;
        cin >> a >> b >> w;
        a--;b--;
        edges.push_back({w,{a,b}});
    }
    for(int i=0;i<q;i++){
        int k,v;
        cin >> k >> v;
        v--;
        queries.push_back({{k,v},i});
    }
    sort(edges.begin(),edges.end(),greater<pair<int,pair<int,int>>>());
    sort(queries.begin(),queries.end(),greater<pair<pair<int,int>,int>>());
    int ind=0;
    vector<int> ans(q);
    for(auto query : queries){
        int curr_k = query.first.first;
        int node = query.first.second;
        while(ind<(int)edges.size() && edges[ind].first>=curr_k){
            unite(edges[ind].second.first,edges[ind].second.second);
            ind++;
        }
        ans[query.second]=sz[find(node)]-1;
    }
    for(auto i : ans){
        cout << i << '\n';
    }
}   