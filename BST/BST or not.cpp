class Solution{
public:
     Node* valid( Node* root){
       return helper(root,LONG_MIN, LONG_MAX);
     }
     Node* helper(Node* node, long minval, long maxval){
       if(!node) return true;
       if(node->val<=minval || node->val>=maxval){
         return false;
         
       }
       return helper(node->left, minval, maxval) && helper(node->right,minval,maxval);
     }
};
