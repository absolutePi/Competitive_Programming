#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int F = 105;
const int INF=1e9+7;
int n,start,target,fuel_cost[N],cap,m;
vector<pair<int,int>> adj[N];
int dist[N][F][2];//node fuel coupoun_status

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> fuel_cost[i];
    }
    cin >> start >> target >> cap;
    start--;target--;
    cin >> m;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[--a].push_back({--b,w});
        adj[b].push_back({a,w});
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=cap;j++){
            for(int k=0;k<2;k++){
                dist[i][j][k]=INF;
            }
        }
    }
    dist[start][0][1]=0;//at node start,have no fuel,1 coupon left
    priority_queue<tuple<int,int,int,int>,vector<tuple<int,int,int,int>>,greater<tuple<int,int,int,int>>> pq;
    pq.push({0,start,0,1});//curr_money currr_node curr_fuel coupon status
    while(!pq.empty()){
        int money=get<0>(pq.top());
        int node=get<1>(pq.top());
        int fuel=get<2>(pq.top());
        int coupon=get<3>(pq.top());
        pq.pop();
        if(fuel<cap&&(dist[node][fuel+1][coupon]>money+fuel_cost[node])){//consider filling 1 more unit of fuel
            dist[node][fuel+1][coupon]=money+fuel_cost[node];
            pq.push({money+fuel_cost[node],node,fuel+1,coupon});
        }   
        if(coupon==1&&(dist[node][cap][0]>money)){//consider filling the whole tank using a coupon
            dist[node][cap][0]=money;
            pq.push({money,node,cap,0});
        }
        for(auto u : adj[node]){
            int nx=u.first;
            int weight=u.second;
            if(fuel>=weight&&(dist[nx][fuel-weight][coupon]>money)){//moving on to the next node
                dist[nx][fuel-weight][coupon]=money;
                pq.push({money,nx,fuel-weight,coupon});
            }
        }
    }
    cout << dist[target][cap][0];
}