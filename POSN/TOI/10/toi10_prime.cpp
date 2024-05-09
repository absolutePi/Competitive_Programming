#include <bits/stdc++.h>

using namespace std;

const int MX=1e7;
int n,cnt;
bitset<MX> NotPrime;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=2;;i++){
        if(NotPrime[i]){continue;}
        cnt++;
        if(cnt==n){
            cout << i << '\n';
            return 0;
        }
        for(int j=2;j*i<MX;j++){
            NotPrime[j*i]=true;
        }
    }
}