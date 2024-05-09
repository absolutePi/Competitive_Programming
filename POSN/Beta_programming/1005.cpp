#include <bits/stdc++.h>

using namespace std;

const int N = 2505;
int a[N];

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++)cin >> a[i];
    vector<int> v,ansv;
    int curr_sum=0,ans=INT_MIN;
    for(int i=0;i<n;i++){
        if(curr_sum+a[i]<a[i]){
            curr_sum=a[i];
            v.clear();v.push_back(a[i]);
        }
        else{
            curr_sum+=a[i];
            v.push_back(a[i]);
        }
        if(curr_sum>ans){
            ans=curr_sum;
            ansv=v;
        }
    }
    if(ans<=0)cout << "Empty sequence";
    else{
        for(auto i : ansv)cout << i << ' ';
        cout << '\n' << ans;
    }
}