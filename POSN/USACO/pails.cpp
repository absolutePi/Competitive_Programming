#include <bits/stdc++.h>

using namespace std;

int x,y,m,mx;

int main(){
    freopen("pails.in","r",stdin);
    freopen("pails.out","w",stdout);
    cin >> x >> y >> m;
    for(int i=0;true;i++){
        if(x*i>m){break;}
        for(int j=0;true;j++){
            if(y*j+x*i>m){break;}
            mx = max(mx,x*i + y*j);
        }
    }
    cout << mx;
}