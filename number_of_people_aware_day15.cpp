static int MOD=1e9+7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long> memo(n+1,1);    
        memo[0]=0;  
        for(int i=1;i<=n;i++)
            for(int j=delay;j<forget;j++) 
                if(i-j>=0)
                    memo[i]=(memo[i]+memo[i-j])%MOD;    
        return (memo[n]-memo[n-forget]+MOD)%MOD; 
    }
};