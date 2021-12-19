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
        unordered_map<Node*,Node*>mp;
        Node* dummy = new Node(100001);
        Node* runner = dummy;
        Node* curr = head;
        while(curr!=NULL)
        {
            Node* newnode = new Node(curr->val);
            runner->next = newnode;
            mp[curr] = newnode;
            curr=curr->next;
            runner=runner->next;
        }
        curr = head;
        runner = dummy->next;
        while(curr!=NULL)
        {
            if(curr->random!=NULL)
                runner->random = mp[curr->random];
            runner = runner->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};