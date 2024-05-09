#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5+5;
int x[N],h[N];

signed main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x[i] >> h[i];
    }
    int ans=INT_MIN,cnt=1,a=x[0]+h[0],curr_pos=1,pos=1;
    char dir='R';
    for(int i=1;i<n;i++){
        if(a>x[i]){
            cnt++;
            a=max(a,x[i]+h[i]);
        }
        else{
            cnt=1;
            a=x[i]+h[i];
            curr_pos=i+1;
        }
        if(cnt>ans){
            ans=cnt;
            pos=curr_pos;
            dir='R';
        }
    }
    a=x[n-1]-h[n-1],cnt=1;
    for(int i=n-2;i>=0;i--){
        if(a<x[i]){
            cnt++;
            a=min(a,x[i]-h[i]);
        }
        else{
            cnt=1;
            a=x[i]-h[i];
            curr_pos=i+1;
        }
        if((cnt>ans)||(cnt==ans && curr_pos<=pos)){
            ans=cnt;
            pos=curr_pos;
            dir='L';
        }
    }
    cout << pos << ' ' << dir;
}