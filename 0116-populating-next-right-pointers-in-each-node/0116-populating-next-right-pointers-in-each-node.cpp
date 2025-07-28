/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
Node* helper(Node* root){

    queue<Node*>q;
    q.push(root);
     Node* prev = NULL;
     q.push(NULL);
    while(!q.empty()){
          Node*node = q.front();
          q.pop();
          if(node == NULL){
             if(q.size() == 0){
                 break;
             }
             else{
                q.push(NULL);
             }
          }else{
               if(node->left)q.push(node->left);
          if(node->right)q.push(node->right);
          if(prev != NULL)prev->next = node;

          }
          prev = node;

        
        
         

       }
    
    return root;
}
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        return helper(root);
    }
};