int maximumGood(vector<vector<int>>& A) {
    int n = A.size(), ans = 0;
    for (int num = 1 << n; num < 1 << (n + 1); num++) {
        string permutation = bitset<15>(num).to_string().substr(15 - n);
        if (check(permutation, A, n)) {
            int c = count(begin(permutation), end(permutation), '1');
            ans = max(ans, c);
        }
    }
    return ans;
}
bool check(string& perm, vector<vector<int>>& A, int n) {
    for (int i = 0; i < n; i++) {
        if (perm[i] == '0') continue;
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 2) continue;
            if ((A[i][j] == 1 && perm[j] == '0') || 
                (A[i][j] == 0 && perm[j] == '1')) 
                return false;
        }
    }
    return true;
}