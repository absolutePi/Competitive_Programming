#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;
int n,q,arr[N],seg[N*4];
const int INF= 1e9+5;

void update(int id,int val,int curr=0,int l=0,int r=n-1){
    if(l==r){
        if(l==id){
            seg[curr]=val;
            return;
        }
    }
    if(id<l||id>r){return;}
    int mid=(l+r)/2;
    update(id,val,curr*2+1,l,mid);
    update(id,val,curr*2+2,mid+1,r);
    seg[curr]=min(seg[curr*2+1],seg[curr*2+2]);
}

int get_min(int L,int R,int curr=0,int l=0,int r=n-1){
    if(l>=L&&r<=R){return seg[curr];}
    if(l>R||r<L){return INF;}
    int mid=(l+r)/2;
    return min(get_min(L,R,curr*2+1,l,mid),get_min(L,R,curr*2+2,mid+1,r));
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        update(i,arr[i]);
    }
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t==1){
            int id,val;
            cin >> id >> val;
            id--;
            update(id,val);
        }
        else if(t==2){
            int L,R;
            cin >> L >> R;
            L--;R--;
            cout << get_min(L,R) << '\n';
        }
    }
}