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
 // Approach-1
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       ListNode* curr = head;
        int len = 0;
        while(curr!=NULL)
        {
            len+=1;
            curr=curr->next;
            
        }
        int mid = len/2;
        for(int i=0;i<mid;i++)
        {
            head=head->next;
        }
        return head;
    }
};

// Approach-2

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
    ListNode* middleNode(ListNode* head) {
       ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next and fast->next->next)
        {
            fast=fast->next->next;
            slow = slow->next;
        }
        if(fast->next)
        {
            return slow->next;
        }
        else
            return slow;
        
    }
};