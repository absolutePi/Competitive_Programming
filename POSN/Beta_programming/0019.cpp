#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

int n,ans=INT_MAX;
vector<pair<int,int>> ing;

void solve(int i,int salt,int bitter){
    if(i==n){
        if(bitter==0)return;
        ans = min(ans,abs(bitter-salt));
    }
    else{
        solve(i+1,salt*ing[i].f,bitter+ing[i].s);
        solve(i+1,salt,bitter);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ing.resize(n);
    for(auto &i : ing){
        cin >> i.f >> i.s;
    }
    solve(0,1,0);
    cout << ans;
}