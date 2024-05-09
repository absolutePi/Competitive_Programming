#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+1;
int pos[N],cnt[N];

int main(){
    freopen("shell.in","r",stdin);
    int n,mx = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        pos[i] = i;
    }
    for(int i=0;i<n;i++){
        int a,b,g;
        cin >> a >> b >> g;
        a--;b--;g--;
        swap(pos[a],pos[b]);
        cnt[pos[g]]++;
    }
    for(int i=0;i<n;i++){
        mx = max(mx,cnt[i]);
    }
    freopen("shell.out","w",stdout);
    cout << mx;
}