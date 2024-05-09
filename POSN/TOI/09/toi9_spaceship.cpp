#include <bits/stdc++.h>

using namespace std;

struct Data{
    int x,y,z;
    int a,b,c;
};

const int N = 15;
bool vis[N];
vector<Data> stores;
int n,m,ans=INT_MAX;


int dist(Data &A,Data &B){
    return (A.x-B.x)*(A.x-B.x)+
           (A.y-B.y)*(A.y-B.y)+
           (A.z-B.z)*(A.z-B.z);
}

void dfs(int curr_dist,Data curr){
    if(curr.a>=n&&curr.b>=n&&curr.c>=n){
        ans=min(ans,curr_dist);
        return;
    }
    for(int i=0;i<m;i++){
        if(!vis[i]){
            vis[i]=true;
            dfs(curr_dist+dist(curr,stores[i]),{stores[i].x,stores[i].y,stores[i].z,
            stores[i].a+curr.a,stores[i].b+curr.b,stores[i].c+curr.c});
            vis[i]=false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int p,q,r;
    cin >> p >> q >> r;
    Data start={p,q,r,0,0,0};
    cin >> m;
    stores.resize(m);
    for(int i=0;i<m;i++){
        cin >> stores[i].x >> stores[i].y >> stores[i].z;
        cin >> stores[i].a >> stores[i].b >> stores[i].c;
    }
    dfs(0,start);
    cout << ans << '\n';
}