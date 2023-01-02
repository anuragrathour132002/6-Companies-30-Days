class Solution {
public:
    
    int maxRotateFunction(vector<int>& nums) {
    int maxval,sum=0,F0=0,cur,prev,n=nums.size();
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
        F0+=i*nums[i];
    }
    maxval=F0;
    prev=F0;
    for(int i=1;i<n;i++)
    {
        cur=prev+sum-n*nums[n-i];
        prev=cur;
        maxval=max(cur,maxval);
    }
    return maxval;
    }

};