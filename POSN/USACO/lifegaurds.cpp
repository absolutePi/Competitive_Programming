#include <bits/stdc++.h>

using namespace std;

int firing(vector<int> arr,int start,int end){
    int cnt=0;
    for(int i=start+1;i<=end;i++){
        arr[i]--;
    }
    for(int i=0;i<=1000;i++){
        if(arr[i])cnt++;
    }
    return cnt;
}

int main(){
    freopen("lifeguards.in","r",stdin);
    freopen("lifeguards.out","w",stdout);
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    vector<int> arr(1001),arr2(1001);
    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
        for(int j=v[i].first+1;j<=v[i].second;j++){
            arr[j]++;
        }
    }
    int mx = INT_MIN;
    // for(int i=0;i<=9;i++){
    //     cout << arr[i];
    // }
    // puts("");
    for(auto i : v){
        arr2=arr;
        mx = max(mx,firing(arr2,i.first,i.second));
    }
    // for(int i=0;i<=9;i++){
    //     cout << arr[i];
    // }
    // puts("");
    cout << mx;
}