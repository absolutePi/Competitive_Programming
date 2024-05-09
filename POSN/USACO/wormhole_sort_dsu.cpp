#include <bits/stdc++.h>

using namespace std;

int n,m;
const int N = 1e5+5;
int cows[N];
vector<pair<int,pair<int,int>>> wormholes;
vector<int> par;

int find(int x){
    if(par[x]!=x){return par[x]=find(par[x]);}
    else return x;
}

void unite(int x,int y){
    int a=find(x);
    int b=find(y);
    par[a]=b;
    return;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("wormsort.in","r",stdin);
    freopen("wormsort.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> cows[i];
        cows[i]--;
    }
    int mx_w = 0;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        mx_w=max(mx_w,w);
        a--;b--;
        wormholes.push_back({w,{a,b}});
    }
    par.resize(n);
    int l=0,r=mx_w+1,mid;
    int valid;
    while(l<=r){
        mid = l+(r-l)/2;
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        for(int i=0;i<m;i++){
            if(wormholes[i].first>=mid){
                unite(wormholes[i].second.first,wormholes[i].second.second);
            }
        }
        bool pos=true;
        for(int i=0;i<n;i++){
            if(find(i)!=find(cows[i])){
                pos=false;
                break;
            }
        }
        if(pos){
            valid=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    if(valid==mx_w+1){
        cout << -1 << '\n';
    }
    else{
        cout << valid << '\n';
    }
}