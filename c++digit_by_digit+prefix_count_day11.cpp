class Solution {
public:
    
    // count the numbers which are in range 1 to N with prefix 
    int countPrefix(int n, long long prefix)
    {
        long long offset = 10;
        long long target = n;
        int total = 0;
        for(int i=1;i<=9;i++)
        {
            long long minv = prefix * offset;
            long long maxv = minv + offset-1;
            
            
            if(target < minv)break;
            
            total+= min(target,maxv) - minv + 1;
            
            offset = offset * 10;
        }
        
        return total+1;
    }
    
    int findKthNumber(int n, int k, int prefix =0) {

        // if K > 0 we have to find the result otherwise current prefix is the solution
        if(k>0)
        {
            // go through next prefix from current prefix and check count of numbers with ith prefix
            // if K <= prefix_count then K lies in the current prefix range and so we ignore current prefix
            // and go to next digit prefix from current prefix and decrease K by 1 
            // otherwise we check prefix count for same digit next prefix number and ignore the previous
            // prefix count from K as K is out of the range of previous prefix number
            for(int i= (prefix==0)?1:0;i<=9;i++)
            {
                int prefixCount = countPrefix(n,10*prefix+i);
                if(k<=prefixCount) return findKthNumber(n,k-1,10*prefix+i);
                k-=prefixCount;
            }            
        }
        
        return prefix;
    }
};