#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

struct Log{
    int day,cow,change;
};

bool cmp(const Log &a, const Log &b){
    return a.day<b.day;
}

int main(){
    freopen("measurement.in","r",stdin);
    freopen("measurement.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,g;
    cin >> n >> g;
    vector<Log> log(n);
    map<int,int> cows;
    for(Log &l : log){
        cin >> l.day >> l.cow >> l.change;
        cows[l.cow]=g;
    }
    sort(all(log),cmp);

    map<int,int> milk_prod{{g,n}};

    int ans=0;
    for(Log l : log){
        int milk_amt = cows[l.cow];
        bool was_top = milk_amt==milk_prod.rbegin()->first;
        int prev_count = milk_prod[milk_amt];

        milk_prod[milk_amt]--;
        if(milk_prod[milk_amt]==0)milk_prod.erase(milk_amt);

        milk_amt+=l.change;
        cows[l.cow]=milk_amt;
        milk_prod[milk_amt]++;

        bool is_top = milk_amt==milk_prod.rbegin()->first;
        int curr_count = milk_prod[milk_amt];
        if(was_top){
            if(is_top && prev_count==curr_count){continue;}
            ans++;
        }
        else if(is_top){
            ans++;
        }
    }
    cout << ans;
}