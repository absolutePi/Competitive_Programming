#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<pair<int,int>> v;
    int n,x;
    cin >> n >> x;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v.emplace_back(a,i);
    }
    sort(v.begin(),v.end());
    int l=0,r=n-1,sum=0;
    while(l<r){
        if(v[l].first+v[r].first==x){
            cout << v[l].second+1 << " " << v[r].second + 1;
            return 0;
        }
        else if(v[l].first+v[r].first>x){
            r--;
        }
        else{
            l++;
        }
    }
    cout << "IMPOSSIBLE";
}