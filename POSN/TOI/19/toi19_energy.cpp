#include <bits/stdc++.h>

using namespace std;

#define ll long long 
const int N = 305;
const int K = 15;
const int MOD = 1000000007;
int pref[N];
ll dp[N][N][K];
int n,k,d;

ll dac(int l,int r,int level){
    if(level==k){
        return dp[l][r][level]=1;//only one possibility
    }
    if(l>=r){return dp[l][r][level]=0;}//unable to divide llo two subarrays
    if(dp[l][r][level]!=-1){return dp[l][r][level];}//already processed
    ll temp=0;
    for(int mid=l;mid<r;mid++){
        if(abs((pref[mid]-pref[l-1])-(pref[r]-pref[mid]))>d){continue;}
        ll a=dac(l,mid,level+1);
        ll b=dac(mid+1,r,level+1);
        temp+=a*b;
        temp%=MOD;
    }
    return dp[l][r][level]=temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> d;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int b=0;b<=k;b++){
                dp[i][j][b]=-1;
            }
        }
    }
    // memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        pref[i]=pref[i-1]+a;
    }
    cout << dac(1,n,1) << '\n';
}   