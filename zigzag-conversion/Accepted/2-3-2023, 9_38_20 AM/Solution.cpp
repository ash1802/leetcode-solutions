// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int n) {
        if(n == 1) return s;

        int len = s.size();
        if(len == 1) return s;

        int col = len/2 + 1;
        char zigzag[n][col];
        for(int i=0; i<n; i++) {
            for(int j=0; j<col; j++) {
                zigzag[i][j] = '$';
            }
        }

        int i=0, j=0;
        bool isDown = true;
        for(int k=0; k<s.size(); k++) {
            zigzag[i][j] = s[k];
            
            if(i == n-1) {
                isDown = false;
                i--;
                j++;
                continue;
            }

            if(i == 0 && j > 0) {
                isDown = true;
                i++;
                continue;
            }

            if(isDown) i++;
            else {
                i--;
                j++;
            }
        }

        string ans = "";

        for(int i=0; i<n; i++) {
            for(int j=0; j<col; j++) {
                if(zigzag[i][j] != '$') ans.push_back(zigzag[i][j]);
            }
        }

        return ans;
    }
};