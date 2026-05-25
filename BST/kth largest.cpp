vector<int>kth_largest(Node* root, int k){
  vector<int>values;
  inorder(root,values);
  int kth_smallest=values[k-1];
  int kth_largest= values[values.size()-k];
  return {kth_smallest, kth_largest};
}

void inorder(Node* node, int values){
  inorder(node->left,values);
  values.push_back(node->data);
  inorder(node->right, values);
}
