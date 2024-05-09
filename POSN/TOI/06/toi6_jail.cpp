#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    queue<int> q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    while(!q.empty()){
        for(int i=1;i<m;i++){
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ' ';
        q.pop();
    }
}           