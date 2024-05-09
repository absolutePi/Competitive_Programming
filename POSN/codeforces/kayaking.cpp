#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,ans=INT_MAX;
    cin >> n;
    vector<int> w(n*2);
    for(int i=0;i<n*2;i++){
        cin >> w[i];
    }
    sort(w.begin(),w.end());
    for(int i=0;i<n*2;i++){
        for(int j=i+1;j<n*2;j++){
            vector<int> v;
            int total_weight=0;
            for(int k=0;k<n*2;k++){
                if(k!=i&&k!=j){
                    v.push_back(w[k]);
                }
            }
            for(int k=0;k<n*2-2;k+=2){
                total_weight+=v[k+1]-v[k];
            }
            ans = min(ans,total_weight);
        }
    }
    cout << ans;
}