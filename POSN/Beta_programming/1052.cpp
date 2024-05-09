#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
vector<pair<int,int>> v(N);//pos height
int par[N];
int prf[N];
//ผิด
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        par[i]=i;
        prf[i]=1;
    }
    for(int i=1;i<=n;i++){
        cin >> v[i].first >> v[i].second;
    }
    int ans=0;char dir;
    for(int i=1;i<n;i++){
        if(v[i+1].first-v[i].first<v[i].second){
            par[i+1]=par[i];
            prf[i+1]+=prf[i];
        }
        if(prf[i+1]>ans){
            ans=par[i+1];
            dir='R';
        }
    }
    for(int i=1;i<=n;i++){
        par[i]=i;
        prf[i]=1;
    }
    for(int i=n;i>1;i--){
        if(v[i-1].first-v[i].first<v[i].second){
            par[i-1]=par[i];
            prf[i-1]+=prf[i];
        }
        if(prf[i-1]>ans){
            ans=par[i-1];
            dir='L';
        }
    }
    cout << ans << ' ' << dir;
}