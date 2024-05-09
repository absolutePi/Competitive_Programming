#include <bits/stdc++.h>

using namespace std;

int main(){
    int l,n;
    cin >> l >> n;
    string mom1,mom2,child;
    cin >> mom1 >> mom2 >> child;
    vector<char> ans;
    for(int i=0;i<n;i++){
        char curr=child[i];
        for(int j=0;j<l;j++){
            vector<char> v;
            v.push_back(mom1[j]);
            v.push_back(mom2[j]);
            v.push_back(curr);
            sort(v.begin(),v.end());
            curr=v[1];
        }
        ans.push_back(curr);
    }
    for(auto i : ans){
        cout << i;
    }
}   