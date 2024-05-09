#include <bits/stdc++.h>

using namespace std;

int grid[2001][2001],i=1000,j=1000;

int main(){
    freopen("mowing.in","r",stdin);
    freopen("mowing.out","w",stdout);
    bool check = false;
    vector<int> ans;
    int n,cnt=1;
    cin >> n;
    for(int p=0;p<n;p++){
        char d;
        int s;
        cin >> d >> s;
        if(d=='N'){
            while(s--){
                i--;
                if(grid[i][j]){
                    ans.push_back(cnt-grid[i][j]);
                    check = true;
                }
                grid[i][j]=cnt;
                cnt++;
            }
        }
        else if(d=='S'){
            while(s--){
                i++;
                if(grid[i][j]){
                    ans.push_back(cnt-grid[i][j]);
                    check = true;
                }
                grid[i][j]=cnt;
                cnt++;
            }
        }
        else if(d=='W'){
            while(s--){
                j--;
                if(grid[i][j]){
                    ans.push_back(cnt-grid[i][j]);
                    check = true;
                }
                grid[i][j]=cnt;
                cnt++;
            }
        }
        else if(d=='E'){
            while(s--){
                j++;
                if(grid[i][j]){
                    ans.push_back(cnt-grid[i][j]);
                    check = true;
                }
                grid[i][j]=cnt;
                cnt++;
            }
        }
    }
    sort(ans.begin(),ans.end());
    if(!check){
        cout << "-1";
        return 0;
    }
    cout << ans[0];
}