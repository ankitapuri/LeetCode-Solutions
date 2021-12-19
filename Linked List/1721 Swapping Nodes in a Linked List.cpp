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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* runner = head;
         ListNode* follower = head;
         ListNode* n1 = head;
        for(int i=0;i<k-1;i++)
        {
            runner = runner->next;
           n1 = runner;
        }
        while(runner->next!=NULL)
        {
            follower = follower->next;
            runner = runner->next;
        }
        int temp;
      temp = n1->val;
      n1->val = follower->val;
      follower->val = temp;
        return head;
    }
};