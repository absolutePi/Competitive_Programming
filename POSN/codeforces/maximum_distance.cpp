#include <bits/stdc++.h>

using namespace std;

const int N =1e5+1;
int x[N],y[N],mx;
vector<pair<int,int>> v;

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    for(int i=0;i<n;i++){
        cin >> y[i];
    }
    for(int i=0;i<n;i++){
        v.push_back({x[i],y[i]});
    }
    // for(auto i : v){
    //     cout << i.first << " " << i.second << "\n";
    // }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int ex = v[i].first - v[j].first;
            int why = v[i].second - v[j].second;
            int a = ex*ex + why*why;
            mx = max(mx,a);
            // cout << ex << " " << why << " " <<  mx << "\n";
        }
    }
    cout << mx;
}