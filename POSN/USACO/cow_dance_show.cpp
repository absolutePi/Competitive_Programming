#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

int main(){
    freopen("cowdance.in","r",stdin);
    freopen("cowdance.out","w",stdout);
    //ios::sync_with_stdio(false);
    //in.tie(NULL);
    int n,tmax;
    cin >> n >> tmax;
    vector<int> v(n);
    for(auto &i : v){cin >> i;}
    int l=1,r=n,ans=n;
    while(l<=r){
        int mid = l+(r-l+1)/2;
        int time = 0,j=0;
        priority_queue<int> pq;
        int size = 0 ;
        while(size<mid && j<n){
            pq.push(-v[j]);
            size++;
            j++;
        }
        while(!pq.empty()){
            time+=max(0,-pq.top()-time);
            pq.pop();
            if(j<n){
                pq.push(-(v[j]+time));
                j++;
            }
        }
        if(time>tmax){
            l = mid+1;
        }
        else{
            ans = min(ans,mid);
            r = mid-1;
        }
    }
    cout << ans;
}