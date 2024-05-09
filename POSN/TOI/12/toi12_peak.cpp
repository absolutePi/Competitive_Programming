#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> peaks(n);
    for(auto &i : peaks){cin >> i;}
    vector<int> den;
    for(int i=0;i<n;i++){
        if(n==1){
            den.push_back(peaks[i]);
            break;
        }
        if(i==0){
            if(peaks[i]>peaks[i+1]){
                den.push_back(peaks[i]);
            }
        }
        else if(i==n-1){
            if(peaks[i]>peaks[i-1]){
                den.push_back(peaks[i]);
            }
        }
        else{
            if((peaks[i]>peaks[i-1])&&(peaks[i]>peaks[i+1])){
                den.push_back(peaks[i]);
            }
        }
    }
    if(den.empty()){
        cout << -1 << '\n';
        return 0;
    }
    sort(den.begin(),den.end(),greater<int>());
    vector<int> ans;
    int num=0;
    for(int i=0;i<den.size();i++){
        if(i==0){
            num++;
            ans.push_back(den[i]);
        }
        else{
            if(den[i]==den[i-1]){continue;}
            else{
                num++;
                ans.push_back(den[i]);
            }
        }
        if(num==k){break;}
    }
    if(num==k){
        for(auto i : ans){
            cout << i << '\n';
        }
    }
    else{
        reverse(ans.begin(),ans.end());
        for(auto i : ans){
            cout << i << '\n';
        }
    }
}