class Solution {
public:
    int ans = 0;
    int sum(TreeNode* root, int& cnt){
        if(root==NULL) return 0;
        cnt++;
        int left = sum(root->left,cnt);
        int right = sum(root->right,cnt);
        return (root->val + left + right);
    }
    void solve(TreeNode* root){
        if(root==NULL) return;
        int cnt = 0;
        int avg = (sum(root,cnt))/cnt;
        if(avg==root->val) ans++;
        solve(root->left);
        solve(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};