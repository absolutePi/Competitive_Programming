#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

int main(){
    //ios::sync_with_stdio(false);
    //in.tie(NULL);
    int n,x;
    cin >> n >> x;
    vector<int> algo(n);
    for(auto &i : algo){cin >> i;}
    sort(all(algo));
    int cnt=0,spent=0;
    for(int i=0;i<n;i++){
        if(spent+algo[i]>x){break;}
        else{
            spent+=algo[i];
            cnt++;
        }
    }
    cout << cnt;
}