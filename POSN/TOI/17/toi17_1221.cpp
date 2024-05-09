#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll INF=1e18;
const int N = 505;
int n,m,q;
pair<ll,ll> dist[N][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++){
        ll a;
        cin >> a;
        dist[i][i]={a,0};
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            dist[i][j]={dist[i][i].first+dist[j][j].first,1};
            dist[j][i]={dist[i][i].first+dist[j][j].first,1};
        }
    }
    for(int i=0;i<m;i++){
        ll a,b,w;
        cin >> a >> b >> w;
        if(dist[a][b].first>w){
            dist[a][b]={w,1};
            dist[b][a]={w,1};
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k].first==INF||dist[k][j].first==INF){continue;}
                ll curr=dist[i][j].first;
                ll curr_steps=dist[i][j].second;
                ll nx=dist[i][k].first+dist[k][j].first;
                ll nx_steps=dist[i][k].second+dist[k][j].second;
                if(nx<curr){
                    dist[i][j]={nx,nx_steps};
                }
                else if(nx==curr&&curr_steps<nx_steps){
                    dist[i][j].second=nx_steps;
                }
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=i+1;j<=n;j++){
    //         cout << dist[i][j].first << '\n';
    //     }
    // }
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        cout << dist[a][b].first << ' ' << dist[a][b].second*2 << '\n';
    }
}