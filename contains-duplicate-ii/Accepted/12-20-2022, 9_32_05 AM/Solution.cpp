// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(int i=0; i<nums.size(); i++) {
            if(mp.find(nums[i]) == mp.end()) mp[nums[i]] = i;
            else {
                int currIdx = i;
                int prevIdx = mp[nums[i]];
                if(abs(currIdx - prevIdx) <= k) return true;
                else mp[nums[i]] = currIdx;
            }
        }

        return false;
    }
};