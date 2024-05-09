#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int limit,goods_num;
    cin >> limit >> goods_num;
    map<int,vector<pair<int,int>>> by_weight;
    for(int i=0;i<goods_num;i++){
        int value,weight,num;
        cin >> value >> weight >> num;
        if(weight<=limit && num>0){
            by_weight[weight].push_back({value,num});
        }
    }
    vector<vector<ll>> dp(by_weight.size()+1,vector<ll>(limit+1,INT32_MIN));
    dp[0][0]=0;
    //dp[fitst i weight][j capacity]
    int at=1;
    for(auto &[w,items] : by_weight){
        sort(items.begin(),items.end(),greater<pair<int,int>>());
        for(int cap=0;cap<=limit;cap++){
            dp[at][cap]=dp[at-1][cap];
            int copies=0;
            int type_at=0;
            int curr_used=0;
            ll profit=0;
            while((copies+1)*w<=cap && type_at<items.size()){
                copies++;
                profit+=items[type_at].first;
                if(dp[at-1][cap-copies*w]!=INT32_MIN){
                    dp[at][cap]=max(dp[at][cap],dp[at-1][cap-copies*w]+profit);
                }
                curr_used++;
                if(curr_used==items[type_at].second){
                    type_at++;
                    curr_used=0;
                }
            }
        }
        at++;
    }
    cout << *max_element(dp.back().begin(),dp.back().end()) << '\n';
}   