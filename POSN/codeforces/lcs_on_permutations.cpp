#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
int a[N],b[N],c[N],pos[N];
vector<int> lcs;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pos[a[i]]=i;
    }
    for(int i=1;i<=n;i++){cin >> b[i];}
    for(int i=1;i<=n;i++){c[i]=pos[b[i]];}
    for(int i=1;i<=n;i++){
        int p=lower_bound(lcs.begin(),lcs.end(),c[i])-lcs.begin();
        if(p==lcs.size()){
            lcs.push_back(c[i]);
        }
        else{
            lcs[p]=c[i];
        }
    }
    cout << lcs.size();
}