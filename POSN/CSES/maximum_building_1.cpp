#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
char grid[N][N];
queue<int> q[N];

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
            if(grid[i][j]=='*'){
                q[j].push(i);
            }
        }
    }
    for(int j=0;j<m;j++){
        q[j].push(n);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(q[j].front()<i){q[j].pop();}
        }
        stack<pair<int,int>> s;
        for(int j=0;j<m;j++){
            int start=j;
            while(!s.empty()&&q[j].front()-i<s.top().second){
                pair<int,int> curr=s.top();
                s.pop();
                start=curr.first;
                ans=max(ans,(j-curr.first)*curr.second);
            }
            s.push({start,q[j].front()-i});
        }
        while(!s.empty()){
            pair<int,int> curr=s.top();
            s.pop();
            ans=max(ans,(m-curr.first)*curr.second);
        }
    }
    cout << ans << '\n';
}