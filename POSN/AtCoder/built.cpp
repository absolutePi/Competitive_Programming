#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
tuple<int,int,int> pos[N];//x y index
int par[N];

struct Edge{
    int u,v,w;
};

bool cmp(const Edge &a,const Edge &b){
    return a.w<b.w;
}

bool cmpx(const tuple<int,int,int> &a,const tuple<int,int,int> &b){
    return get<0>(a)<get<0>(b);
}

bool cmpy(const tuple<int,int,int> &a,const tuple<int,int,int> &b){
    return get<1>(a)<get<1>(b);
}

int find(int x){
    if(par[x]!=x){return par[x]=find(par[x]);}
    else return x;
}

void unite(int x,int y){
    int a=find(x);
    int b=find(y);
    if(a==b)return;
    par[a]=b;
}

int main(){
    int n;  
    cin >> n;
    for(int i=0;i<n;i++){
        par[i]=i;
    }
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        pos[i]={x,y,i};
    }
    vector<Edge> edges;
    sort(pos,pos+n,cmpx);
    for(int i=0;i<n-1;i++){
        int x1=get<0>(pos[i]),x2=get<0>(pos[i+1]);
        int ind1=get<2>(pos[i]),ind2=get<2>(pos[i+1]);
        edges.push_back({ind1,ind2,abs(x1-x2)});
    }
    sort(pos,pos+n,cmpy);
    for(int i=0;i<n-1;i++){
        int y1=get<1>(pos[i]),y2=get<1>(pos[i+1]);
        int ind1=get<2>(pos[i]),ind2=get<2>(pos[i+1]);
        edges.push_back({ind1,ind2,abs(y1-y2)});
    }
    sort(edges.begin(),edges.end(),cmp);
    int num=0,ans=0;
    for(auto edge : edges){
        int node1=edge.u;
        int node2=edge.v;
        int weight=edge.w;
        if(find(node1)!=find(node2)){
            unite(node1,node2);
            ans+=weight;
            num++;
        }
        if(num==n-1){break;}
    }
    cout << ans << '\n';
}