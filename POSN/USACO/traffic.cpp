#include <bits/stdc++.h>

using namespace std;

const int LARGE = 1e9;

int main(){
    freopen("traffic.in","r",stdin);
    freopen("traffic.out","w",stdout);
    int n;
    cin >> n;
    vector<string> tos(n);
    vector<int> l(n),r(n);
    for(int i=0;i<n;i++){
        cin >> tos[i] >> l[i] >> r[i];
    }
    //first answer
    int low = -LARGE,high = LARGE;
    for(int i=n-1;i>=0;i--){
        if(tos[i]=="none"){
            low = max(low,l[i]);
            high = min(high,r[i]);
        }
        else if(tos[i]=="on"){
            low -=r[i];
            high -=l[i];
        }
        else if(tos[i]=="off"){
            low +=l[i];
            high +=r[i];
        }
        low = max(low,0);
    }
    cout << low << " " << high;
    //second answer
    low = -LARGE,high = LARGE;
    for(int i=0;i<n;i++){
        if(tos[i]=="none"){
            low = max(low,l[i]);
            high = min(high,r[i]);
        }
        else if(tos[i]=="on"){
            low +=l[i];
            high +=r[i];
        }
        else if(tos[i]=="off"){
            low -=r[i];
            high -=l[i];
        }
        low = max(low,0);
    }
    puts("");
    cout << low << " " << high;
}