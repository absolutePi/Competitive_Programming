#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n,m;
queue<pair<int,int>> q;
int dist[N][N];
pair<int,int> from[N][N];
pair<int,int> a;
bool is_a=false;
bool pos=false;
int mx[]={1,-1,0,0},my[]={0,0,1,-1};
vector<char> ans;

void retrace(pair<int,int> curr){
    pair<int,int> origin=from[curr.first][curr.second];
    if(origin==pair<int,int>(-1,-1)){return;}
    if(origin.first==curr.first+1){
        ans.push_back('U');
    }
    if(origin.first==curr.first-1){
        ans.push_back('D');
    }
    if(origin.second==curr.second+1){
        ans.push_back('L');
    }
    if(origin.second==curr.second-1){
        ans.push_back('R');
    }
    retrace(origin);
}

void bfs(){
    while(!q.empty()){
        auto curr=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x=curr.first+mx[i];
            int y=curr.second+my[i];
            if(dist[curr.first][curr.second]+1<dist[x][y]){
                dist[x][y]=dist[curr.first][curr.second]+1;
                q.push({x,y});
                from[x][y]=curr;
            }
        }
        if(is_a&&(curr.first==0 || curr.first==n-1||curr.second==0||curr.second==m-1)){
            cout << "YES" << '\n' << dist[curr.first][curr.second] << '\n';
            retrace(curr);
            pos=true;
            return;
        }
    }
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++){
            dist[i][j]=INT_MAX;
            if(s[j]=='#')dist[i][j]=0;
            if(s[j]=='M'){
                q.push({i,j});
                dist[i][j]=0;
            }
            if(s[j]=='A'){
                a.first=i;
                a.second=j;
            }
        }
    }
    bfs();
    is_a=true;
    q.push(a);
    from[a.first][a.second]={-1,-1};
    dist[a.first][a.second]=0;
    bfs();
    if(pos){
        reverse(ans.begin(),ans.end());
        for(auto i : ans){
            cout << i;
        }
    }
    else{
        cout << "NO" << '\n';
    }
}