class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MIN, INT_MAX);
    }
    
private:
    TreeNode* build(const vector<int>& A, int& i, int lower, int upper) {
        // if all elements used or current value out of allowed bounds
        if (i >= (int)A.size() || A[i] <= lower || A[i] >= upper) {
            return nullptr;
        }
        int val = A[i++];
        TreeNode* root = new TreeNode(val);
        // left subtree: valid values < val
        root->left = build(A, i, lower, val);
        // right subtree: valid values > val
        root->right = build(A, i, val, upper);
        return root;
    }
};
