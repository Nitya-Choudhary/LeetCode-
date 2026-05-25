class Solution{
public:
      unordered_set<int>s;
      bool targettwosum(Node* root, int k){
        if(root==NULL) return false;
        if(s.find(k-root->val!=s.end()) return true;
        s.insert(root->val);
        return targettwosum(root->left,k) || targettwosum(root->right,k); 
      }
}
