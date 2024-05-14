class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
            int n=heights.size(),ans=0,ind;
            bool check=false;
            stack<pair<int,int>> s;
            s.push({0,-1});
            for(int i=0;i<n;i++){
                int start=i;
                while(!s.empty()&&s.top().first>heights[i]){
                    int h=s.top().first;start=s.top().second;s.pop();
                    ans=max(ans,h*(i-start));
                }
                s.push({heights[i],start});
            }
            while(!s.empty()){
                int h=s.top().first;ind=s.top().second;s.pop();
                ans=max(ans,h*(n-ind));
            }
            return ans;
        }
};