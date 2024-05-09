#include <bits/stdc++.h>

using namespace std;

const int N = 2e6+5;
int n,a[N];
bool on_stack[N];

bool works(int curr_size){
    stack<int> s;
    for(int i=0;i<n;i++){
        if(a[i]<=curr_size){continue;}
        if(s.empty()){
            s.push(a[i]);
        }
        else if(a[i]!=s.top()){
            return false;
        }
        else if(a[i]==s.top()){
            s.pop();
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int l=0,r=INT_MAX,mid,ans=-1;
    while(l<=r){
        mid=l+(r-l)/2;
        if(works(mid)){
            r=mid-1;
            ans=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout << ans << '\n';
}   