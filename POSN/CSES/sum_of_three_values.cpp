#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int n,x;
    cin >> n >> x;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        int l=0;
        int r=n-1;
        while(l!=r){
            int target = x - v[i].first;
            if(l!=i&&r!=i&&v[l].first+v[r].first==target){
                cout << v[l].second+1 << " " << v[i].second+1 << " " << v[r].second+1;
                return 0;
            }
            if(v[l].first+v[r].first<target){
                l++;
            }
            else{
                r--;
            }
        }
    }
    cout << "IMPOSSIBLE";
}