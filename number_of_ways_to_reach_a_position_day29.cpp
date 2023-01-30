int dp[1001][1001] = {}, mod = 1000000007;
class Solution {
public:
int dfs(int k, int d) {
    if (d >= k)
        return d == k;
    if (dp[k][d] == 0)
        dp[k][d] = (1 + dfs(k - 1, d + 1) + dfs(k - 1, abs(d - 1))) % mod;
    return dp[k][d] - 1;
} 
int numberOfWays(int startPos, int endPos, int k) {
    return dfs(k, abs(startPos - endPos));
   }
};