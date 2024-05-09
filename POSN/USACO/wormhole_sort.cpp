#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("wormsort.in","r",stdin);
    freopen("wormsort.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> cows(n);
    for(auto &i : cows){
        cin >> i;
        i--;
    }
    vector<vector<pair<int,int>>> adj(n);
    int max_width=0;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        a--;b--;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
        max_width=max(max_width,w);
    }
    int l=0,r=max_width+1,mid,ans=-1;
    while(l<=r){
        mid=l+(r-l)/2;//min width
        int curr_father=0;
        vector<int> comp(n,-1);
        for(int i=0;i<n;i++){
            if(comp[i]!=-1){continue;}
            vector<int> frontier{i};
            while(!frontier.empty()){
                int curr=frontier.back();
                frontier.pop_back();
                comp[curr]=curr_father;
                for(const auto &[n,w] : adj[curr]){
                    if(w>=mid && comp[n]==-1){
                        frontier.push_back(n);
                    }
                }
            }
            curr_father++;
        }
        bool valid=true;
        for(int i=0;i<n;i++){
            if(comp[i]!=comp[cows[i]]){
                valid=false;
                break;
            }
        }
        if(valid){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout << (ans==max_width+1 ? -1 : ans) << endl;
}   