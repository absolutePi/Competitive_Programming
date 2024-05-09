#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int A=0,B=0,C=0,D=0,E=0;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b,c,d,e;
        cin >> a >> b >> c >> d >> e;
        A+=a;
        B+=b;
        C+=c;
        D+=d;
        E+=e;
    }
    int sum=A*8+B*6+C*4+D*2+E;
    int ans=sum/8;
    if(sum%8)ans++;
    cout << ans << '\n';
}   