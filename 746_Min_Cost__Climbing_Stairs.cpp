class Solution {
public:
//RECURSION METHOD
   /* int solve(vector<int>& cost,int i){
        if(i==0){
            return cost[0];
        }
        if(i == 1){
            return cost[1];
        }
        int ans = cost[i] + min(solve(cost,i-1),solve(cost,i-2));
        return ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int i = cost.size();
        return min(solve(cost,i-1),solve(cost,i-2));

    }
};*/


//MEMORIZATION
    /*int solve(vector<int>& cost,int i,vector<int> &dp){
            if(i==0){
                return cost[0];
            }
            if(i == 1){
                return cost[1];
            }
            if(dp[i]!=-1){
                return dp[i];
            }
            dp[i]= cost[i] + min(solve(cost,i-1,dp),solve(cost,i-2,dp));
            return dp[i];
        }
        int minCostClimbingStairs(vector<int>& cost) {
            int i = cost.size();
            vector<int> dp(i+1,-1);
            return min(solve(cost,i-1,dp),solve(cost,i-2,dp));

        }
    };*/

    //TABULATION => Bottom Up Approach
    /*int solve1(vector<int>& cost,int n){
        // step 1 creation of dp array
            vector<int> dp(n+1);
            //  step 2 base case analysis
            dp[0] = cost[0];
            dp[1] = cost[1];
            //step 3
            for(int i=2;i<n;i++){
                dp[i] = cost[i]+min(dp[i-1],dp[i-2]);
            }
            return min(dp[n-1],dp[n-2]);
        }
        int minCostClimbingStairs(vector<int>& cost) {
            int n = cost.size();
            return solve1(cost,n);

        }
    };*/

    //SPACE OPTIMISATION
    int solve(vector<int>& cost,int n){
        int prev1 = cost[1];
        int prev2 = cost[0];
        for(int i=2;i<n;i++){
            int curr = cost[i]+min(prev1,prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1,prev2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
            int n = cost.size();
            return solve(cost,n);

    }
};
