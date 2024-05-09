#include <bits/stdc++.h>

using namespace std;

const int N = 4e5+5;

int lds[N],temp[N],ans[N];

struct Mountain{
    int l,r,index;
};

bool cmp(const Mountain &a,const Mountain &b){
    if(a.l==b.l)return a.r>b.r;
    return a.l<b.l;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Mountain> mountains(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        mountains[i]={a,b,i};
    }
    sort(mountains.begin(),mountains.end(),cmp);
    int sz=0;
    for(int i=n-1;i>=0;i--){
        int right=mountains[i].r;
        int ind=upper_bound(lds,lds+sz,right)-lds;
        if(ind==sz){
            lds[ind]=right;
            sz++;
        }
        else{
            lds[ind]=right;
        }
        temp[i]=ind+1;
    }
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        ans[mountains[i].index]=temp[i];
        mx=max(mx,temp[i]);
    }
    cout << mx << '\n';
    for(int i=0;i<n;i++){
        cout << ans[i] << ' ';
    }
}