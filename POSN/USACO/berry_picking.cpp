#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

int main(){
    freopen("berries.in","r",stdin);
    freopen("berries.out","w",stdout);
    //ios::sync_with_stdio(false);
    //in.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<int> trees(n);
    int maxb=0;
    for(auto &i : trees){
        cin >> i;
        maxb=max(maxb,i);//finding the max amount of berries
    }
    int ans=0;
    for(int q=1;q<=maxb;q++){
        //finding every possibility
        vector<int> chunks(q+1,0);//amount of chunk i size
        for(int i=0;i<n;i++){
            //getting chunks
            chunks[q]+=trees[i]/q;
            chunks[trees[i]%q]++;
        }
        if(k/2>chunks[q]){continue;}//if q size chunks is less than Elsie's basket amount->change q
        chunks[q]-=k/2;//gave Elsie
        //giving berries to bessie
        int curr=q;//giving the most possible amount
        int given=0;//keep track of how many we have given her,if all of her baskets are full then stop giving her
        int total=0;//total of berries Bessie has gotten so far
        while(given<k/2&&curr>0){
            //if theres still a chunk this size left
            if(chunks[curr]>0){
                given++;
                total+=curr;
                chunks[curr]--;
            }
            //if the amount of current chunk size run out
            else{
                curr--;
            }
        }
        ans = max(ans,total);
    }
    cout << ans;
}