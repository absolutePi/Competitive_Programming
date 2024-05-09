#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;
int dest[N];
bool visited[N];
int path_length[N];
int steps;
int decrement;
queue<int> path;

void dfs(int node){
    path.push(node);
    if(visited[node]){
        steps+=path_length[node];
        return;
    }
    visited[node]=true;
    steps++;
    dfs(dest[node]);

}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> dest[i];
        dest[i]--;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            steps=0;
            decrement=1;
            dfs(i);
            while(!path.empty()){
                //if in a cycle
                if(path.front()==path.back()){
                    decrement=0;
                }
                int cur = path.front();
                path.pop();
                path_length[cur]=steps;
                steps-=decrement;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << path_length[i] << ' ';
    }
}