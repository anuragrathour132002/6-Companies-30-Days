class Solution {
   public:
   int minimumCardPickup(vector<int>& cards) {
    unordered_map<int,int> res;
    int ans=INT_MAX;
    for(int i=0;i<cards.size();i++)
    {
        if(res.find(cards[i])!=res.end())
        {
            res[cards[i]]=i-res[cards[i]];
            ans=min(ans,res[cards[i]]);
        }
        
        res[cards[i]]=i;
    }
    if (ans==INT_MAX) return -1;
    
    return ans+1;
    
}
};