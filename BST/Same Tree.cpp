class Solution{
public:
      bool issame(Node* p, Node* q){
        if(p==NULL || q== NULL){
          return false;
        }
        if(p==NULL && q==NULL){
          return true;
        }

        return (p->val == q->val) && issame(p->left, q->left) && issame(p->right,q->right);
        
      }
}
