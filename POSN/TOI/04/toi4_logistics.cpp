#include <bits/stdc++.h>

using namespace std;

map<char,vector<pair<double,char>>> adj;
map<char,bool> vis;
vector<tuple<char,char,double>> ans;

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        char u,v;
        int w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    char start='X';
    while(start!='Y'){
        vis[start]=true;
        char nx;
        vector<double> v;
        for(auto i : adj[start]){
            if(vis[i.second])continue;
            nx=i.second;
            v.push_back(i.first);
        }
        if(v.size()==0){
            cout << "broken" << '\n';
            return 0;
        }
        sort(v.begin(),v.end());
        int sz=v.size();
        double median;
        if(v.size()%2){
            median=v[sz/2];
        }
        else{
            median=(v[(sz/2)-1]+v[(sz/2)])/2;
        }
        ans.push_back({start,nx,median});
        start=nx;
    }
    double sum=0;
    for(auto i : ans){
        char u=get<0>(i);
        char v=get<1>(i);
        double med=get<2>(i);
        cout << u << ' ' << v << ' ' << fixed << setprecision(1) << med << '\n';
        sum+=med;
    }
    cout << sum << '\n';
}