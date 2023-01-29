class Solution
{
    public:
    bool asteroidsDestroyed(int mass, vector<int>& arr)
    {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        long long m=mass;
        for (int i=0;i<n;i++)
        {
            if (arr[i]<=m)
                m+=arr[i];
            else
                return false;
        }
        return true;
    }
};