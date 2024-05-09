#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
int dp1[N][N],dp2[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i : v){cin >> i;}
    for(int i=0;i<n;i++)dp1[i][i]=v[i];
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(i<j){
                if(i+1<n){
                    dp1[i][j]=max(dp1[i][j],dp1[i+1][j]+v[i]+abs(v[i]-v[j]));
                }
                if(j-1>=0){
                    dp1[i][j]=max(dp1[i][j],dp1[i][j-1]+v[j]+abs(v[i]-v[j]));
                }
            }
        }
    }
    for(int i=0;i<n;i++)dp2[i]=dp1[0][i];
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            dp2[i]=max(dp2[i],dp2[j]+dp1[j+1][i]);
        }
    }
    cout << dp2[n-1] << '\n';
}   