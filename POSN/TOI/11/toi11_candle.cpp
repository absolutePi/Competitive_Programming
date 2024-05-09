#include <bits/stdc++.h>

using namespace std;

const int N = 2001;
int a[N][N];
int n,m;

int mx[]={-1,-1,0,+1,+1,+1,0,-1},my[]={0,+1,+1,+1,0,-1,-1,-1};

bool within(int x,int y){
    return (x>=0&&y>=0&&x<n&&y<m);
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int j=0;j<m;j++){
            a[i][j]=str[j]-'0';
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==1){
                ans++;
                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()){
                    pair<int,int> curr=q.front();
                    q.pop();
                    int r=curr.first;
                    int c=curr.second;
                    if(a[r][c]==0){continue;}
                    a[r][c]=0;
                    for(int k=0;k<8;k++){
                        int newr=r+mx[k];
                        int newc=c+my[k];
                        if(within(newr,newc)&&a[newr][newc]==1){
                            q.push({newr,newc});
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}