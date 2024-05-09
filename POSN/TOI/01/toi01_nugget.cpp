#include <bits/stdc++.h>

using namespace std;

const int N = 105;
bool pos[N];

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    if(n<6){
        cout << "no" << '\n';
        return 0;
    }
    pos[0]=1;
    for(int i=0;i<=n;i++){
        if(i>=6)pos[i]|=pos[i-6];
        if(i>=9)pos[i]|=pos[i-9];
        if(i>=20)pos[i]|=pos[i-20];
    }
    for(int i=6;i<=n;i++){
        if(pos[i]){
            cout << i << '\n';
        }
    }
}   