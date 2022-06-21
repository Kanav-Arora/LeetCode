/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
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
        if(head==NULL)
            return NULL;
        
        
        Node* clonehead = new Node(head->val);
        Node* temp = head->next;
        Node* temp2 = clonehead;
        
        while(temp!=NULL)
        {
            Node* n = new Node(temp->val);
            temp2->next = n;
            temp2 = temp2->next;
            temp = temp->next;
        }
        
        unordered_map<Node*, Node*> mapping;
        temp = head;
        temp2 = clonehead;
        while(temp!=NULL)
        {
            mapping[temp] = temp2;
            
            temp = temp->next;
            temp2 = temp2->next;
        }
        
         temp = head;
        temp2 = clonehead;
        
        while(temp!=NULL)
        {
            temp2->random = mapping[temp->random];
            
            temp = temp->next;
            temp2 = temp2->next;
        }
        
        return clonehead;
    }
};
// @lc code=end

