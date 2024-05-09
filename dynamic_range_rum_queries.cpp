#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int N = 3e5+5;
int n,q,arr[N];
ll seg[N*4];

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
    seg[curr]=seg[curr*2+1]+seg[curr*2+2];
}

ll get_sum(int L,int R,int curr=0,int l=0,int r=n-1){
    if(r<L||l>R){return 0;}
    if(l>=L&&r<=R){return seg[curr];}
    int mid=(l+r)/2;
    return get_sum(L,R,curr*2+1,l,mid)+get_sum(L,R,curr*2+2,mid+1,r);
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
            int l,r;
            cin >> l >> r;
            l--;r--;
            cout << get_sum(l,r) << '\n';
        }
    }
}