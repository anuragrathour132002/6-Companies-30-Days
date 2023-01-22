class Solution {
public:
    void merge(vector<int> &a , int l , int mid , int h)     {
        vector<int> x(a.begin()+l, a.begin()+mid+1);         
        vector<int> y(a.begin()+mid+1, a.begin()+h+1); 
        int n = x.size();
        int m = y.size();
        int i,j,k;  i=j=0;  k=l;
        while(i<n and j<m)                                  
            a[k++] = (x[i]<y[j]) ? x[i++] : y[j++];
        while(i<n)
            a[k++] = x[i++];
        while(j<m)
            a[k++] = y[j++];         
	}        
    void mergeSort(vector<int> &a , int l , int h)    
    {
        if(l<h)
        {
            int mid = l+(h-l)/2;
            mergeSort(a,l,mid);
            mergeSort(a,mid+1,h);
            merge(a,l,mid,h);
        }
    }    
    vector<int> sortArray(vector<int>& nums) {        
        int n = nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};