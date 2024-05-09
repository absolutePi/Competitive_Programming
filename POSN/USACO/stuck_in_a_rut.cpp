#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

bool stopped[1002];


bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    if(a.f.s!=b.f.s){return a.f.s<b.f.s;}
    return a.f.f<b.f.f;
}

int main(){
    int n;
    cin >> n;
    vector<int> ans(n);
    vector<pair<pair<int,int>,int>> east,north;
    for(int i=0;i<n;i++){
        char c;
        int x,y;
        cin >> c >> x >> y;
        if(c=='E'){east.pb({{x,y},i});}
        else north.pb({{x,y},i});
    }
    sort(all(north));
    sort(all(east),cmp);
    for(auto e : east){
        for(auto n : north){
            int timen = e.f.s-n.f.s;
            int timee = n.f.f-e.f.f;
            if(stopped[e.s] || stopped[n.s]){continue;}
            if(timen==timee || timen<0 || timee<0){continue;}
            if(timee<timen){
                stopped[n.s]=true;
                ans[e.s]+=1+ans[n.s];
            }
            else{
                stopped[e.s]=true;
                ans[n.s]+=1+ans[e.s];
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << ans[i] << endl;
    }
}