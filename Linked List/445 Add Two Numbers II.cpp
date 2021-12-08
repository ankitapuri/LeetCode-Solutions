/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp = NULL;
        while(curr!=NULL)
        {
            temp=curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseList(l1); // O(n)
        l2=reverseList(l2); //o(n)
        ListNode* dummyNode;
        ListNode* head;
        dummyNode = head = new ListNode(-1);
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        int carry = 0;
        
        while(l1 || l2){
            int firstVal = l1 ? l1->val : 0;
            int secondVal = l2 ? l2->val : 0;
            
            int total = firstVal + secondVal + carry;
            carry = total / 10;
            total %= 10;
            
            ListNode* newNode = new ListNode(total);
            dummyNode->next = newNode;
            
            dummyNode = dummyNode->next;
            
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
            
        }
        
        if(carry)
            dummyNode->next = new ListNode(1);
        
        return reverseList(head->next); //o(max(m,n))
    }
};

