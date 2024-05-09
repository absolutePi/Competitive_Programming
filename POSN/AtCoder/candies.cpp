#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
const int K = 1e5+5;
const int N = 105;
int a[N],dp[N][K];
int n,k;

int recur(int ind,int sum){
    if(dp[ind][sum])return dp[ind][sum];
    for(int i=0;i<=a[ind];i++){
        
    }
}

void recur(int ind,vector<int> v,int sum){
    if(ind==n&&sum==k){
        for(auto i : v){
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    if(sum>k||ind==n)return;
    for(int i=0;i<=a[ind];i++){
        v.push_back(i);
        recur(ind+1,v,sum+i);
        v.pop_back();
    }
}

int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    recur(0,{},0);
}