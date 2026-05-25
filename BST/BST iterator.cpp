void traverse(Node* root, vector<int>& elements){
  if(root==NULL) return nullptr;
  traverse(root->left,elements);
  elements.push_back(root->data);
  traverse(root->right, elements);
  
}

vector<int>merge(Node* root1, Node* root2){
  vector<int>elements;
  traverse(root1, elements);
  traverse(root2,elements);
  sort(elements.begin(), elements.end());
  return elements;
}
