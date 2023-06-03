// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;

        if(arr.size() == 1) return 0;

        while(low < high) {
            int mid = low + (high-low)/2;

            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;

            else if(arr[mid] > arr[mid+1]) high = mid;
            else low = mid;
        }

        return -1;
    }
};