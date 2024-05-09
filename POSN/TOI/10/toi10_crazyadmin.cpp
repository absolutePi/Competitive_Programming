#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int cables,n,mx,sum;
int rooms[N];

bool works(int cap){
    // cout << '\n' << cap << '\n';
    int curr_sum=0,cable_used=1;
    for(int i=0;i<n;i++){
        if(curr_sum+rooms[i]>cap){
            curr_sum=rooms[i];
            cable_used++;
            // cout << curr_sum << ' ';
        }
        else{
            curr_sum+=rooms[i];
        }
    }
    return cable_used<=cables;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> cables >> n;
    for(int i=0;i<n;i++){
        cin >> rooms[i];
        sum+=rooms[i];
        mx=max(mx,rooms[i]);
    }
    int l=mx,r=sum,mid,ans=0;
    while(l<=r){
        mid=l+(r-l)/2;
        if(works(mid)){
            ans=mid;
            r=mid-1;
            // cout << "D";
        }
        else{
            l=mid+1;
        }
    }
    cout << ans << '\n';
}