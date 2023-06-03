// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxCurr = 0;
        int overallMax = INT_MIN;
    
        if(nums.size() == 1) {
            return nums[0];
        }
        
        
        for(int i=0; i<nums.size(); i++) {
            maxCurr += nums[i];
            if(maxCurr < 0) {
                maxCurr = 0;
            }

            overallMax = max(overallMax,maxCurr);
        }
        
        return overallMax;
    }
};