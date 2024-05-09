#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+5;
int prf_point[N],prf_money[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        if(a<0){
            a*=-1;
            prf_money[i]=a;
        }
        else if(a>0){
            prf_point[i]=a;
        }
    }
    for(int i=1;i<N;i++){
        prf_money[i]+=prf_money[i-1];
        prf_point[i]+=prf_point[i-1];
    }
    // for(int i=1;i<=n;i++){cout << prf_point[i] << ' ';}
    // cout << '\n';
    // for(int i=1;i<=n;i++){cout << prf_money[i] << ' ';}
    for(int t=0;t<q;t++){
        int start,money;
        cin >> start >> money;
        start++;
        auto it = lower_bound(prf_money+1,prf_money+1+n,money+prf_money[start-1])-prf_money;
        // cout << money+prf_money[start-1] << '\n';
        it--;
        // cout << it << ' ' << start << '\n';
        // cout << it-start << '\n';
        if((it<0)||(it-start<0)){
            cout << 0 << '\n';
        }
        else{
            cout << prf_point[it]-prf_point[start-1] << '\n';
        }
    }
}