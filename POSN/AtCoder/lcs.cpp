#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
int dp[N][N];
string str1,str2;

void print(int i,int j){
    if(i==0||j==0)return;
    if(dp[i][j]==dp[i-1][j])print(i-1,j);
    else if(dp[i][j]==dp[i][j-1])print(i,j-1);
    else if(str1[i-1]==str2[j-1]){
        print(i-1,j-1);
        cout << str1[i-1];
    }
}

int main(){
    cin >> str1 >> str2;
    int n=str1.length(),m=str2.length();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if((str1[i-1]==str2[j-1]))dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    print(n,m);
}