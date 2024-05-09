#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

using cow = pair<int,pair<int,int>>;

int main(){
    freopen("convention2.in","r",stdin);
    freopen("convention2.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<cow> cows;
    for(int i=n;i>0;i--){
        int str,d,s=i;
        cin >> str >> d;
        cows.pb({s,{str,d}});
    }
    cows.pb({0,{INT_MAX,0}});

    #define arrival s.f
    #define duration s.s
    #define seniority f
    sort(all(cows),[&](const cow &a,const cow &b){
        if(a.arrival!=b.arrival)return a.arrival<b.arrival;
        else{return a.seniority>b.seniority;}
    });

    priority_queue<cow> waitList;

    int time=0,ans=0;

    for(int i=0;i<n+1;){
        cow c = cows[i];

        if(c.arrival > time && waitList.empty()){
            time=c.arrival+c.duration;
            i++;
        }
        else if(c.arrival>time){
            cow x = waitList.top();
            waitList.pop();

            ans = max(ans,time-x.arrival);

            time+=x.duration;
        }
        else{
            waitList.push(c);
            i++;
        }
    }
    cout << ans;
}