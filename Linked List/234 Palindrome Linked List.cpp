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
    ListNode* findmid(ListNode*head)
    {
        ListNode*fast =head;
        ListNode*slow = head;
        while(fast->next!=NULL and fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow = slow->next;
        }
        return slow;
          
    }
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
    bool compare(ListNode*l1,ListNode* l2)
    {
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val!=l2->val)
            {return false;}
            l1=l1->next;
            l2=l2->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return false;
        if(head->next == NULL) return true;
        ListNode *mid = findmid(head);
        ListNode *templist = mid->next;
        mid->next = NULL;
         ListNode * l2 = reverseList(templist);
         return compare(head,l2);
    }
};