class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque <int> dq;
        for(int i = 0;i<k;i++){
            while(dq.size() && dq.back() < nums[i]){ // element in dq is smaller than curr
            // so we dont need it
                dq.pop_back();

            }
            dq.push_back(nums[i]);
        }
        vector <int> ans; ans.push_back(dq.front());
        for(int i = k;i<nums.size();i++){
            while(dq.size() && dq.back() < nums[i]){ // element in dq is smaller than curr
            // so we dont need it
                dq.pop_back();

            }
            dq.push_back(nums[i]);
            // delete left element
            if(dq.front() == nums[i-k]){ // if left element is in dq        
                dq.pop_front();
            }
            ans.push_back(dq.front());
        }
        return ans;
    }
};