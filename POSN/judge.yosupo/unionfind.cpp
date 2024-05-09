#include <bits/stdc++.h>

using namespace std;

int n,q;
const int N = 2e5+5;
int par[N];

int find(int x){
    if(par[x]!=x){
        par[x]=find(par[x]);
    }
    return par[x];
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> q;
    for(int i=0;i<=n;i++){
        par[i]=i;
    }
    for(int i=0;i<q;i++){
        int t,a,b;
        cin >> t >> a >> b;
        if(t){
            cout << (find(a)==find(b) ? 1 : 0) << '\n';
        }
        else{
            par[find(a)]=find(b);
        }
    }
}