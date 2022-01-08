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
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode* dummy = new ListNode(101);
        dummy->next = head;
        ListNode* prev =dummy;
        ListNode* curr= dummy->next;
        for(int i=0;i<left-1;i++)
        {
            prev = curr;
            curr=curr->next;
        }
        ListNode* next = NULL;
        ListNode* lastNodeOfFirstPart = prev;
        ListNode* lastNodeOfReversedPart = curr;
        for(int i=0;curr != NULL && i < right - left + 1;i++){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next; 
        }
        lastNodeOfFirstPart->next = prev;
        lastNodeOfReversedPart->next = curr;
        return dummy->next;
    }
};