/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        Node* newhead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newhead;
        unordered_map<Node*,Node*>mp;
        mp[head] = newhead;

        while(oldTemp != NULL){
          Node* copyNode = new Node(oldTemp->val);
          mp[oldTemp] = copyNode;
          newTemp->next = copyNode;
          newTemp = newTemp->next;
          oldTemp = oldTemp->next;
        }

        oldTemp = head;
        newTemp = newhead;
        Node* randomNode = oldTemp->random;
        while(oldTemp!=NULL){ 
        //    
         //else{
           randomNode = oldTemp->random;
           newTemp->random = mp[randomNode];
           // }

           oldTemp = oldTemp->next;
           newTemp = newTemp->next;
        }

        return newhead;


    }
};