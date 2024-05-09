#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 2005*2005;
int par[N];

struct Edge{
    int a,b,w;
};

bool cmp(const Edge &A,const Edge &B){
    return (A.w<B.w);
}

int find(int x){
    if(x!=par[x]){return par[x]=find(par[x]);}
    else return x;
}

void unite(int x,int y){
    int a=find(x);
    int b=find(y);
    if(a==b){return;}
    par[a]=b;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("fencedin.in","r",stdin);
    freopen("fencedin.out","w",stdout);
    int hdist,vdist,n,m;
    cin >> hdist >> vdist >> n >> m;
    vector<int> vx(n+1),vy(m+1);
    for(int i=1;i<=n;i++){
        cin >> vx[i];
    }
    for(int i=1;i<=m;i++){
        cin >> vy[i];
    }
    vx.push_back(hdist);
    vy.push_back(vdist);
    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());
    n+=2;
    m+=2;
    vector<Edge> edges;
    int curr_sect=0,row=1;
    while(row<m){
        for(int i=0;i<n-2;i++){
            edges.push_back({curr_sect,curr_sect+1,vy[row]-vy[row-1]});
            curr_sect++;
        }
        row++;
        curr_sect++;
    }
    curr_sect=n-1;
    int col=1;
    while(col<n){
        int init=curr_sect;
        for(int i=0;i<m-2;i++){
            edges.push_back({curr_sect-(n-1),curr_sect,vx[col]-vx[col-1]});
            curr_sect+=(n-1);
        }
        curr_sect=init+1;
        col++;
    }
    for(int i=0;i<(n+2)*(m+2);i++){
        par[i]=i;
    }
    sort(edges.begin(),edges.end(),cmp);
    ll ans=0;
    for(auto edge : edges){
        if(find(edge.a)!=find(edge.b)){
            unite(edge.a,edge.b);
            ans+=edge.w;
        }
    }
    cout << ans << '\n';
}   