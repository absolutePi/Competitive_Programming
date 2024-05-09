#include <bits/stdc++.h>

using namespace std;

int n;
int a,b,c,d,e;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int p,q,r,s,t;
        cin >> p >> q >> r >> s >> t;
        a+=p;
        b+=q;
        c+=r;
        d+=s;
        e+=t;
    }
    int sum=a*8+b*6+c*4+d*2+e;
    int ans=sum/8+(sum%8!=0);
    cout << ans << '\n';
}