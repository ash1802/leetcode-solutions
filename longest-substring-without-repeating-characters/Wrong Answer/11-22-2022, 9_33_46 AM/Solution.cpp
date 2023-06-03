// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0;
        int count = 0;
        int maxCount = INT_MIN;

        if(s.length() == 0) return 0;
        
        if(s.length() == 1) return 1;

        unordered_map<char,bool> mp;
        
        for(int i=0; i<s.length(); ) {
            if(mp.find(s[i]) == mp.end()) {
                mp[s[i]] = true;
                count++;
                i++;
            }
            else {
                maxCount = max(maxCount, count);
                count = 0;
                mp.clear();
            }
        }

        return maxCount;
    }
};