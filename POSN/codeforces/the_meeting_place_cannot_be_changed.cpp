#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define db double

const db MAX_ERROR=10e-7;

vector<db> locations;
vector<db> speeds;

db ans=(db)INT_MAX;
db curr_min_time;
bool left_max = false;
bool right_max = false;

db gyaatt(db mid){
    db max_time=0;
    for(int i=0;i<locations.size();i++){
        if(locations[i]==mid){continue;}
        db time=abs(mid-locations[i])/speeds[i];
        if(time>max_time){
            max_time=time;
            left_max=false;
            right_max=false;
            if(locations[i]>mid){
                right_max=true;
            }
            else{
                left_max=true;
            }
        }
        else if(time==max_time){
            if(locations[i]>mid){
                right_max=true;
            }
            else{
                left_max=true;
            }
        }
    }
    return max_time;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    locations.resize(n);
    speeds.resize(n);
    db l=0,r=0,mid;
    for(int i=0;i<n;i++){
        cin >> locations[i];
        r=max(r,locations[i]);
    }
    for(auto &i : speeds){cin >> i;}
    while(r-l>MAX_ERROR){
        mid=l+(r-l)/2;
        curr_min_time=gyaatt(mid);
        ans=min(ans,curr_min_time);
        if(left_max&&right_max){break;}
        else if(right_max){l=mid;}
        else{r=mid;}
    }
    cout << fixed << ans;
}   