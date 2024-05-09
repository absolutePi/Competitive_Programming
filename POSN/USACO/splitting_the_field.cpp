#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll ans=0;
vector<pair<int,int>> cows;

ll solve(){
    sort(cows.begin(),cows.end());
    vector<pair<int,int>> pref(n),suf(n);
    //[0] = min, [1] = max
    pref[0] = {cows[0].second,cows[0].second};
    for(int i=1;i<n;i++){
        pref[i].first = min(pref[i-1].first,cows[i].second);
        pref[i].second = max(pref[i-1].second,cows[i].second);
    }
    suf[n-1] = {cows[n-1].second,cows[n-1].second};
    for(int i=n-2;i>=0;i--) {
		suf[i].first = min(suf[i+1].first,cows[i].second);
        suf[i].second = max(suf[i+1].second,cows[i].second);
	}

    ll area = (ll)(cows.back().first-cows.front().first)*(pref.back().second-pref.back().first);

    ll best = LLONG_MAX;
    for(int i=0;i<n-1;i++){
        if(cows[i].first!=cows[i+1].first){
            ll first_rect = (ll)(cows[i].first-cows[0].first)*(pref[i].second-pref[i].first);
            ll second_rect = (ll)(cows.back().first-cows[i+1].first)*(suf[i+1].second-suf[i+1].first);

            best = min(best,first_rect+second_rect);
        }
    }
    return area - best;
}

int main(){
    freopen("split.in","r",stdin);
    freopen("split.out","w",stdout);
    cin >> n;
    cows.resize(n);
    for(pair<int,int> &cow : cows){cin >> cow.first >> cow.second;}

    ans = max(ans,solve());

    for(pair<int,int> &cow : cows){swap(cow.first,cow.second);}

    ans = max(ans,solve());

    cout << ans << endl;
}