// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        int n = strs.size();
        for(int i=0; i<n; i++) {
            bool flag = true;
            int j;
            for(j=0; j<n-1; j++) {
                if(strs[j][i] != strs[j+1][i]) {
                    flag = false;
                    break;
                }
            }

            if(flag && j>0) ans += strs[i][i];
        }
        return ans;
    }
};