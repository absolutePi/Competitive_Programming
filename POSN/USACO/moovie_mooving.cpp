#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int dur[N+1];
vector<set<int>> starts(N+1);
int dp[1<<N];

int main(){
    freopen("movie.in","r",stdin);
    freopen("movie.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,l;
    cin >> n >> l;
    for(int i=0;i<n;i++){
        cin >> dur[i];
        int showtimes;
        cin >> showtimes;
        for(int j=0;j<showtimes;j++){
            int x;
            cin >> x;
            starts[i].insert(x);
        }
    }   
    dp[0]=0;
    for(int i=1;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                int prev=i^(1<<j);
                auto it=starts[j].upper_bound(dp[prev]);
                it--;
                if(*it<=dp[prev]){
                    dp[i]=max(dp[i],*it+dur[j]);
                }
            }
        }
    }
    int ans=INT_MAX;
    bool check=false;
    for(int i=1;i<(1<<n);i++){
        if(dp[i]>=l){
            check=true;
            ans=min(ans,__builtin_popcount(i));
        }
    }
    if(!check){
        cout << "-1" << '\n';
    }
    else{
        cout << ans << '\n';
    }
}