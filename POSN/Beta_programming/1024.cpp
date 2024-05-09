#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+5;
int prf[N];

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> prf[i];
        prf[i]+=prf[i-1];
    }
    int ans=INT_MAX,pos1,pos2;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int a=prf[i-1];
            int b=prf[j-1]-prf[i-1];
            int c=prf[n]-prf[j-1];
            int mn=min({a,b,c});
            int mx=max({a,b,c});
            int dif=mx-mn;
            if(dif<ans){
                ans=dif;
                pos1=i;
                pos2=j;
            }
        }
    }
    // for(int i=1;i<=n;i++)cout << prf[i] << ' ';
    cout << pos1 << ' ' << pos2;
}   