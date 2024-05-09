#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v1(n),v2(m);
    for(int i=0;i<n;i++){cin >> v1[i];}
    for(int i=0;i<m;i++){cin >> v2[i];}
    
    vector<int> ans;
    int l=0,r=0;
    while(l!=n || r!=m){
        if(r==m || l<n && v1[l]<v2[r]){
            ans.push_back(v1[l]);
            l++;
        }
        else{
            ans.push_back(v2[r]);
            r++;
        }
    }
    for(auto i : ans){
        cout << i << " ";
    }
}