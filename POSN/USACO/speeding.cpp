#include <bits/stdc++.h>

using namespace std;


int main(){
    freopen("speeding.in","r",stdin);
    freopen("speeding.out","w",stdout);
    int n,m,mx = 0;
    int pos = 0,limits[101];
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int seg,lim;
        cin >> seg >> lim;
        for(int j=0;j<seg;j++){
            limits[pos++] = lim;
        }
    }
    pos = 0;
    for(int i=0;i<m;i++){
        int seg,speed;
        cin >> seg >> speed;
        for(int i=0;i<seg;i++){
            // cout << b-arr[q] << "\n";
            if(speed > limits[pos]){
                mx = max(mx,speed - limits[pos]);
            }
            pos++;
        }
        // cout << mx << "\n";
    }
    cout << mx;
}