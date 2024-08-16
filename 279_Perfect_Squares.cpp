class Solution {
public:
    int numSquares(int num) {
       vector<int> dp(num + 1, INT_MAX);
        dp[0] = 0;

        vector<int> squares;
        for (int i = 1; i * i <= num; ++i) {
            squares.push_back(i * i);
        }

        for (int i = 1; i <= num; ++i) {
            for (int square : squares) {
                if (i - square >= 0) {
                    dp[i] = min(dp[i], dp[i - square] + 1);
                }
            }
        }

        return dp[num]; 
    }
};
