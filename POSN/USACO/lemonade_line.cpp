#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

int main(){
    freopen("lemonade.in","r",stdin);
    freopen("lemonade.out","w",stdout);
    //ios::sync_with_stdio(false);
    //in.tie(NULL);
    int n;
    cin >> n;
    vector<int> cows(n);
    for(auto &i : cows){cin >> i;}
    sort(all(cows),greater<int>());

    int curr_cows=0;
    for(auto i : cows){
        if(i<curr_cows){break;}
        curr_cows++;
    }
    cout << curr_cows;
}