#include <bits/stdc++.h>

using namespace std;

const int MAX_H = 1000;
const int N = 1e6;
int n,k;
int houses[N];

bool works(int firehose_range){
    for(int i=0;i<n;i++){
        int needed=1;
        int start = houses[i];
        for(int j=1;j<n;j++){
            int end = houses[(i+j)%n];
            int dist =  (end-start+N)%N;
            if(dist>2*firehose_range){
                start=end;
                needed++;
            }
        }
        if(needed<=k){return true;}
    }
    return false;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> houses[i];
    }
    cin >> k;
    sort(houses,houses+n);
    int l=0,r=N;
    while(l<r){
        int mid=l+(r-l)/2;
        if(works(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout << l << '\n';
}       