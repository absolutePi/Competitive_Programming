#include <bits/stdc++.h>

using namespace std;

struct Cows{
    int height;
    int weight;
    int strength;
};

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("guard.in","r",stdin);
    freopen("guard.out","w",stdout);
    int n,h;
    cin >> n >> h;
    vector<Cows> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].height >> v[i].weight >> v[i].strength;
    }  
    vector<pair<int,int>> dp(1<<n);//dp[subset]={curr_height,max_safety_factor}
    dp[0]={0,INT32_MAX};
    for(int i=1;i<(1<<n);i++){
        dp[i]={0,-1};
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                dp[i].first+=v[j].height;
                int prev = i^(1<<j);
                dp[i].second=max(dp[i].second,min(v[j].strength,dp[prev].second-v[j].weight));
            }
        }
    }
    int max_safety=-1;
    for(int i=1;i<(1<<n);i++){
        if(dp[i].first>=h){
            max_safety=max(max_safety,dp[i].second);
        }
    }
    if(max_safety<0){
        cout << "Mark is too tall" << '\n';
    }
    else{
        cout << max_safety << '\n';
    }
}   