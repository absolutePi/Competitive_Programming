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
    vector<int> v(n);
    for(auto &i : v){cin >> i;}
    priority_queue<int> taken;
    taken.push(min(-v[0],-v[1]));
    for(int i=2;i<n;i+=2){
        int smallest_taken = taken.top();

        if(smallest_taken>max(-v[i],-v[i+1])){
            taken.pop();
            taken.push(-v[i]);
            taken.push(-v[i+1]);
        }
        else{
            taken.push(min(-v[i],-v[i+1]));
        }
    }
    ll ans = 0;
    while(!taken.empty()){
        ans -= taken.top();
        taken.pop();
    }
    cout << ans;
}