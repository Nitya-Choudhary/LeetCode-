class Solution{
public:
      int maxdepth(Node* root){
        if(root==nullptr) return 0;
        int lh= maxdepth(root->left);
        int rh= maxdepth(root->right);
        return 1+max(lh,rh);
      }
}
