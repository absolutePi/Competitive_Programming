#include <bits/stdc++.h>

using namespace std;

#define int long long 
const int N =  1e5+5;
int a[N],temp[N],qs[N],ans=0;

void msort(int l,int r){
    if(l==r)return;
    int mid=l+(r-l)/2;
    msort(l,mid);
    msort(mid+1,r);
    for(int i=l;i<=r;i++){
        qs[i]=qs[i-1]+a[i];
    }
    int i=l,j=mid+1,ind=l;
    while(i<=mid&&j<=r){
        if(a[i]<a[j]){
            temp[ind++]=a[i++]; 
        }
        else{
            temp[ind++]=a[j];
            ans+=qs[mid]-qs[i-1]+(a[j]*(mid-i+1));
            j++;
        }
    }
    while(i<=mid)temp[ind++]=a[i++];
    while(j<=r)temp[ind++]=a[j++];
    for(int i=l;i<=r;i++)a[i]=temp[i];
    return;
}

signed main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        a[y]=x;
    }
    msort(1,n);
    cout << ans << '\n';
}