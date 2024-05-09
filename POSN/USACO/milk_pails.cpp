#include <bits/stdc++.h>

using namespace std;

bool visited[101][101][101];
int x,y,k,m;//x cap,y cap,k op,needs m
int ans;

void solve(int left,int right,int op){//left buket and right bucket
    if(visited[left][right][op]||op>k){return;}
    visited[left][right][op]=true;
    ans=min(ans,abs(m-(left+right)));
    //case 1
    solve(x,right,op+1);
    solve(left,y,op+1);
    //case 2;
    solve(0,right,op+1);
    solve(left,0,op+1);
    //case 3
    int leftOverX=left+right>y?left-(y-right) : 0;
    int leftOverY=right+left>x?right-(x-left) : 0;
    solve(leftOverX,min(y,left+right),op+1);
    solve(min(x,left+right),leftOverY,op+1);
    return;
}

int main(){
    freopen("pails.in","r",stdin);
    freopen("pails.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);   
    cin >> x >> y >> k >> m;
    ans=m;
    solve(0,0,0);
    cout << ans;
}