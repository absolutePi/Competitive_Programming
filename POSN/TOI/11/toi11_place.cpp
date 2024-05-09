#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;
int par[N];
#define ll long long

struct Edge{
    int u,v;
    ll w;
};

bool cmp(const Edge &A,const Edge &B){
    return (A.w>B.w);
}

int n,m;

int find(int x){
    if(par[x]!=x){return par[x]=find(par[x]);}
    else return x;
}

void unite(int x,int y){
    int a=find(x);
    int b=find(y);
    if(a==b){return;}
    par[b]=a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    vector<Edge> edges(m);
    for(int i=0;i<n;i++){
        par[i]=i;
    }
    for(auto &i : edges){
        cin >> i.u >> i.v >> i.w;
        i.u--;i.v--;i.w--;
    }
    sort(edges.begin(),edges.end(),cmp);
    ll ans=0;
    for(auto i : edges){
        int curr=i.u;
        int nex=i.v;
        ll weight=i.w;
        if(find(curr)!=find(nex)){
            unite(curr,nex);
            ans+=weight;
        }
    }
    cout << ans << '\n';
}