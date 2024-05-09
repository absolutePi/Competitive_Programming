#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i : v){cin >> i;}
    map<int,pair<int,int>> max_end_at;//key = value to max_end and indice
    vector<int> succ(n+1);
    int best_length=1;
    for(int i=0;i<n;i++){
        int curr=v[i];
        if(!max_end_at.count(curr-1)){
            max_end_at[curr]={1,i};
            succ[i]=-1;
        }
        else{
            int new_length=max_end_at[curr-1].first+1;
            if(!max_end_at.count(curr)||new_length>max_end_at[curr].first){
                max_end_at[curr]={new_length,i};
                best_length=max(best_length,new_length);
                succ[i]=max_end_at[curr-1].second;
            }   
        }
    }
    int at_ind=-1;
    for(auto i : max_end_at){
        if(i.second.first==best_length){
            at_ind=i.second.second;
        }
    }
    vector<int> rev;
    for(int i=0;i<best_length;i++){
        rev.push_back(at_ind);
        at_ind=succ[at_ind];
    }
    cout << best_length << '\n';
    for(int i=best_length-1;i>=0;i--){
        cout << rev[i]+1 << ' ';
    }
    cout << '\n';
}   