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
    ListNode* reverseLL(ListNode* head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr!=NULL)
        {
            ListNode * temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* reverseLLinKGroup(ListNode* head, int k)
    {
        ListNode* current = head;
        int currlen = 1;
        if(head == NULL) return head;
      while(current->next!=NULL and currlen<k)
      {
          current=current->next;
          currlen+=1;
      }
      if(currlen<k)
         return head;
      ListNode *tempnode = current->next;
      current->next = NULL;
       /*reverse LL */
        
       ListNode * templist = reverseLLinKGroup(tempnode,k);
       ListNode * previous = reverseLL(head);
      head->next = templist;
       return previous;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseLLinKGroup(head,k);
    }
};