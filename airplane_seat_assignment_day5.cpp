class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n == 1) return 1;
        vector<double> dp(2, 0); dp[0] = 1.0/n;
        for(int i = 3; i <= n; ++i)
            dp[0] = dp[1] = dp[0] + dp[0]/(n-i+2);
        return 1 - dp[0];
    }
};