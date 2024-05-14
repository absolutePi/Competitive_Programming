class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),ans=0,ground=0;
        stack<pair<int,int>> s;
        for(int i=0;i<n;i++){
            while(!s.empty()&&s.top().first<=height[i]){
                ans+=(min(height[i],s.top().first)-ground)*(max(0,i-s.top().second-1));
                ground=s.top().first;
                s.pop();
            }
            if(!s.empty()){
                ans+=(min(height[i],s.top().first)-ground)*(max(0,i-s.top().second-1));
            }
            s.push({height[i],i});
        }
        return ans;
    }
};