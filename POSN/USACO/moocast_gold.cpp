#include <bits/stdc++.h>

using namespace std;

int dist(const pair<int,int> &a,const pair<int,int> &b){
    int x=a.first-b.first;
    int y=a.second-b.second;
    return x*x+y*y;
}

bool all_reachable(int power,vector<pair<int,int>> &cows){
    int start=0;
    queue<int> q;
    vector<bool> reached(cows.size());
    q.push(start);
    reached[start]=true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i=0;i<cows.size();i++){
            if(!reached[i]&&dist(cows[curr],cows[i])<=power){
                q.push(i);
                reached[i]=true;
            }
        }
    }
    for(auto i : reached){
        if(!i){
            return false;
        }
    }
    return true;
}

int main(){
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> cows(n);
    for(auto &i : cows){
        cin >> i.first >> i.second;
    }
    int l=0,r=INT_MAX,mid,ans;
    while(l<r){
        mid=l+(r-l)/2;
        if(all_reachable(mid,cows)){
            ans=mid;
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout << ans;
}