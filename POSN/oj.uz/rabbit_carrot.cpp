#include <bits/stdc++.h>

using namespace std;

int nds(const vector<int> &unchanged){
    vector<int> ans;
    for(auto i : unchanged){
        int p=upper_bound(ans.begin(),ans.end(),i)-ans.begin();
        if(p==ans.size()){
            ans.push_back(i);
        }
        else{
            ans[p]=i;
        }
    }
    return ans.size();
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for(auto &i : v){cin >> i;}
    vector<int> unchanged;
    for(int i=1;i<=n;i++){
        if(i*m>=v[i-1]){
            unchanged.push_back(i*m-v[i-1]);
        }
    }
    cout << n-nds(unchanged);
}