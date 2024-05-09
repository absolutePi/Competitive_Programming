#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    int t;
    cin >> t;
    while(t--){
        int ans = INT_MIN;
        int mx_dif;
        char c;
        cin >> mx_dif >> c;
        int l=0,r=0;
        while(l<n && r<n){
            while(r<n){
                if(str[r]!=c){
                    if(mx_dif==0){break;}
                    mx_dif--;
                }
                r++;
            }
            ans = max(ans,r-l);
            mx_dif += str[l++]!=c;
        }
        cout << ans << endl;
    }
}