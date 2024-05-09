#include <bits/stdc++.h>

using namespace std;

const int K = 1e5+5;
const int N = 105;
int a[N];
bool dp[K];//false = Jiro// true = Taro

int main(){
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(i>=a[j]){
                dp[i]|=(dp[i-a[j]]^1);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=a[i];j<=k;j++){
    //         dp[j]|=(dp[j-a[i]]^1);
    //     }
    // }
    if(dp[k]){
        cout << "First" << '\n';
    }
    else cout << "Second" << '\n';
}
