class Solution {
public:
       int maxConsecutive(int bottom, int top, vector<int>& A) {
        sort(begin(A), end(A));
        int n = A.size(), res = max(A[0] - bottom, top - A[n - 1]);
        for (int i = 1; i < n; ++i)
            res = max(res, A[i] - A[i - 1] - 1);
        return res;
    }
};