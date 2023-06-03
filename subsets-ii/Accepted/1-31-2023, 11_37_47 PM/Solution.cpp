// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int index, vector<int> ds) {
        ans.push_back(ds);
        for(int j=index; j<nums.size(); j++) {
            if(j != index && nums[j] == nums[j-1]) continue;
            ds.push_back(nums[j]);
            solve(nums,ans,j+1,ds);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        solve(nums,ans,0,ds);
        return ans;
    }
};