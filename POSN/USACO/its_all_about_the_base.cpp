#include <bits/stdc++.h>

using namespace std;

void solve(){
    int x,y;
    cin >> x >> y;
    map<int,int> recx,recy;
    for(int i=10;i<=15000;i++){
        int numx = (x%10) + ((x/10)%10)*i + ((x/100)%10)*i*i;
        int numy = (y%10) + ((y/10)%10)*i + ((y/100)%10)*i*i;
        recx[numx] = i;
        recy[numy] = i;
        if(recx.count(numy)){
            cout << recx[numy] << " " << i << endl;
            break;
        }
        if(recy.count(numx)){
            cout << i << " " << recy[numx] << endl;
            break;
        }
    }
    return;
}

int main(){
    freopen("whatbase.in","r",stdin);
    freopen("whatbase.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        solve();      
    }
}