#include <bits/stdc++.h>

using namespace std;

const int N=15005;
const int INF=1e9+7;
int dist[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> pos(n);
    for(auto &i : pos){
        cin >> i.first >> i.second;
    }
    memset(dist,INF,sizeof(dist));
    int curr_node=0,curr_min,curr_weight=0,next_node;
    vector<int> edges_used;
    for(int i=0;i<n-1;i++){//MST has n-1 edges->finding n-1 edges 
        curr_min=INF;//reset min
        dist[curr_node]=-1;//mark visited
        for(int j=0;j<n;j++){
            if(dist[j]==-1){continue;}
            dist[j]=min(dist[j],abs(pos[curr_node].first-pos[j].first)+abs(pos[curr_node].second-pos[j].second));
            if(dist[j]<curr_min){
                curr_min=dist[j];
                next_node=j;//next node we'll be traveling
            }
        }
        curr_weight+=curr_min;
        edges_used.push_back(curr_min);
        curr_node=next_node;
    }
    sort(edges_used.begin(),edges_used.end(),greater<int>());
    for(int i=0;i<k-1;i++){//subtracting the unnecessary edge
        curr_weight-=edges_used[i];
    }
    cout << curr_weight << '\n';
}   