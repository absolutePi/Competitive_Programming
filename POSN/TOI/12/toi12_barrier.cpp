#include <bits/stdc++.h>

using namespace std;

const int N = 6e6+6;
#define ll long long
ll prf[N];
ll sum,ans;
int length;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        prf[i]=prf[i-1]+a;
    }
    deque<pair<int,ll>> q;
    q.push_front({0,0});
    for(int i=1;i<=n;i++){
        while(!q.empty()&&i-q.front().first>k){q.pop_front();}
        while(!q.empty()&&prf[i]<=q.back().second){q.pop_back();}
        q.push_back({i,prf[i]});
        sum=prf[i]-q.front().second;
        if(sum>ans){
            ans=sum;
            length=i-q.front().first;
        }
        else if(sum==ans){
            length=min(length,i-q.front().first);
        }
    }
    cout << ans << '\n' << length;
}