class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(105,0);
        for(int i=0;i<n;i++){
            v[nums[i]]++;
        }
        int ans=0;
        for(int i=1;i<=100;i++){
            int curr=v[i];
            ans+=(curr*(curr-1))/2;
        }
        return ans;
    }
};