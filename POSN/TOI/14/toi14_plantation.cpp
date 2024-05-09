#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
pair<int,int> pos[N];
int n,r,d;

double dis(const pair<int,int> &a,const pair<int,int> &b){
    double dx=a.first-b.first;
    double dy=a.second-b.second;
    return sqrt(dx*dx+dy*dy);
}

bool bf(int lim,int l,int r){
    for(int i=l;i<r;i++){
        for(int j=i+1;j<r;j++){
            if(dis(pos[i],pos[j])<lim)return false;
        }
    }
    return true;
}

bool closest(int lim,int l,int r){
    if(r-l<3){return bf(lim,l,r);}
    int mid=l+(r-l)/2;
    if(!closest(lim,l,mid))return false;
    if(!closest(lim,mid+1,r))return false;
    return bf(lim,max(l,mid-3),min(mid+3,r));
}

void solve(){
    cin >> n >> r >> d;
    for(int i=0;i<n;i++){
        cin >> pos[i].first >> pos[i].second;
    }
    sort(pos,pos+n);
    int lim=2*r+d;
    if(closest(lim,0,n)){
        cout << "Y" << '\n';
    }
    else{
        cout << "N" << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
}