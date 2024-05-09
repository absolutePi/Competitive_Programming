#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
int n,q,a[N],qs[350][N],sq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        qs[1][i]=qs[1][i-1]+a[i];
    }
    sq=sqrt(n);
    for(int i=1;i<=sq;i++){
        for(int j=1;j<=n;j++){
            qs[i][j]=a[j];
            if(j>=i){
                qs[i][j]+=qs[i][j-i];
            }
        }
    }
    for(int i=0;i<q;i++){
        int l,m,r,ans=0;
        cin >> l >> m >> r;
        if(m<=sq){
            ans=qs[m][l+(r-l)/m*m]-qs[m][l]+a[l];
        }
        else{
            for(int i=l;i<=r;i+=m){
                ans+=a[i];
            }
        }
        cout << ans << ' ';
    }
}