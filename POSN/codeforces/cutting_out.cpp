#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;
int n,k;
vector<int> cnts(N);
vector<int> t;

bool works(int cnt){
    t.clear();
    for(int i=0;i<N;i++){
        int need = min(k-(int)t.size(),cnts[i]/cnt);
        for(int j=0;j<need;j++){
            t.push_back(i);
        }
    }
    return t.size()==k;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        cnts[x]++;
    }
    int l=0,r=n,mid;
    while(r-l>1){
        mid = l+(r-l)/2;
        if(works(mid)){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    if(!works(r))works(l);
    for(auto i : t){
        cout << i << ' ';
    }
}   