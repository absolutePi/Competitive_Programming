#include <bits/stdc++.h>

using namespace std;

vector<int> blame;
vector<bool> visited;
int n;

void solve(int node){
    if(visited[node]){
        cout << node+1 << ' ';
        return;
    }
    else{
        visited[node]=true;
        solve(blame[node]);
    }
    return;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n;
    blame = vector<int>(n);
    for(int i=0;i<n;i++){
        cin >> blame[i];
        blame[i]--;
    }
    for(int i=0;i<n;i++){
        visited = vector<bool>(n);
        solve(i);
    }
}