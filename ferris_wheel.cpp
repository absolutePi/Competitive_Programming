#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

int main(){
    //ios::sync_with_stdio(false);
    //in.tie(NULL);
    int n,x;
    cin >> n >> x;
    vector<int> child(n);
    for(auto &i : child){cin >> i;}
    sort(all(child));
    int l=0,r=n-1,ans=0;
    while(l<=r){
        if(l==r){
            ans++;
            l++;
            r--;
        }
        else if(child[l]+child[r]<=x){
            ans++;
            l++;
            r--;
        }
        else{
            ans++;
            r--;
        }
    }
    cout << ans;
}