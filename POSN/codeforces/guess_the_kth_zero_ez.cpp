#include <bits/stdc++.h>

using namespace std;

int N,K;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> N >> K >> K;
    int l=1,r=N;
    while(l<r){
        int mid = l+(r-l)/2;
        cout << "? 1 " << mid << endl;
        int zeros;
        cin >> zeros;
        int ones = mid-zeros;
        if(ones>=K){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout << "! " << l;
}