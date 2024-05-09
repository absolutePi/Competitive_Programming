#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
int prf[N];
int n,q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        prf[i]=prf[i-1]+a;
    }
    vector<pair<int,int>> customers(q);//money,index
    for(int i=0;i<q;i++){
        int a;
        cin >> a;
        customers[i]={a,i};
    }
    sort(customers.begin(),customers.end(),greater<pair<int,int>>());
    priority_queue<pair<int,int>> pq;
    for(int i=1;i<=n;i++){
        if(prf[i]<=customers[0].first){
            pq.push({i,prf[i]});
        }
    }
    vector<int> ans(q);
    for(int i=0;i<q;i++){
        while(!pq.empty()&&customers[i].first<pq.top().second)pq.pop();
        if(pq.empty()){
            ans[customers[i].second]=0;
        }
        else{
            ans[customers[i].second]=pq.top().first;
        }
    }
    for(auto i : ans){
        cout << i << "\n";
    }
}