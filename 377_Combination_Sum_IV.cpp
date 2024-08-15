class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i - nums[j] >= 0) {
                    dp[i] += dp[i - nums[j]];
                    // Check for overflow and handle it if necessary
                    if (dp[i] > INT_MAX) {
                        dp[i] = INT_MAX;
                    }
                }
            }
        }
        return dp[target];
    }
};
