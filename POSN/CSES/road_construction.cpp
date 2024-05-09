#include <bits/stdc++.h>

using namespace std;

int n,m;
int comp;
vector<int> par;
vector<int> sz;
int mx=1;

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
    if(sz[a]>sz[b])swap(a,b);
    par[a]=b;
    comp--;
    sz[b]+=sz[a];
    mx=max(mx,sz[b]);
    return;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> m;
    comp=n;
    par.resize(n);
    sz.resize(n,1);
    for(int i=0;i<n;i++){
        par[i]=i;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        unite(--a,--b);
        cout << comp << ' ' << mx << '\n';
    }
}