class Solution {
public:
    int findIntegers(int n) {
        vector<int> dpZero(32), dpOne(32), dp(32);
        dpZero[0] = dp[0] = 1;
        for (int i = 1; i < 32; ++i) {
            dpOne[i] = dpZero[i-1];
            dpZero[i] = dpZero[i-1] + dpOne[i-1];
            dp[i] = dpZero[i] + dpOne[i];
        }
        int ans = 0, lastBit = -1;
        for (int k = 30; k >= 0; --k) {
            int bit = (n >> k) & 1;
            if (bit == 1) {
                ans += dp[k];
                if (lastBit == 1) return ans; 
            }
            lastBit = bit;
        }
        return ans + 1; 
    }
};