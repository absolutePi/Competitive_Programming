#include <bits/stdc++.h>

using namespace std;

const int N = 80005;
vector<pair<int,int>> adj[N];
int n,l,r,mid,res;

pair<int,int> dfs(int node,int par){  
    pair<int,int> ans={0,0};
    for(auto i : adj[node]){
        if(i.second==par){continue;}
        pair<int,int> curr=dfs(i.second,node);
        if(curr.first+i.first>=mid){
            ans.second+=curr.second+1;
        }
        else{
            ans.first+=curr.first+i.first;
            ans.second+=curr.second;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }    
    int start;
    for(int i=0;i<=n;i++){
        if(adj[i].size()==1){
            start=i;
            break;
        }
    }
    l=0;
    r=2e9;
    while(l<=r){
        mid=l+(r-l)/2;
        pair<int,int> curr=dfs(start,-1);//dist and components
        if(curr.second>=3){
            l=mid+1;
            res=mid;
        }
        else{
            r=mid-1;
        }
    }
    cout << res << '\n';
}
/*
8
0 1 9
1 2 8
2 3 11
3 4 50
4 5 1
3 6 13
6 7 12
6 8 32
*/