// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int k, vector<int>& arr) {
        unordered_map<int,int> mp;
        int sum = 0;
        int n = arr.size();
        int minLen = n+1;

        for(int i=0; i<n; i++) {
            sum += arr[i];

            if(sum >= k) {
                int len = i+1;
                minLen = min(minLen, len);
            }

            if(arr[i] == k) minLen = min(minLen, 1);

            if(mp.find(sum - k) != mp.end()) {
                int len = i - mp[sum-k];
                minLen = min(minLen,len);
            }
            
            mp[sum] = i;
        }

        if(minLen == n+1) return 0;
        return minLen;
    }
};