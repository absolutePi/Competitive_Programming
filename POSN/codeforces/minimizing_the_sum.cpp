#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    priority_queue<tuple<int,int,int>> q;
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(i){
            q.push({abs(v[i]-v[i-1]),i-1,i});
        }
    }
    int cnt=0;
    while(!q.empty()&&cnt<k){
        int dif,ind1,ind2;
        tie(dif,ind1,ind2)=q.top();q.pop();
        if(abs(v[ind1]-v[ind2])!=dif)continue;
        cnt++;
        if(v[ind1]>v[ind2])swap(ind1,ind2);
        v[ind2]=v[ind1];
        if(ind2)q.push({abs(v[ind2]-v[ind2-1]),ind2-1,ind2});
        if(ind2+1<n)q.push({abs(v[ind2]-v[ind2+1]),ind2,ind2+1});
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
    }
    cout << sum << '\n';
}

signed main(){
    int t;
    cin >> t;
    while(t--)solve();
}