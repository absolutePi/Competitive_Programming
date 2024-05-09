#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+5;
int t[N],x[N],y[N];

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> t[i] >> x[i];
        if(t[i]==2){
            cin >> y[i];
        }
    }
    vector<int> parents(N);
    vector<int> ans;
    iota(parents.begin(),parents.end(),0);
    for(int i=q-1;i>=0;i--){
        if(t[i]==1){
            ans.push_back(parents[x[i]]);
        }
        else{
            parents[x[i]]=parents[y[i]];
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto i : ans){
        cout << i << ' ';
    }
}