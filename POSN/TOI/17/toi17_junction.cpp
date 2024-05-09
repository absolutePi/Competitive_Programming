#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int N = 80005;
vector<pair<int,int>> adj[N];
bool vis[N];
ll a[N];
int node=0;

void dfs(int curr){
    vis[curr]=true;
    for(auto u : adj[curr]){
        if(vis[u.first]){continue;}
        a[node]=u.second;
        node++;
        dfs(u.first);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    int start;
    for(int i=0;i<=n;i++){
        if(adj[i].size()==1){
            start=i;
            break;
        }
    }
    dfs(start);
    ll l=0,r=20005*80000,mid,sum=0,cnt,ans;
    while(l<=r){
        mid=l+(r-l)/2;
        cnt=0,sum=0;
        for(int i=0;i<node;i++){
            sum+=a[i];
            if(sum>=mid){
                sum=0;
                cnt++;
            }
        }
        if(cnt<3){
            r=mid-1;
        }
        else{
            ans=mid;
            l=mid+1;
        }
    }
    cout << ans << '\n';
    // cout << l << ' ' << r;
}   