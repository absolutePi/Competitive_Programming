#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
const int NUM=1e6+5;
const int INF= 1e9+7;

int price[NUM];
int par[N];

struct Edge{
    int w,u,v;
};

bool cmp(const Edge &a,const Edge &b){
    return (a.w<b.w);
}

int find(int x){
    if(par[x]!=x)return par[x]=find(par[x]);
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
    int n,m;
    cin >> n >> m;
    vector<Edge> edges;
    for(int i=0;i<n;i++){
        par[i]=i;
    }
    for(int i=1;i<NUM;i++){
        price[i]=INF;
    }
    for(int i=0;i<m;i++){
        int a,b,w,t;
        cin >> a >> b >> w >> t;
        if(t==1){
            edges.push_back({0,a,b});
        }
        else{
            edges.push_back({w,a,b});
        }
    }
    sort(edges.begin(),edges.end(),cmp);
    int p;
    cin >> p;
    for(int i=0;i<p;i++){
        int dist,money;
        cin >> dist >> money;
        price[dist]=min(price[dist],money);
    }
    for(int i=NUM-2;i>=0;i--){
        price[i]=min(price[i],price[i+1]);
    }
    int ans=0;
    for(auto edge : edges){
        int node1=edge.u;
        int node2=edge.v;
        int weight=edge.w;
        if(find(node1)!=find(node2)){
            unite(node1,node2);
            ans+=price[weight];
        }
    }
    cout << ans << '\n';
}
