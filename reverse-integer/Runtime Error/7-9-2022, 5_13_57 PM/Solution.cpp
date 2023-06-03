// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        
        int dig = 0;
        int x1 = 0;
        bool sign = false;
        
        if(x < 0) {
            sign=true;
            x = abs(x);
        }
        
        while (x > 0) {
            dig = x%10;
            if(x1 >= INT_MAX) return 0;
            x1 = x1*10 + dig;
            x/=10;
        }
        
        return (sign) ? -x1 : x1;
    }
};