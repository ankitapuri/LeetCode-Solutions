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
    int find_greater(ListNode* curr)
    {
        int ans = curr->val;
        curr=curr->next;
        while(curr!=NULL)
        {
            if(curr->val > ans)
            {
                return curr->val;
                break;
            }
            curr=curr->next;
        }
        return 0;
    }
        
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>res;
        ListNode* curr = head;
        while(curr!=NULL)
        {
            res.push_back(find_greater(curr));
            curr=curr->next;
        }
        return res;
    }
};