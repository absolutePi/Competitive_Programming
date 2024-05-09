#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int price[N][N],up[N][N];
int price_ver[N],price_hor[N];
int up_ver[N],up_hor[N];

int main(){
    int n,m;
    cin >> n >> m;
    int sum=0;
    //input
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> price[i][j];
            sum+=price[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> up[i][j];
        }
    }
    //run prefix verically
    for(int j=1;j<=m;j++){
        int curr1=0,curr2=0;
        for(int i=1;i<=n;i++){
            curr1+=price[i][j];
            curr2+=up[i][j];
        }
        price_ver[j]=curr1;
        up_ver[j]=curr2;
    }
    //run prefix horizontally
    for(int i=1;i<=n;i++){
        int curr1=0,curr2=0;
        for(int j=1;j<=m;j++){
            curr1+=price[i][j];
            curr2+=up[i][j];
        }
        price_hor[i]=curr1;
        up_hor[i]=curr2;
    }
    int ans=INT_MIN;
    //cutting
        //cut horizontally
        for(int i=1;i<=n;i++){
            int curr=sum;
            curr-=price_hor[i];
            if(i-1>=1)curr+=up_hor[i-1];
            if(i+1<=n)curr+=up_hor[i+1];
            ans=max(ans,curr);
        }
        //cut vertically
        for(int j=1;j<=m;j++){
            int curr=sum;
            curr-=price_ver[j];
            if(j-1>=1)curr+=up_ver[j-1];
            if(j+1<=m)curr+=up_ver[j+1];
            ans=max(ans,curr);
        }
    cout << ans << '\n';
}
/*
3 3
2 4 5
1 3 2
4 3 7
1 4 6
3 5 3
4 2 1
*/