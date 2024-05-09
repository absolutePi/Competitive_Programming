#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+5;
vector<int> rel(N);
vector<bool> diameter(N);

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> rel[i];
        rel[i]--;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(!diameter[rel[i]]){
            diameter[rel[i]]=diameter[rel[rel[i]]]=true;
            ans++;
        }
    }
    cout << ans;
}   