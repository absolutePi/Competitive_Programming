#include <bits/stdc++.h>

using namespace std;

const int K = 20005;
const int P = 20;
pair<pair<int,int>,pair<int,int>> pos[K];
int dist[P][K];

int dif(pair<pair<int,int>,pair<int,int>> &a,pair<pair<int,int>,pair<int,int>> &b){
    return abs(a.second.first-b.first.first)+abs(a.second.second-b.first.second);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m,n;//row col
    cin >> m >> n;
    int k,p;//portals key
    cin >> k >> p;
    pos[0]={{1,1},{1,1}};
    for(int i=1;i<=k;i++){
        int inx,iny,outx,outy;
        cin >> inx >> iny >> outx >> outy;
        pos[i]={{inx,iny},{outx,outy}};
    }
    pos[k+1]={{m,n},{m,n}};
    for(int i=1;i<=p;i++){
        for(int j=1;j<=k+1;j++){
            dist[i][j]=INT_MAX;
        }
    }
    for(int i=1;i<=k+1;i++){
        dist[0][i]=dif(pos[0],pos[i]);
    }
    dist[0][0]=0;
    for(int key=1;key<=p;key++){
        for(int i=1;i<=k;i++){
            for(int j=1;j<=k+1;j++){
                dist[key][j]=min(dist[key][j],dist[key-1][i]+dif(pos[i],pos[j]));
            }
        }
    }
    int ans=INT_MAX,key_used;
    for(int i=0;i<=p;i++){
        if(dist[i][k+1]<ans){
            ans=dist[i][k+1];
            key_used=i;
        }
    }
    cout << ans << ' ' << key_used << '\n';
}