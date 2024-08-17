class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int n = days.size();
        vector<int> dp(n+1, INT_MAX);
        dp[n] = 0;
        for(int k=n-1; k>=0; k--){
            //1 day pass
            int opt1 = cost[0] + dp[k+1];

            int i;

            //7 days pass
            for(i =k; i<n && days[i] < days[k]+7; i++);
            int opt2 = cost[1] + dp[i];

            //30 days pass
            for(i =k; i<n && days[i] < days[k]+30; i++);
            int opt3 = cost[2] + dp[i];

            dp[k] = min(opt1, min(opt2, opt3));
        }
        return dp[0];
    }
};
