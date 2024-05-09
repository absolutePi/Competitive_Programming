#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int> 
const int N = 5e5+5;
int a[N];

int main(){
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(int i=0;i<n;i++){
        if(pq.empty()){
            pq.push({a[i],i});
        }
        else{
            while(i-pq.top().second>k)pq.pop();
            pq.push({a[i]+pq.top().first,i});
        }
    }
    while(pq.top().second!=n-1)pq.pop();
    cout << pq.top().first;
}