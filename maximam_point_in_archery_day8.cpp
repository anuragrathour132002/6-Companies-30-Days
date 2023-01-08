class Solution {
public:
    int memo[12][100001];
    int dp(int k, int numArrows, vector<int>& aliceArrows) {
        if (k == 12 || numArrows <= 0)
            return 0;
        
        if (memo[k][numArrows] != -1) return memo[k][numArrows];
        int maxScore = dp(k+1, numArrows, aliceArrows); // Bob loses
        if (numArrows > aliceArrows[k])
            maxScore = max(maxScore, dp(k+1, numArrows-aliceArrows[k]-1, aliceArrows) + k);
        return memo[k][numArrows] = maxScore;
    }
    
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        memset(memo, -1, sizeof(memo));
        vector<int> ans(12, 0);
        int remainBobArrows = numArrows;
        for (int k = 0; k < 12; ++k) {
            if (dp(k, numArrows, aliceArrows) != dp(k+1, numArrows, aliceArrows)) { 
                ans[k] = aliceArrows[k] + 1;
                numArrows -= ans[k];
                remainBobArrows -= ans[k];
            }
        }
        
        ans[0] += remainBobArrows;
        return ans;
    }
};