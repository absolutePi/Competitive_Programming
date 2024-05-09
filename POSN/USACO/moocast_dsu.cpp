#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int>> cows;
const int N = 1005;
int par[N];

int find(int x){
    if(par[x]!=x){return par[x]=find(par[x]);}
    else return x;
}

void unite(int x,int y){
    int a=find(x);
    int b=find(y);
    if(a==b){return;}
    par[a]=b;
    return;
}

bool within(int a,int b,int curr){
    return (cows[a].first-cows[b].first)*(cows[a].first-cows[b].first)+(cows[a].second-cows[b].second)*(cows[a].second-cows[b].second)<=curr;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    cin >> n;
    cows.resize(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        cows[i]={a,b};
    }
    int l=0,r=2e9,ans;
    while(l<=r){
        int mid=l+(r-l)/2;
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(find(i)!=find(j)&&within(i,j,mid)){
                    unite(i,j);
                }
            }
        }
        bool pos=true;
        int check=find(0);
        for(int i=1;i<n;i++){
            if(find(i)!=check){
                pos=false;
                break;
            }
        }
        if(pos){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout << ans << '\n';
}   