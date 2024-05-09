#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m,cnt=0;
    cin >> n >> m;
    while(n<=m){
        cnt++;
        n*=3;
        m*=2;
    }
    cout << cnt;
}