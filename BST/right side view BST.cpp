class Solution{
public:
      vector<int> rightsideview(Node* root){
        vector<int>ans;
        solve(root,ans,0);
        return ans;
      }
      void solve(Node* root, vector<int>ans, int level){
        if(root==nullptr) return ;
        if(level== ans.size()) ans.push_back(root->val);
        solve(root->right,ans,level+1);
        solve(root->right,ans,level+1);
      }
}
