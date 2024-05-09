#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int num;
    cin >> num;
    for(int i=1;i<=num;i++){
        long long int a1=i*i;
        long long int a2=a1*(a1-1)/2;
        if(i>2){
            a2-=4*(i-1)*(i-2);
        }
        cout << a2 << "\n";
    }
}