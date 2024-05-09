#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll N = 3005;
ll par[N];
//85/100
struct Edge{
    ll u,v,w;
};

ll find(ll x){
    if(par[x]!=x){return par[x]=find(par[x]);}
    else return x;
}

void unite(ll x,ll y){
    ll a=find(x);
    ll b=find(y);
    if(a==b)return;
    par[b]=a;
}

bool cmp(const Edge &a,const Edge &b){
    return a.w<b.w;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;
    cin >> n >> m;
    vector<Edge> edges;
    for(ll i=0;i<n;i++){
        par[i]=i;
    }
    ll cnt=0;//there has to be n-1 edges
    for(ll i=0;i<m;i++){
        ll a,b,w,t;
        cin >> a >> b >> w >> t;
        if(t==1){
            unite(a,b);
            cnt++;
        }
        else if(t==0){
            edges.push_back({a,b,w});
        }
    }
    ll p;
    cin >> p;
    vector<pair<ll,ll>> packages(p);//{dist,money}
    vector<ll> edges_used;
    for(auto &i : packages){cin >> i.first >> i.second;}
    sort(edges.begin(),edges.end(),cmp);
    for(auto edge : edges){
        if(cnt==n-1){break;}
        ll node1=edge.u;
        ll node2=edge.v;
        ll weight=edge.w;
        if(find(node1)!=find(node2)){
            unite(node1,node2);
            cnt++;
            edges_used.push_back(weight);
        }
    }
    sort(edges_used.begin(),edges_used.end());
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;//{money,dist}
    for(ll i=0;i<p;i++){
        if(packages[i].first>=edges_used[0]){
            pq.push({packages[i].second,packages[i].first});
        }
    }
    ll ans=0;
    for(ll i=0;i<edges_used.size();i++){
        while(pq.top().second<edges_used[i])pq.pop();
        ans+=pq.top().first;
    }
    cout << ans << '\n';
}