#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
int x[N],y[N],s[N],t[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        s[i]=s[i-1]+a;
    }
    for(int i=0;i<m;i++){
        cin >> y[i];
    }
    for(int i=1;i<=m;i++){
        int a;
        cin >> a;
        t[i]=t[i-1]+a;
    }
    for(int i=0;i<q;i++){
        int a,b,k;
        cin >> a >> b >> k;
        int l=-1e9,r=1e9,mid,ans=0;
        while(l<=r){
            mid=l+(r-l)/2;
            int curr_x=s[upper_bound(x,x+n,mid)-x];
            int curr_y=t[upper_bound(y,y+m,(mid-b)/a)-y];
            if(curr_x+curr_y>=k){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        cout << ans << '\n';
    }
}