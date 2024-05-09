#include <bits/stdc++.h>

using namespace std;

int total_cows;

int main(){
    freopen("cbarn.in","r",stdin);
    freopen("cbarn.out","w",stdout);
    int n;
    cin >> n;
    vector<int> rooms(n);
    for(int i=0;i<n;i++){
        cin >> rooms[i];
        total_cows+=rooms[i];
    }
    int mn = INT_MAX;
    for(int i=0;i<n;i++){
        int dist =0;
        int cow_left =total_cows;
        for(int j=0;j<n;j++){
            cow_left -=rooms[(i+j)%n];
            dist +=cow_left;
        }
        mn = min(mn,dist);
    }
    cout << mn;
}