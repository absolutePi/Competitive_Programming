#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    map<int,int> m;
    int left=0,right=0,distinct=0;
    ll ans=0;
    while(left<n){
        while(right<n){
            if(m.count(v[right])==0&&distinct==k){break;}
            if(m.count(v[right])==0){
                m[v[right]]=1;
                distinct++;
            }
            else{
                m[v[right]]++;
            }
            right++;
        }   
        ans+= (right-left);
        if(m[v[left]]==1){
            distinct--;
            m.erase(v[left]);
        }
        else{
            m[v[left]]-=1;
        }
        left++;
    }
    cout << ans << '\n';
}