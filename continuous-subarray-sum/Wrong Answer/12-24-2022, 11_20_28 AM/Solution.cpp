// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mp;
        int sum = 0;
        mp[sum] = -1;

        for(int i=0; i<n; i++) {
            sum += arr[i];

            if(mp.find((sum-k) % k) != mp.end()) {
                int len = i - mp[(sum-k)%k] + 1;
                if(len >= 2) return true;
            }

            mp[sum % k] = i;
        }

        return false;
    }
};