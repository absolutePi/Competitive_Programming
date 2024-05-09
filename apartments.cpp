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
    int n,m,d;
    cin >> n >> m >> d;
    vector<int> apli(n),aprt(m);
    for(auto &i : apli){cin >> i;}
    for(auto &i : aprt){cin >> i;}
    sort(all(apli));
    sort(all(aprt));
    int i=0,j=0,ans=0;
    while(i<n&&j<m){
        if(abs(apli[i]-aprt[j])<=d){
            ans++;
            i++;
            j++;
        }
        else{
            if(apli[i]>aprt[j])j++;
            else i++;
        }
    }
    cout << ans;
}