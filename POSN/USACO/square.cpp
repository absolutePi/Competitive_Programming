#include <bits/stdc++.h>

using namespace std;

int first[4],sec[4],mxx,mxy,mnx=INT_MAX,mny=INT_MAX;

int main(){
    freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
    for(int i=0;i<8;i++){
        int a;
        cin >> a;
        if(i%2){
            mxy = max(mxy,a);
            mny = min(mny,a);
        }
        else{
            mxx = max(mxx,a);
            mnx = min(mnx,a);
        }
    }
    int x = max(mxx-mnx,mxy-mny);
    // cout << mxx << " " << mxy << "\n";
    // cout << mnx << " " << mny << "\n";
    cout << x*x;
}