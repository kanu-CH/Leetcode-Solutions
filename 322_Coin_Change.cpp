class Solution {
public:
    // int solve(vector<int> &nums, int x, vector<int> &dp){
    //     //base case
    //     if(x == 0) return 0;
    //     if(x < 0) return INT_MAX;

    //     if(dp[x] != -1) return dp[x];

    //     int mini = INT_MAX;
    //     for(int i = 0; i<nums.size(); i++){
    //         int ans = solve(nums, x-nums[i], dp);

    //         if(ans != INT_MAX) mini = min(mini, 1+ans);
    //     }
    //     return dp[x] = mini;
    // }
    int solve2(vector<int> &coins, int x){
        vector<int> dp(x+1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i<=x; i++){
            for(int j = 0; j<coins.size(); j++){
                if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX){
                    dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
                }
            }
        }
        if(dp[x] == INT_MAX) return -1;
        else return dp[x];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        // vector<int> dp(amount+1,-1);
        // int ans = solve(coins, amount, dp);
        // if(ans == INT_MAX) return -1;
        // else return ans;

        return solve2(coins, amount);
    }
};
