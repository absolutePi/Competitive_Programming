#include <bits/stdc++.h>

using namespace std;

const int N = 505;
int n;
int field[N][N];
int par[N*N];
int sz[N*N];
int mx[]={1,-1,0,0},my[]={0,0,1,-1};

struct Cell{
    int i,j;
};

struct Edges{
    Cell from,to;
    int cost;
};

bool within(int x,int y){
    return (x>=0&&y>=0&&x<n&&y<n);
}

bool cmp(Edges &a,Edges &b){
    return a.cost<b.cost;
}

int find(int x){
    if(par[x]!=x){return par[x]=find(par[x]);}
    else return x;
}

bool unite(int x,int y){
    int a=find(x);
    int b=find(y);
    if(a==b){return false;}
    if(sz[a]<sz[b])swap(a,b);
    sz[a]+=sz[b];
    par[b]=a;
    return (sz[a]>=(n*n+1)/2);
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("tractor.in","r",stdin);
    freopen("tractor.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> field[i][j];
        }
    }
    for(int i=0;i<n*n;i++){
        par[i]=i;
        sz[i]=1;
    }
    vector<Edges> edges;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<4;k++){
                Cell to = {i+mx[k],j+my[k]};
                if(within(to.i,to.j)&&field[to.i][to.j]<=field[i][j]){
                    edges.push_back({{i,j},to,field[i][j]-field[to.i][to.j]});
                }
            }
        }
    }
    sort(edges.begin(),edges.end(),cmp);
    for(auto edge : edges){
        if(unite(edge.from.i*n+edge.from.j,edge.to.i*n+edge.to.j)){
            cout << edge.cost << '\n';
            return 0;
        }
    }
}   