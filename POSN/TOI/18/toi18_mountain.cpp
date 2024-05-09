#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<ll,ll>
const ll INF=LLONG_MAX;
const int N = 505;
int n,m;
pii pos[N];
ll dp[N][N];

ll dif(int i,int j){
    return abs(pos[i].first-pos[j].first)+abs(pos[i].second-pos[j].second);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> pos[i].first >> pos[i].second;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=INF;
        }
    }
    dp[0][0]=0;
    for(int k=1;k<n;k++){
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                dp[k][i]=min(dp[k][i],max(dp[k-1][j],dif(i,j)));
            }
        }
    }
    ll ans=0;
    for(int i=0;i<m;i++){
        ll strength;
        cin >> strength;
        ll l=0,r=n,mid,curr=0;
        while(l<=r){
            mid=l+(r-l)/2;
            if(dp[mid][n-1]<=strength){
                r=mid-1;
                curr=mid;
            }
            else{
                l=mid+1;
            }
        }
        ans+=curr;
    }
    cout << ans << '\n';
    // for(int i=0;i<n;i++){
    //     cout << dp[i][n-1] << ' ';
    // }
}   