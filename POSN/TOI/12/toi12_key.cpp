#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
string str1,str2;
bool dp[N][N];

void solve(){
    string str;
    cin >> str;
    memset(dp,false,sizeof(dp));
    int l1=str1.length();
    int l2=str2.length();
    for(int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++){
            if(i==0&&j==0)dp[i][j]=true;
            if(i!=0){
                dp[i][j]|=(dp[i-1][j]&&str[i+j-1]==str1[i-1]);
            }
            if(j!=0){
                dp[i][j]|=(dp[i][j-1]&&str[i+j-1]==str2[j-1]);
            }
        }
    }
    if(dp[l1][l2])cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str1 >> str2;
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
}