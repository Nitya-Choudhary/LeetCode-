class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1; // if -1, tree is unbalanced
    }

private:
    int checkHeight(TreeNode* root) {
        if (!root) return 0;

        int lh = checkHeight(root->left);
        if (lh == -1) return -1; // left subtree unbalanced

        int rh = checkHeight(root->right);
        if (rh == -1) return -1; // right subtree unbalanced

        if (abs(lh - rh) > 1) return -1; // current node unbalanced

        return 1 + max(lh, rh); // return height
    }
};
