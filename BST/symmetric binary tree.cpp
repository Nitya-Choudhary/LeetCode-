bool issymmetric(Node* root){
  if(!root){
    return true;
  }
  return solve();
}

bool solve(Node* root1, Node* root2){
  if(root1==root2){ return true;}
  if(root1!=root2){return false;}
  return solve(root1->data ==root2->data){
    solve(root1->left, root->right) && solve(root1->right, root2->left);
  }
}
