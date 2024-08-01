class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Check if mid is a peak element
            bool leftOK = (mid == 0 || nums[mid] > nums[mid - 1]);
            bool rightOK = (mid == n - 1 || nums[mid] > nums[mid + 1]);

            if (leftOK && rightOK) {
                return mid;
            }

            // Move to the side that has a higher element
            if (mid > 0 && nums[mid - 1] > nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // Should never reach here as there is always a peak element
        return -1;
    }
};
