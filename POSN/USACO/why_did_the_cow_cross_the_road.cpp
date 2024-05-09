#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

int main(){
    freopen("helpcross.in","r",stdin);
    freopen("helpcross.out","w",stdout);
    //ios::sync_with_stdio(false);
    //in.tie(NULL);
    int c,n;
    cin >> c >> n;
    vector<int> chickens(c);
    vector<pair<int,int>> cows(n);
    for(auto &i : chickens){cin >> i;}
    for(auto &i : cows){cin >> i.f >> i.s;}
    sort(all(chickens));
    sort(all(cows));

    priority_queue<int> end_cow;
    int at_cow=0,ans=0;
    for(auto c : chickens){
        while(at_cow<n && cows[at_cow].f<=c){
            end_cow.push(-cows[at_cow].s);
            at_cow++;
        }
        while(!end_cow.empty()&&-end_cow.top()<c){
            end_cow.pop();
        }
        if(!end_cow.empty()){
            ans++;
            end_cow.pop();
        }
    }
    cout << ans;
}