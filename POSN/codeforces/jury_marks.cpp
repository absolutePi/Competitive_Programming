#include <bits/stdc++.h>

using namespace std;

int main(){
    int k,n;
    cin >> k >> n;
    vector<int> changes(k+1);
    vector<int> remember(n);
    for(int i=1;i<=k;i++){
        cin >> changes[i];
        changes[i]+=changes[i-1];
    }
    for(auto &i : remember){
        cin >> i;
    }
    set<int> all_pos_start;
    for(int i=1;i<=k;i++){
        all_pos_start.insert(remember.front()-changes[i]);
    }
    int ans=0;
    for(int s : all_pos_start){
        set<int> points;
        for(int i=1;i<=k;i++){
            points.insert(s + changes[i]);
        }
        bool value = true;
        for(int p : remember){
            value &= points.count(p);
        }
        ans+=value;
    }
    cout << ans;
}
