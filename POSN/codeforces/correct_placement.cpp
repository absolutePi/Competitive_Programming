#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Friend{
    int mx;
    int mn;
    int id;
};

bool cmp(const Friend &a,const Friend &b){
    if(a.mx==b.mx){return a.mn>b.mn;}
    else return a.mx<b.mx;
}

void solve(){
    int n;
    cin >> n;
    vector<Friend> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i].mx >> v[i].mn;
        v[i].id = i;
        if(v[i].mx<v[i].mn)swap(v[i].mx,v[i].mn);
    }
    sort(v.begin()+1,v.end(),cmp);
    vector<int> overlap(n+1,-1);
    int x = v[1].id, y = v[1].mn;
    for(int i=2;i<=n;i++){
        if(v[i].mn>y){
            overlap[v[i].id]=x;
        }
        else{
            x = v[i].id;
            y = v[i].mn;
        }
    }
    for(int i=1;i<=n;i++){
        cout << overlap[i] << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}