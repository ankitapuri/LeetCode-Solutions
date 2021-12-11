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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next =reverseList(head);
        head = dummy;
        ListNode *curr=head;
        ListNode *prev = NULL;
        for(int i=0;i<n;i++)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        return reverseList(head->next);
    }
};