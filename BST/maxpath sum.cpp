class Solution{
public:
    int maxpathsum(Node* root){
      int maxsum=INT_MIN;
      dfs(root, maxsum);
      return maxsum;
    }
    int dfs(Node* node, int &maxsum){
      if(!root) return 0;
      int left= max(0, dfs(root->left, maxsum));
      int right= max(0, dfs(root->right, maxsum));
      maxsum= max(maxsum, left+right+node->val);
      return max(left, right) +node->val;
      
    }
};
