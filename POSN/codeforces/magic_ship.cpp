#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll days;
string str;

bool check(ll time,ll x1,ll y1,ll x2,ll y2){
    ll x=0,y=0;
    //changes in 1 cycle
    for(int i=0;i<days;i++){
        if(str[i]=='U')y++;
        else if(str[i]=='D')y--;
        else if(str[i]=='R')x++;
        else if(str[i]=='L')x--;
    }
    x1+=x*(time/days);
    y1+=y*(time/days);
    for(int i=0;i<(time%days);i++){
        if(str[i]=='U')y1++;
        else if(str[i]=='D')y1--;
        else if(str[i]=='R')x1++;
        else if(str[i]=='L')x1--;
    }
    return (abs(x2-x1)+abs(y2-y1))<=time;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll x1,y1,x2,y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> days;
    cin >> str;
    ll l=1,r=1e18,time,ans=-1;
    while(l<r){
        time = l+(r-l)/2;
        if(check(time,x1,y1,x2,y2)){
            ans=time;
            r=time;
        }
        else{
            l=time+1;
        }
    }
    cout << ans;
}