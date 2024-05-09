#include <bits/stdc++.h>

using namespace std;

int n,d,m;

pair<bool,vector<vector<int>>> works(vector<pair<int,int>> &jobs,int machines){
    int temp=0;
    vector<vector<int>> schedule(n);
    for(int day=1;day<=n;day++){
        for(int mac=0;mac<machines;mac++){
            if(jobs[temp].first>day){
                break;
            }
            if(jobs[temp].first+d>=day){
                schedule[day-1].push_back(jobs[temp++].second);
            }
            else{
                return {false,schedule};
            }
            if(temp==m){return {true,schedule};}
        }
    }
    return {false,schedule};
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> d >> m;
    vector<pair<int,int>> jobs(m);
    for(int i=0;i<m;i++){
        int day;
        cin >> day;
        //date,index
        jobs[i] = {day,i+1};
    }
    sort(jobs.begin(),jobs.end());
    vector<vector<int>> ans;
    int l=0,r=m,mid;
    while(l<r){
        mid = l+(r-l)/2;
        pair<bool,vector<vector<int>>> res = works(jobs,mid);
        if(res.first){
            r=mid;
            ans = res.second;
        }
        else{
            l=mid+1;
        }
    }
    cout << l << endl;
    for(int i=0;i<n;i++){
        for(auto j : ans[i]){
            cout << j << ' ';
        }
        cout << 0 << endl;
    }
}