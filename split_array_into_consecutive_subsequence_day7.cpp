class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> C;
        for(int x: nums) C[x]++;
        int a=0,b=0,c=0;
        for(int k=-1000; k<=1001; k++){
            if(C[k]<a+b) return false;
            int a_prev = a;
            a = max(0,C[k]-a-b-c);
            b = a_prev;
            c = C[k]-a-b;
        }
        return true;
    }
};