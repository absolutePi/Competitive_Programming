#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,mx = INT_MIN,tram=0;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        tram-=a;
        tram+=b;
        mx = max(mx,tram);
    }
    cout << mx;
}