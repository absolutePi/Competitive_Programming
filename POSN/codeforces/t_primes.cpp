#include <bits/stdc++.h>

using namespace std;

#define ll long long
int main(){
    int n;
    cin >> n;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    vector<bool> is_prime(1e6+1,true),is_tprime(n+1,false);
    is_prime[0] = is_prime[1] = false;
    for(int i=2;i*i<=1e6;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=1e6;j+=i){
                is_prime[j] = false;
            }
        }
    }
    // cout << "a";
    set<long long>S;
    for(int i=1;i<=1e6;i++){
        if(is_prime[i]){
            S.insert((ll)i*(ll)i);
        }
    }
    // cout << "b";
    for(int i=0;i<n;i++){
        if(S.count(arr[i])){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << "\n";
    }
    // cout << "c";
}