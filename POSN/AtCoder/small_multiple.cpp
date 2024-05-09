#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int k;
    cin >> k;
    vector<int> dist(k,INT_MAX);
    queue<int> q;
    q.push(1);
    dist[1]=1;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        int case1=(curr*10)%k;
        if(dist[curr]<dist[case1]){
            dist[case1]=dist[curr];
            q.push(case1);
        }
        int case2=(curr+1)%k;
        if(dist[curr]<dist[case2]){
            dist[case2]=dist[curr]+1;
            q.push(case2);
        }
    }
    cout << dist[0] << '\n';
}   