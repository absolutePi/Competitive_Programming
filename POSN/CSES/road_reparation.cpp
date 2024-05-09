#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll N = 1e5+5;
ll par[N];

struct Edge{
    ll a;
    ll b;
    ll w;
};

bool cmp(const Edge &a,const Edge &b){
    return (a.w<b.w);
}

ll find(ll x){
    if(x!=par[x]){return par[x]=find(par[x]);}
    else return x;
}

void unite(ll x,ll y){
    ll a=find(x);
    ll b=find(y);
    if(a==b){return;}
    par[b]=a;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll n,m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for(ll i=0;i<m;i++){
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
        edges[i].a--;
        edges[i].b--;
    }
    sort(edges.begin(),edges.end(),cmp);
    for(ll i=0;i<n;i++){
        par[i]=i;
    }
    ll cost=0;
    for(ll i=0;i<m;i++){
        ll x=edges[i].a;
        ll y=edges[i].b;
        ll c=edges[i].w;
        if(find(x)==find(y)){continue;}
        cost+=c;
        unite(x,y);
    }
    bool pos=true;
    for(ll i=1;i<n;i++){
        if(find(i)!=find(i-1)){
            pos=false;
            break;
        }
    }
    if(pos){
        cout << cost << '\n';
    }
    else{
        cout << "IMPOSSIBLE" << '\n';
    }
}   
