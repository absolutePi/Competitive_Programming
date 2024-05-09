#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int a[N][N];
int roads,start,T;
int mj[]={69,-1,1,0};

bool within(int pos){
    return (pos>=1&&pos<=roads);
}

void dfs(int t,int pos,vector<int> ops){
    if(t==T){
        for(auto i : ops){
            cout << i << '\n';
        }
        return;
    }
    for(int i=1;i<=3;i++){
        if(within(pos+mj[i])&&a[t+1][pos+mj[i]]==0){
            ops.push_back(i);
            dfs(t+1,pos+mj[i],ops);
            ops.pop_back();
        }
    }
}

int main(){
    cin >> roads >> start >> T;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            a[i][j]=2e9;
        }
    }
    a[0][start]=0;
    for(int i=1;i<=T;i++){
        for(int j=1;j<=roads;j++){
            cin >> a[i][j];
        }
    }
    dfs(0,start,{});
}       