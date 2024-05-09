#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<pair<int,int>,int>> v(n);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        cin >> v[i].f.f >> v[i].f.s;
        v[i].s = i;
    }
    sort(all(v));

    int rooms = 0;
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<n;i++){
        if(pq.empty()){
            rooms++;
            pq.push({-v[i].f.s,rooms});
            ans[v[i].s]=rooms;
        }
        else{
            pair<int,int> mn = pq.top();
            if(-mn.f<v[i].f.f){
                pq.pop();
                pq.push({-v[i].f.s,mn.s});
                ans[v[i].s]=mn.s;
            }
            else{
                rooms++;
                pq.push({-v[i].f.s,rooms});
                ans[v[i].s]=rooms;
            }
        }
    }
    cout << rooms << endl;
    for(auto i : ans){cout << i << " ";}
}