#include <bits/stdc++.h>

using namespace std;

const int N =1e5+1;
int petals[N],ans;

int main(){
    float n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> petals[i];
    }
    for(int i=0;i<n;i++){
        float flower_cnt=1;
        float petal_cnt=petals[i];
        for(int j=i+1;j<n;j++){
            flower_cnt++;
            petal_cnt+=petals[j];
            float avg_petals = petal_cnt/flower_cnt;
            // cout << flower_cnt << " " << petal_cnt << "\n";
            for(int k=i;k<=j;k++){
                if(petals[k]==avg_petals){
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans+n;
}