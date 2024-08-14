class Solution {
private:
    int solve(vector<int> &nums, int start, int end)
    {
        // Handle the case when the subarray has only one element
        if (start == end) {
            return nums[start];
        }

        int prev2 = nums[start];
        int prev1 = max(nums[start], nums[start + 1]);

        for (int i = start + 2; i <= end; i++) {
            int include = prev2 + nums[i];
            int exclude = prev1;
            int ans = max(include, exclude);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        return max(solve(nums, 0, n - 2), solve(nums, 1, n - 1));
    }
};
