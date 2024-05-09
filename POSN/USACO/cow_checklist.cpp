#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define f first 
#define s second
const int MX = 1001;
ll dp[MX][MX][2];

ll distance(pair<ll,ll> a,pair<ll,ll> b){
    return abs(a.f-b.f)*abs(a.f-b.f)+abs(a.s-b.s)*abs(a.s-b.s);
}

int main(){
    freopen("checklist.in","r",stdin);
    freopen("checklist.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll n,m;
    cin >> n >> m;
    vector<pair<ll,ll>> hcow(n+1);
    vector<pair<ll,ll>> gcow(m+1);
    for(ll i=1;i<=n;i++){
        cin >> hcow[i].f >> hcow[i].s;
    }
    for(ll i=1;i<=m;i++){
        cin >> gcow[i].f >> gcow[i].s;
    }
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=m;j++){
            dp[i][j][0]=INT_MAX;
            dp[i][j][1]=INT_MAX;
        }
    }
    dp[1][0][0]=0;
    // dp[1][1][1]=distance(hcow[1],gcow[1]);
    // || i==1 && j==1
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=m;j++){
            if(i==1 && j==0 ){continue;}
            if(i>0){
                dp[i][j][0]=min(dp[i-1][j][0]+distance(hcow[i-1],hcow[i]),
                dp[i-1][j][1]+distance(hcow[i],gcow[j]));
            }
            if(j>0){
                dp[i][j][1]=min(dp[i][j-1][0]+distance(hcow[i],gcow[j]),
                dp[i][j-1][1]+distance(gcow[j],gcow[j-1]));
            }
        }
    }
    cout << dp[n][m][0] << '\n';
}