Node* Search(Node* root, int val){
  if(root==nullptr) return nullptr;
  if(val==root->val) return root;
  if(val>root->val) return Search( root->right, val);
  if(val<root>val) return Search(root->left,val);
}
