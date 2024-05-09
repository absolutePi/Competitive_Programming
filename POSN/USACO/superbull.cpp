#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll N = 2005;

ll par[N];

struct Edge{
    ll a,b,w;
};

bool cmp(const Edge &a,const Edge &b){
    return (a.w>b.w);
}

ll find(ll x){
    if(x!=par[x]){return par[x]=find(par[x]);}
    else return x;
}

void unite(ll x,ll y){
    ll a=find(x);
    ll b=find(y);
    if(a==b){return;}
    par[a]=b;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("superbull.in","r",stdin);
    freopen("superbull.out","w",stdout);
    ll n;
    cin >> n;
    vector<ll> ids(n);
    vector<Edge> edges;
    for(auto &i : ids){cin >> i;}
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            edges.push_back({i,j,ids[i]^ids[j]});
        }
    }
    sort(edges.begin(),edges.end(),cmp);
    ll scores=0;
    for(ll i=0;i<n;i++){
        par[i]=i;
    }
    for(ll i=0;i<edges.size();i++){
        ll x=edges[i].a;
        ll y=edges[i].b;
        ll weight=edges[i].w;
        if(find(x)!=find(y)){
            unite(x,y);
            scores+=weight;
        }
    }
    cout << scores << '\n';
}   