#include <bits/stdc++.h>

using namespace std;

long long int cnt[200001];
int main(){
    long long int x,num;
    cin >> num;
    for(int i=1;i<num;i++){
        cin >> x;
        cnt[x]++;
    }
    for(int i=1;i<=num;i++){
        if(cnt[i]==0){
            cout << i;
        }
    }
}