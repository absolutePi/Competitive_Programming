#include <bits/stdc++.h>

using namespace std;

double h,c,d;

bool works(int pouring){
    double total_temp = (pouring+1)*h+pouring*c;
    double total_cups = (double)(2*pouring+1.0);
    double avg = total_temp/total_cups;
    return avg>=d;
}

void solve(){
    cin >> h >> c >> d;
    int l=0,r=1e6+1,cups_poured=0;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(works(mid)){//works we pour more
            cups_poured=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    if(cups_poured==1e6+1){
        cout << 2 << endl;
    }
    else{//compare the slightly less and slightly more case
        double total1 = (cups_poured+1)*h+cups_poured*c;
        double total2 = (cups_poured+2)*h+(cups_poured+1)*c;
        double cup1 = (double)(2*cups_poured+1.0);
        double cup2 = (double)(2*cups_poured+3.0);
        double first_avg = total1/cup1;
        double second_avg = total2/cup2;
        double hot_and_cold = (h+c)/2.0;
        double min_dif = min({abs(first_avg-d),abs(second_avg-d),abs(hot_and_cold-d)});
        if(min_dif==abs(d-hot_and_cold)){
            cout << 2 << endl;
        }
        else if(min_dif==abs(first_avg-d)){
            cout << 2*cups_poured+1 << endl;
        }
        else{
            cout << 2*cups_poured+3 << endl;
        }
        return;
    }
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
}