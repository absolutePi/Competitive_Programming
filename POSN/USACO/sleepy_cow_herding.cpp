#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

int main(){
    freopen("herding.in","r",stdin);
    freopen("herding.out","w",stdout);
    int n;
    cin >> n;
    vector<int> cow(n);
    for(auto &i : cow){cin >> i;}
    sort(all(cow));

    int mn_move = INT_MAX;
    if(cow[n-2]-cow[0]==n-2 && cow[n-1]-cow[n-2]>2){
        mn_move=2;
    }
    else if(cow[n-1]-cow[1]==n-2 && cow[1]-cow[0]>2){
        mn_move=2;
    }
    else{
        int farthest_cow = 0;
        for(int curr_cow=0;curr_cow<n;curr_cow++){
            while(farthest_cow+1<n && cow[farthest_cow+1]-cow[curr_cow]<n){
                farthest_cow++;
            }
            mn_move = min(mn_move,n-(farthest_cow-curr_cow+1));
        }
    }

    int gap_num=0;
    for(int i=1;i<n;i++){gap_num+=cow[i]-cow[i-1]-1;}

    int mx_move = max(gap_num-(cow[1]-cow[0]-1),gap_num-(cow[n-1]-cow[n-2]-1));

    cout << mn_move << "\n" << mx_move;
}