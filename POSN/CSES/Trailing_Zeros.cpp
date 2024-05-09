#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long powfive =5;
    int ans=0;
    while(powfive<=n){
        ans+=n/powfive;
        powfive*=5;
    }
    cout << ans;
}