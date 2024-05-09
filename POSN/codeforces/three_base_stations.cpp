#include <bits/stdc++.h>

using namespace std;
#define ll long long

const long double N = 1e-7;
int n;
vector<int> houses;
vector<long double> ans;

pair<bool,vector<long double>> works(double curr_dist){
    vector<long double> pos = {houses[0]+curr_dist,0,0};
    int used = 0;
    for(int i=1;i<n;i++){
        if(curr_dist<houses[i]-pos[used]){
            used++;
            if(used==3){
                return {false,pos};
            }
            pos[used]=houses[i]+curr_dist;
        }
    }
    return {true,pos};
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n;
    houses.resize(n);
    for(int i=0;i<n;i++){
        cin >> houses[i];
    }
    sort(houses.begin(),houses.end());
    double l=0,r=1e9,mid;
    while(r-l>N){
        mid = l+(r-l)/2;
        pair<bool,vector<long double>> p=works(mid);
        if(p.first){
            r=mid;
            ans = p.second;
        }
        else{
            l=mid;
        }
    }
    cout << fixed << setprecision(6) <<  l << '\n';
    for(auto i : ans){
        cout << fixed << setprecision(6) << i << ' ';
    }
}