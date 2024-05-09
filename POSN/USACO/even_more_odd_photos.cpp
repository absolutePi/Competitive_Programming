#include <bits/stdc++.h>

using namespace std;

int n,odd,even;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x%2)odd++;
        else even++;
    }
    while(odd>even){
        odd-=2;
        even++;
    }
    if(even>odd+1)even = odd+1;
    cout << odd + even;
}