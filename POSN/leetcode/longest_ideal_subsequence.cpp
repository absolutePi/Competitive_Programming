class Solution {
public:
    int longestIdealString(string str, int k) {
        int n=str.length();
        int ans=0;
        vector<int> dp(26,0);
        for(int i=0;i<n;i++){
            int curr=str[i]-'a';
            int best=0;
            for(int j=0;j<26;j++){
                if(abs(curr-j)<=k){
                    best=max(best,dp[j]);
                }
            }
            dp[curr]=max(dp[curr],best+1);
            ans=max(ans,dp[curr]);
        }
        return ans;
    }
};