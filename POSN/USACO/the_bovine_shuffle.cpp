#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1e5+5;
ll neighbor[N];
ll after_shuffle[N];
ll n,ans;

int main(){
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n;
    for(ll i=0;i<n;i++){
        cin >> neighbor[i];
        neighbor[i]--;
        after_shuffle[neighbor[i]]++;
    }
    ans = n;
    queue<ll> q;
    for(int i=0;i<n;i++){
        if(after_shuffle[i]==0){
            ans--;
            q.push(i);
        }
    }
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        if(--after_shuffle[neighbor[cur]]==0){
            q.push(neighbor[cur]);
            ans--;
        }
    }
    cout << ans;
}