// https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long quotient = 0;
  
        long long x = abs(dividend);
        long long y = abs(divisor);

        if(divisor == 1) return dividend;
        if(divisor == -1) {
            if(dividend == INT_MIN) return INT_MAX;
            return -dividend;
        }

        while(x-y >= 0) {
            x = x - y;
            quotient++;
        }

        if(quotient > INT_MAX) return INT_MAX;
        if(quotient < INT_MIN) return INT_MIN;

        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) return -quotient;

        return quotient;
    }
};