#include <bits/stdc++.h>

using namespace std;

vector<int> x;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        int l=0,r=x.size();
        while(l<r){
            int mid=l+(r-l)/2;
            if(x[mid]>z){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        if(l==x.size()){
            x.push_back(z);
        }
        else{
            x[l]=z;
        }
    }
    cout << x.size();
}