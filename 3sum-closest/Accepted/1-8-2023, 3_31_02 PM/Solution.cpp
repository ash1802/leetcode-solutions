// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int absDiff = INT_MAX;
        int ans = 0;

        for(int i=0; i<nums.size()-1; i++) {
            int start = i+1;
            int end = nums.size()-1;

            while(start < end) {
                // solving just like regular three sum
                int sum = nums[start] + nums[end] + nums[i];
                if(sum == target) return sum;
                if(sum < target) start++;
                else end--;

                // additionally we find the minimum absolute difference and store the 
                // answer sum that leads to it
                int diff = abs(sum - target);
                if(diff < absDiff) {
                    absDiff = diff;
                    ans = sum;
                }
            }
        }

        return ans;
    }
};