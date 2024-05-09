#include <bits/stdc++.h>

using namespace std;

const int N =1e5+1;
int ds[N],cnt,mx;

int main(){
    freopen("diamond.in","r",stdin);
    freopen("diamond.out","w",stdout);
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> ds[i];
    }
    sort(ds,ds+n);
    for(int i=0;i<n;i++){
        cnt=1;
        for(int j=i+1;j<n;j++){
            if(ds[j]-ds[i]>k){break;}
            else mx = max(mx,++cnt);
        }
    }
    cout << mx;
}