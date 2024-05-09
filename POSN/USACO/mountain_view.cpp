#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

struct Mountain{
    int start;
    int end;
};

bool cmp(const Mountain &a,const Mountain &b){
    if(a.start==b.start){return a.end>b.end;}
    else return a.start<b.start;
}

int main(){
    freopen("mountains.in","r",stdin);
    freopen("mountains.out","w",stdout);
    int n;
    cin >> n;
    vector<Mountain> m;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        m.push_back({x-y,x+y});
    }
    sort(m.begin(),m.end(),cmp);
    int able_toc=0;
    int mx_right = INT_MIN;
    for(const Mountain &i : m){
        if(i.end>mx_right){
            mx_right = i.end;
            able_toc++;
        }
    }
    cout << able_toc;
}