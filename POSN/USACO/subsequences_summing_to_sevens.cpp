#include <bits/stdc++.h>

using namespace std;

const int MOD = 7;

int main(){
    freopen("div7.in","r",stdin);
    freopen("div7.out","w",stdout);
    int n;
    cin >> n;
    vector<int> first(MOD,-1);
    first[0]=0;
    int curr=0,ans=INT_MIN;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        curr = (curr+x)%MOD;
        if(first[curr]==-1){
            first[curr] = i;
        }
        else{
            ans = max(ans,i-first[curr]);
        }
    }
    cout << ans << endl;
}