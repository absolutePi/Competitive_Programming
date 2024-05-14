class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int> cnt;
        int ans=0;
        for(auto c : stones){
            cnt[c]++;
        }
        for(auto c : jewels){
            ans+=cnt[c];
        }
        return ans;
    }
};