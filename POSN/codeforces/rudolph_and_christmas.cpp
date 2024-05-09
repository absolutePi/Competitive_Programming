#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        double b,h;
        cin >> n >> b >> h;
        vector<int> base_height(n);
        double total=0;
        for(int i=0;i<n;i++){
            cin >> base_height[i];
        }
        for(int i=0;i<n;i++){
            if(i==n-1 || base_height[i+1]-base_height[i]>=h){
                total += 0.5*b*h;
            }
            else{
                double newh = base_height[i+1]-base_height[i];
                double side1 = b;
                double side2 = b*(h-newh)/h;
                total+=0.5*newh*(side1+side2);
            }
        }
        cout << fixed << total << setprecision(7) << endl;
    }
}