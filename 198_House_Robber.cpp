class Solution {
public:
    int solve(vector<int>& nums,int n){
        vector<int>dp(n+1,0);
        dp[0]=nums[0];
        if(n>1)
            dp[1]=max(nums[0],nums[1]);

        for(int i=2;i<n;i++){
            int temp1=dp[i-2]+nums[i];
            int temp2=dp[i-1];

            dp[i]=max(temp1,temp2);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        return solve(nums, nums.size());
    }
};
