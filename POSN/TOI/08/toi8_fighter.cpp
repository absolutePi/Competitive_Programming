#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int p;
    cin >> p;
    int even_damaged=0,odd_damaged=0,cnt_even=0,cnt_odd=0;
    for(int i=0;i<p*2;i++){
        int x;
        cin >> x;
        if(x%2==0){//even
            cnt_odd=0;
            cnt_even++;
            odd_damaged+=(cnt_even>=3 ? 3 : 1);
        }
        else if(x%2==1){
            cnt_even=0;
            cnt_odd++;
            even_damaged+=(cnt_odd>=3 ? 3 : 1);
        }
        if(even_damaged>=p){
            cout << 1 << '\n' << x;
            return 0;
        }
        if(odd_damaged>=p){
            cout << 0 << '\n' << x;
            return 0;
        }
    }
}