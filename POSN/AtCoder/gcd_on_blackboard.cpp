#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
int arr[N],prefix[N],suffix[N];

int main(){
    int n;
    cin >> n;
    //containing the values in array
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    //pushing prefix
    for(int i=1;i<=n;i++){
        prefix[i] = __gcd(prefix[i-1],arr[i]);
    }
    //pushing suffix
    for(int i=n;i>=1;i--){
        suffix[i] = __gcd(suffix[i+1],arr[i]);
    }
    int ans = INT_MIN;
    for(int i=1;i<=n;i++){
        ans = max(ans,__gcd(prefix[i-1],suffix[i+1]));
    }
    cout << ans;
}