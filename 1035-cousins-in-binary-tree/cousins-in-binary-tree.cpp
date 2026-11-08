class Solution {
public:
    int xd = -1, yd = -1;
    TreeNode* xp = NULL;
    TreeNode* yp = NULL;

    void dfs(TreeNode* root, TreeNode* parent, int depth, int x, int y) {
        if(root == NULL) return;

        if(root->val == x) {
            xd = depth;
            xp = parent;
        }

        if(root->val == y) {
            yd = depth;
            yp = parent;
        }

        dfs(root->left, root, depth+1, x, y);
        dfs(root->right, root, depth+1, x, y);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, NULL, 0, x, y);

        return xd == yd && xp != yp;
    }
};