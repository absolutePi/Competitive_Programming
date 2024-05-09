#include <bits/stdc++.h>

using namespace std;

#define ll long long
int two[205],fv[205];
int pre[205][6005];
int curr[205][6005];

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,b;
    cin >> n >> b;
    vector<ll> v(n+1);
    memset(pre, -1, sizeof(pre));
	memset(curr, -1, sizeof(curr));
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    for(int i=1;i<=n;i++){
        while(v[i]%2==0){
            two[i]++;
            v[i]/=2;
        }
        while(v[i]%5==0){
            fv[i]++;
            v[i]/=5;
        }
    }
    
    pre[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=b;j++){
            for(int c=0;c<=6000;c++){
                //use the ith element
                if(j!=0 && fv[i]<=c){
                    if(pre[j-1][c-fv[i]]!=-1){
                        curr[j][c]=max(curr[j][c],pre[j-1][c-fv[i]]+two[i]);
                    }
                }
                //doesnt use the ith element
                if(pre[j][c]!=1){
                    curr[j][c]=max(curr[j][c],pre[j][c]);
                }
            }
        }
        for(int j=0;j<=b;j++){
            for(int c=0;c<=6000;c++){
                pre[j][c]=curr[j][c];
                curr[j][c]=-1;
            }
        }
    }
    int ans=0;
    for(int c=0;c<=6000;c++){
        ans=max(ans,min(c,pre[b][c]));
    }
    cout << ans << '\n';
}