//recursion
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
	else if (n == 1) return 1;
	else return fib(n - 1) + fib(n - 2);
    }
};

//dp bottom up approach
class Solution {
public:
    int fib(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};

//dp top down approach
class Solution {
public:
    int fib(int n) {
        // base case
        if (n <= 1)
            return n;
        vector<int> dp(n + 1, -1);

        if (dp[n] != -1)
            return dp[n];

        dp[n] = fib(n - 1) + fib(n - 2);
        return dp[n];
    }
};
