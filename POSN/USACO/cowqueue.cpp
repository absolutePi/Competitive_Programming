#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("cowqueue.in","r",stdin);
    freopen("cowqueue.out","w",stdout);
    int n;
    cin >> n;
    vector<pair<int,int>> cow(n);
    for(int i=0;i<n;i++){
        cin >> cow[i].first >> cow[i].second;
    }
    sort(cow.begin(),cow.end());
    int cur_time = 0;
    for(int i=0;i<n;i++){
        if(cow[i].first>cur_time){
            cur_time = cow[i].first;
        }
        cur_time+=cow[i].second;
    }
    cout << cur_time;
}