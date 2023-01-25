class Solution 
{
public:
    bool isStrictlyPalindromic(int n) 
    {
        int temp;
        string base;
        for(int i=2; i<=n-2; i++)
        {
            temp=n;
            while(temp)
            {
                base = to_string(temp%i) + base;
                temp = temp/i;
            }
        
            int sz=base.size();
            for(int j=0; j<sz; j++)
            {
                if(base[j]!=base[sz-j-1])
                    return false;    
                
            }
            base.clear();
        }
        return true;
        
    }
};